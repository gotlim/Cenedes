#include "pch.h"

#include "Cenedes.Stores.Exam.h"
#include "Cenedes.Stores.Helpers.h"
#include "Cenedes.Stores.Constants.h"

#include "Cenedes.Helpers.Entities.h"
#include "Cenedes.Helpers.Strings.h"

#include <sstream>

using namespace Cenedes::Stores::SQLite;

using namespace Cenedes::Helpers::Entities;
using namespace Cenedes::Helpers::Strings;
using namespace Cenedes::Helpers::Types;

namespace Cenedes::Stores
{
  ExamStore::ExamStore(const std::shared_ptr<SQLiteConnection>& connection)
    : Connection{ connection }
  {
  }

  uint64_t ExamStore::GetLastExamId()
  {
    SQLiteStatement statement(*Connection, L"Select Max(ExamId) From Exam");
    return statement.Step(), statement.GetUInt64(ColumnIndex<0>);
  }

  uint64_t ExamStore::CreateExam(const Models::Exam& exam)
  {
    Execute(*Connection,
      LR"Sql(
        Insert Into Exam (ExamId, Name, Price, CreatedDate, ModifiedDate, DeletedDate, IsEdit, IsDelete)
        Values (?, ?, ?, ?, ?, ?, ?, ?)
      )Sql", GetLastExamId() + 1, exam.Name, exam.Price,
      Models::DateTime::clock::now(), nullptr, nullptr, false, false
    );

    return Connection->RowId();
  }

  bool ExamStore::UpdateExam(const uint64_t exam_id, const Models::UpdateExam& exam)
  {
    if (not ModelHasUpdate(exam.Name, exam.Price)) { return false; }
    if (not ExistsExam(exam_id)) { return false; }

    wchar_t sql_query[256] = { L'\0' };

    swprintf_s(sql_query, L"Update Exam Set %s %s Where ExamId = ?",
      (exam.Name ? L"Name = ?," : WEmpty),
      (exam.Price ? L"Price = ?" : WEmpty)
    );

    SQLiteStatement statement(*Connection, sql_query);
    BindIfHasValue(statement, exam.Name, exam.Price, exam_id);

    statement.Execute();
    return Connection->TotalChanges() not_eq 0;
  }

  bool ExamStore::DeleteExam(const uint64_t exam_id)
  {
    Execute(*Connection, L"Delete From Exam Where ExamId = ?", exam_id);
    return Connection->TotalChanges() not_eq 0;
  }

  bool ExamStore::ExistsExam(const uint64_t exam_id)
  {
    return SQLiteStatement(*Connection, L"Select ExamId From Exam Where ExamId = ?", exam_id).Step();
  }

  template <typename Statement>
  Models::Exam MappingExam(SQLiteReader<Statement>& statement)
  {
    Models::Exam exam;
    exam.ExamId = statement.GetUInt64(ColumnIndex<0>);

    exam.Name = statement.GetWideString(ColumnIndex<1>);

    exam.Price = statement.GetDouble(ColumnIndex<2>);

    exam.CreatedDate = statement.GetDateTime<DateTime>(ColumnIndex<3>);

    exam.ModifiedDate = statement.GetType(ColumnIndex<4>) != SQLiteType::Null
      ? statement.GetDateTime<DateTime>(ColumnIndex<4>)
      : Nullable<DateTime>(std::nullopt);

    exam.DeletedDate = statement.GetType(ColumnIndex<5>) != SQLiteType::Null
      ? statement.GetDateTime<DateTime>(ColumnIndex<5>)
      : Nullable<DateTime>(std::nullopt);

    exam.IsEdit = statement.GetBoolean(ColumnIndex<6>);

    exam.IsDelete = statement.GetBoolean(ColumnIndex<7>);

    return exam;
  }

  std::optional<Models::Exam> ExamStore::Exams(const uint64_t exam_id)
  {
    SQLiteStatement statement(*Connection, L"Select * From Exam Where ExamId = ?", exam_id);

    if (statement.Step())
    {
      return MappingExam(statement);
    }

    return std::nullopt;
  }

  Helpers::Coroutines::Generator<Models::Exam> ExamStore::Exams()
  {
    for (SQLiteRow row : SQLiteStatement(*Connection, L"Select * From Exam"))
    {
      co_yield MappingExam(row);
    }
  }
}

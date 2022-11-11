#include "pch.h"

#include "Cenedes.Helpers.Entity.h"

#include "Cenedes.Stores.Exam.h"
#include "Cenedes.Stores.ColumnIndex.h"

#include <sstream>

using namespace Cenedes::Repository::ModernCpp::SQLite;
using namespace Cenedes::Helpers::Entity;
using namespace Cenedes::Helpers::Types;

namespace Cenedes::Stores
{
  ExamStore::ExamStore(const std::shared_ptr<SQLiteConnection>& connection)
    : Connection{ connection }
  {
  }

  uint64_t ExamStore::CreateExam(const Models::Exam& exam)
  {
    /* Execute(*Connection, "INSERT INTO Exam (ExamId, Name, Price, CreatedDate, ModifiedDate, DeletedDate, IsEdit, IsDelete) VALUES (?, ?, ?, ?, ?, ?, ?, ?);",
       exam.ExamId, exam.Name, exam.Price, Models::DateTime::clock::now(), nullptr, nullptr, false, false);*/

    wchar_t sql_query[1'024] = { 0 };

    int32_t sql_query_size = swprintf_s(sql_query, LR"Sql(
          INSERT INTO Exam (Name, Price, CreatedDate, ModifiedDate, DeletedDate, IsEdit, IsDelete)
          VALUES (%s, %s, %s, %s, %s, %s, %s);
        )Sql",
      SqlParameter<wchar_t>(exam.Name.c_str(), UseQuoted).c_str(),
      SqlParameter<wchar_t>(exam.Price).c_str(),
      SqlParameter<wchar_t>(Models::DateTime::clock::now().time_since_epoch().count()).c_str(),
      SqlParameter<wchar_t>(nullptr),
      SqlParameter<wchar_t>(nullptr),
      SqlParameter<wchar_t>(false).c_str(),
      SqlParameter<wchar_t>(false).c_str());

    //auto sql_query = std::format(
    //  LR"Sql(
    //    INSERT INTO Exam (Name, Price, CreatedDate, ModifiedDate, DeletedDate, IsEdit, IsDelete)
    //    VALUES ({}, {}, {}, {}, {}, {}, {});
    //  )Sql",
    //  SqlParameter<wchar_t>(exam.Name.c_str(), UseQuoted),
    //  SqlParameter<wchar_t>(exam.Price),
    //  SqlParameter<wchar_t>(Models::DateTime::clock::now().time_since_epoch().count()),
    //  SqlParameter<wchar_t>(nullptr),
    //  SqlParameter<wchar_t>(nullptr),
    //  SqlParameter<wchar_t>(false),
    //  SqlParameter<wchar_t>(false));

    Execute(*Connection, sql_query);

    return Connection->RowId();
  }

  bool ExamStore::UpdateExam(const uint64_t exam_id, const Models::Updates::Exam& exam)
  {
    if (not ExistsExam(exam_id))
    {
      return false;
    }

    std::ostringstream sql_query("Update Exam ");

    if (exam.Name)
    {
      sql_query << "Set Name =  ? ";
    }

    if (exam.Price)
    {
      sql_query << "Set Price = ? ";
    }

    sql_query << "Where ExamId = ?;";

    SQLiteStatement statement(*Connection, sql_query.str().data());

    statement.Bind(ArgumentIndex<3>, exam_id);

    if (exam.Name)
    {
      statement.Bind(ArgumentIndex<1>, exam.Name->c_str());
    }

    if (exam.Price)
    {
      statement.Bind(ArgumentIndex<2>, *exam.Price);
    }

    statement.Execute();

    return Connection->TotalChanges() > 0;
  }

  bool ExamStore::DeleteExam(const uint64_t exam_id)
  {
    Execute(*Connection, "Delete From Exam Where ExamId = ?;", exam_id);
    return Connection->TotalChanges() > 0;
  }

  bool ExamStore::ExistsExam(const uint64_t exam_id)
  {
    SQLiteStatement statement(*Connection, "Select ExamId From Exam Where ExamId = ?;", exam_id);
    statement.Execute();

    return statement.GetType(ColumnIndex<0>) != SQLiteType::Null;
  }

  template <typename Statement>
  Models::Exam MappingExam(SQLiteReader<Statement>& statement)
  {
    Models::Exam exam;
    exam.ExamId = statement.GetUInt64(ColumnIndex<0>);

    exam.Name = statement.GetWideString(ColumnIndex<1>);

    exam.Price = statement.GetType(ColumnIndex<2>) != SQLiteType::Null
      ? statement.GetDouble(ColumnIndex<2>)
      : Nullable<Double>(std::nullopt);

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
    SQLiteStatement statement(*Connection, "Select * From Exam Where ExamId = ?;", exam_id);

    try
    {
      statement.Execute();
      return MappingExam(statement);
    }
    catch (...)
    {
      return std::nullopt;
    }
  }

  std::experimental::generator<Models::Exam> ExamStore::Exams()
  {
    try
    {
      for (SQLiteRow row : SQLiteStatement(*Connection, "Select * From Exam;"))
      {
        co_yield MappingExam(row);
      }
    }
    catch (...)
    {
      co_return;
    }
  }
}

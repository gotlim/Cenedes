#include "pch.h"
#include "Cenedes.Stores.Exam.h"
#include "Cenedes.Stores.ColumnIndex.h"

#include <sstream>

using namespace Cenedes::Repository::ModernCpp::SQLite;

namespace Cenedes::Stores
{
  ExamStore::ExamStore(const std::shared_ptr<SQLiteConnection>& connection)
    : Connection{ connection }
  {
  }

  uint64_t ExamStore::CreateExam(const Models::Exam& exam)
  {
    Execute(*Connection,
      R"Sql(
        Insert Into Exam (Name, Price, CreatedDate, ModifiedDate, DeletedDate, IsEdit, IsDelete)
        Values (?, ?, ?, ?, ?, ?, ?)
      )Sql", exam.Name, exam.Price, Models::DateTime::clock::now(), nullptr, nullptr, false, false);

    return Connection->RowId();
  }

  void ExamStore::UpdateExam(const uint64_t exam_id, const Models::Updates::Exam& exam)
  {
    if (ExistsExam(exam_id))
    {
      std::ostringstream sql_query("Update Exam ");

      if (exam.Name)
      {
        sql_query << "Set Name =  ? ";
      }

      if (exam.Price)
      {
        sql_query << "Set Price = ? ";
      }

      sql_query << "Where ExamId = ?";

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
    }
  }

  void ExamStore::DeleteExam(const uint64_t exam_id)
  {
  }

  bool ExamStore::ExistsExam(const uint64_t exam_id)
  {
    SQLiteStatement statement(*Connection, "Select ExamId From Exam Where ExamId = ?", exam_id);
    statement.Execute();

    return statement.GetType(ColumnIndex<0>) != SQLiteType::Null;
  }

  std::optional<Models::Exam> ExamStore::Exams(const uint64_t exam_id)
  {
    return std::nullopt;
  }

  std::experimental::generator<Models::Exam> ExamStore::Exams()
  {
    co_return;
  }
}

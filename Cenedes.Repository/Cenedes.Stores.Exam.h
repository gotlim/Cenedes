#pragma once

#if __has_include(<generator>)
#include <generator>
#elif __has_include(<experimental/generator>)
#include <experimental/generator>
#else
#error The content of <generator> must be installed.
#endif

#include <memory>

#include <Cenedes.Models.h>
#include "Cenedes.SQLite.h"
#include "Cenedes.Stores.Exports.Api.h"

namespace Cenedes::Stores
{
  struct CENEDES_STORES_API ExamStore
  {
  public:
    ExamStore(const std::shared_ptr<SQLite::SQLiteConnection>& connection);
    uint64_t CreateExam(const Models::Exam& exam);
    bool UpdateExam(const uint64_t exam_id, const Models::Updates::Exam& exam);
    bool DeleteExam(const uint64_t exam_id);
    bool ExistsExam(const uint64_t exam_id);
    std::optional<Models::Exam> Exams(const uint64_t exam_id);
    std::experimental::generator<Models::Exam> Exams();

  private:
    std::shared_ptr<SQLite::SQLiteConnection> Connection;
  };
}

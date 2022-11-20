#pragma once

#include <memory>
#include <Cenedes.Models.Exam.h>
#include <Cenedes.Models.UpdateExam.h>
#include <Cenedes.Helpers.Generator.h>

#include "Cenedes.SQLite.h"
#include "Cenedes.Stores.Exports.Api.h"

namespace Cenedes::Stores
{
  struct CENEDES_STORES_API ExamStore
  {
  public:
    ExamStore(const std::shared_ptr<SQLite::SQLiteConnection>& connection);
    uint64_t CreateExam(const Models::Exam& exam);
    uint64_t GetLastExamId();
    bool UpdateExam(const uint64_t exam_id, const Models::UpdateExam& exam);
    bool DeleteExam(const uint64_t exam_id);
    bool ExistsExam(const uint64_t exam_id);
    std::optional<Models::Exam> Exams(const uint64_t exam_id);
    Helpers::Coroutines::Generator<Models::Exam> Exams();

  private:
    std::shared_ptr<SQLite::SQLiteConnection> Connection;
  };
}

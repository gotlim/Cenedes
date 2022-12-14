#include "pch.h"

#include <filesystem>
#include <vector>

#include <Cenedes.Helpers.Entities.h>
#include <Cenedes.Helpers.Strings.h>
#include <Cenedes.Stores.Exam.h>

using namespace Cenedes::Stores::SQLite;
using namespace Cenedes::Stores;
using namespace Cenedes::Models;

TEST(Repositories, ExamStore)
{
  char current_work_directory[MAX_PATH];
  (void)_getcwd(current_work_directory, MAX_PATH);
  std::filesystem::directory_iterator dir_iterator(current_work_directory);

  std::vector<std::wstring> dir_contents;

  std::transform(begin(dir_iterator), end(dir_iterator),
    std::back_inserter(dir_contents),
    [](const std::filesystem::directory_entry& dir_entry) -> std::wstring
    {
      return dir_entry.path().c_str();
    });

  auto file_path = std::filesystem::current_path() / "Cenedes.db";
  EXPECT_NE(std::find(dir_contents.cbegin(), dir_contents.cend(), file_path), dir_contents.cend());

  bool file_exists = std::filesystem::exists(file_path);
  EXPECT_TRUE(file_exists);

  size_t file_size = std::filesystem::file_size(file_path);
  EXPECT_NE(file_size, 0);

  EXPECT_TRUE(std::filesystem::exists(file_path));
  auto connection = std::make_shared<SQLiteConnection>(file_path.c_str());
  ExamStore exam_store(connection);

  Exam exam;
  exam.ExamId = 1;
  exam.Name = L"Examen de Sandre";
  EXPECT_NO_THROW(exam.ExamId = exam_store.CreateExam(exam));

  EXPECT_TRUE(exam_store.ExistsExam(exam.ExamId));

  UpdateExam exam_update;
  exam_update.Name = L"Examen de la Cabeza";
  exam_update.Price = 45;
  EXPECT_TRUE(exam_store.UpdateExam(exam.ExamId, exam_update));

  auto nullable_exam = exam_store.Exams(Cenedes::Helpers::Entities::DefaultId);
  EXPECT_FALSE(nullable_exam.has_value());

  nullable_exam = exam_store.Exams(exam.ExamId);
  EXPECT_TRUE(nullable_exam.has_value());
  EXPECT_EQ(*exam_update.Name, nullable_exam->Name);
  EXPECT_EQ(*exam_update.Price, Nullable<Double>(45));

  exam.Name = L"Examen de la Locura";
  exam.ExamId = 2;
  exam.Price = 100;
  EXPECT_NO_THROW(exam.ExamId = exam_store.CreateExam(exam));

  auto generator_exams = exam_store.Exams();

  SQLiteStatement statement_exam_ids(*connection, "Select ExamId From Exam");
  auto examid_it = begin(statement_exam_ids);

  for (int32_t index = 0; const auto & exam : generator_exams)
  {
    EXPECT_EQ(exam.ExamId, (examid_it->GetUInt64()));
    EXPECT_NE(exam.Name, winrt::to_hstring(Cenedes::Helpers::Strings::WEmpty));
    ++examid_it;
  }

  generator_exams = exam_store.Exams();
  std::vector<Exam> vector1_exams(generator_exams.begin(), generator_exams.end());

  exam_store.DeleteExam(exam_store.GetLastExamId());

  generator_exams = exam_store.Exams();
  std::vector<Exam> vector2_exams(generator_exams.begin(), generator_exams.end());

  EXPECT_EQ(vector1_exams.size() - 1, vector2_exams.size());
}

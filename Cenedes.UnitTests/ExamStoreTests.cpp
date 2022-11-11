#include "pch.h"

#include <filesystem>
#include <vector>

#include <Cenedes.Helpers.Entity.h>
#include <Cenedes.Helpers.String.h>
#include <Cenedes.Stores.Exam.h>

using namespace Cenedes::Repository::ModernCpp::SQLite;
using namespace Cenedes::Stores;
using namespace Cenedes::Models;

TEST(Repositories, ExamStore)
{
  /*char current_work_directory[MAX_PATH];
  (void)_getcwd(current_work_directory, MAX_PATH);
  std::filesystem::directory_iterator dir_iterator(current_work_directory);

  std::vector<std::wstring> dir_contents;

  std::transform(begin(dir_iterator), end(dir_iterator),
    std::back_inserter(dir_contents),
    [](const std::filesystem::directory_entry& dir_entry) -> std::wstring
    {
      return dir_entry.path().c_str();
    });

  auto current_path = std::filesystem::current_path();*/

  auto file_path = std::filesystem::current_path() / "Cenedes.db";
  bool file_exists = std::filesystem::exists(file_path);
  size_t file_size = std::filesystem::file_size(file_path);

  EXPECT_TRUE(std::filesystem::exists(file_path));
  auto connection = std::make_shared<SQLiteConnection>(file_path.c_str());
  ExamStore exam_store(connection);

  Exam exam;
  exam.ExamId = 1;
  exam.Name = L"Examen de Sandre";
  EXPECT_NO_THROW(exam.ExamId = exam_store.CreateExam(exam));

  EXPECT_TRUE(exam_store.ExistsExam(exam.ExamId));

  Updates::Exam exam_update;
  exam.Name = L"Examen de la Cabeza";
  exam.Price = 45;
  EXPECT_TRUE(exam_store.UpdateExam(exam.ExamId, exam_update));

  auto nullable_exam = exam_store.Exams(Cenedes::Helpers::Entity::DefaultId);
  EXPECT_FALSE(nullable_exam.has_value());

  nullable_exam = exam_store.Exams(exam.ExamId);
  EXPECT_TRUE(nullable_exam.has_value());
  EXPECT_EQ(exam.Name, nullable_exam->Name);
  EXPECT_EQ(exam.Price, Nullable<Double>(45));

  exam.Name = L"Examen de la Locura";
  exam.Price = 100;
  EXPECT_NO_THROW(exam_store.CreateExam(exam));

  for (int32_t index = 0; const auto & exam : exam_store.Exams())
  {
    EXPECT_NE(exam.Id, 0);
    EXPECT_NE(exam.Name, Cenedes::Helpers::String::Empty);
  }
}

#pragma once

#include <string>
#include <string_view>
#include <iterator>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <typeindex>
#include <typeinfo>
#include <functional>
#include <algorithm>
#include <numeric>
#include <memory>
#include <charconv>
#include <format>
#include <variant>
#include <optional>
#include <any>
#include <chrono>
#include <cstring>
#include <ctime>

#include <winsqlite/winsqlite3.h>

namespace Cenedes::Repository::SQLite
{
  class SQLiteContext
  {
  public:
    SQLiteContext() = default;
    SQLiteContext(const std::filesystem::path file_path);
    ~SQLiteContext() = default;
  private:
    std::unique_ptr<sqlite3, decltype(&sqlite3_close_v2)> m_SQLite;
  };
}

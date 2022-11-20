#pragma once

#ifdef CENEDES_HELPERS_API_EXPORTS
  #define CENEDES_HELPERS_API __declspec(dllexport)
#else
  #define CENEDES_HELPERS_API __declspec(dllimport)
#endif

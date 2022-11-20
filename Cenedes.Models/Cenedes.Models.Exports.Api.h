#pragma once

#ifdef CENEDES_MODELS_API_EXPORTS
  #define CENEDES_MODELS_API __declspec(dllexport)
#else
  #define CENEDES_MODELS_API __declspec(dllimport)
#endif

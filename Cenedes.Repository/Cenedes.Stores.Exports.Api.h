#pragma once

#ifdef CENEDES_STORES_API_EXPORTS
#define CENEDES_STORES_API __declspec(dllexport)
#else
#define CENEDES_STORES_API __declspec(dllimport)
#endif

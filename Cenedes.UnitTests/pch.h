//
// pch.h
//

#pragma once

#include "gtest/gtest.h"

#include <Windows.h>
#include <Unknwn.h>
#include <RestrictedErrorInfo.h>
#include <hstring.h>


#pragma push_macro("GetCurrentTime")
#pragma push_macro("X64")

#undef GetCurrentTime
#undef X64

#include <winrt/base.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Foundation.Collections.h>

#include <winrt/Cenedes.Application.h>
#include <winrt/Cenedes.BusinessLogic.h>
#include <winrt/Cenedes.Helpers.h>
#include <winrt/Cenedes.Models.h>
#include <winrt/Cenedes.Reports.h>
#include <winrt/Cenedes.Repository.h>
#include <winrt/Cenedes.ViewModels.h>

#pragma pop_macro("GetCurrentTime")
#pragma pop_macro("X64")

#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <ctime>
#include <chrono>
#include <charconv>
#include <format>
#include <concepts>

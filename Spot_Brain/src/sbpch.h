#pragma once

#include "Spot_Brain/Core/PlatformDetection.h"

#ifdef SB_PLATFORM_WINDOWS
	#ifndef NOMINMAX
		#define NOMINMAX
	#endif
#endif


#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Spot_Brain/Core/Base.h"

#include "Spot_Brain/Core/Log.h"

#include "Spot_Brain/Debug/Instrumentor.h"

#ifdef SB_PLATFORM_WINDOWS
	#include <Windows.h>
#endif
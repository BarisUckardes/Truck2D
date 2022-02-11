#pragma once
#include <Core/Log.h>
#include <assert.h>

#ifdef _DEBUG
#define ASSERT(condition,header,message,...) if(!condition) { LOG(header,message,__VA_ARGS__); __debugbreak();}
#else
#define ASSERT(condition,header,message,...) if(!condition) {}
#endif


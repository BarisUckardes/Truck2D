#pragma once
#include <stdio.h>

#define LOG(header,message,...) printf("[%s]: ",header); printf(message,__VA_ARGS__); printf("\n");
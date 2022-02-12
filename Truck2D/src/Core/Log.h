#pragma once
#include <stdio.h>

/*
* Simple log macro
*/

#define LOG(header,message,...) printf("[%s]: ",header); printf(message,__VA_ARGS__); printf("\n");
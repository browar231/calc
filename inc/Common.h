#ifndef COMMON_H
#define COMMON_H
#include <iostream>
#include <math.h>
#include <string>
#include <string_view>

#ifndef NDEBUG
#define DEBUG(x) std::cout << x;
#endif
#ifdef NDEBUG
#define DEBUG(x)
#endif

void *operator new(size_t size);
#endif
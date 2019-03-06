#pragma once

#ifdef DEMO_EXPORTS

#define DEMOLIB extern "C" _declspec(dllexport)

#else

#define DEMOLIB extern "C" _declspec(dllimport)

#endif

DEMOLIB int add(int a, int b);
DEMOLIB int sub(int a, int b);
DEMOLIB int mul(int a, int b);
DEMOLIB int divv(int a, int b);

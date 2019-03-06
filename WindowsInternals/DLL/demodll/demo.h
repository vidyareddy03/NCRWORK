#pragma once

#ifdef DEMODLL_EXPORTS

#define DEMOLIB extern "C" _declspec(dllexport)

#else

#define DEMOLIB extern "C" _declspec(dllimport)

#endif

DEMOLIB int add(int a, int b);
DEMOLIB int sub(int a, int b);
DEMOLIB int mul(int a, int b);
DEMOLIB int div(int a, int b);




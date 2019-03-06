#pragma once
#ifdef MYLIB_EXPORTS
#define MYLIBAPI extern 'C' __declspec(dllexport)
#else
#define MYLIBAPI extern 'C' __declspec(dllimport)
#endif // MYLIB_EXPORTS

//extern "C" __declspec(dllexport) int add(int a, int b);
MYLIBAPI int add(int nleft, int nright);
MYLIBAPI int sub(int nleft, int nright);
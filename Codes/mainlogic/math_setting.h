#ifndef MATH_SETTING_H
#define MATH_SETTING_H

#include <cmath>

typedef signed char	int8;
typedef signed short int16;
typedef signed int int32;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef float float32;
typedef double float64;

#define physqrt sqrtf
#define phyatan atan2
#define phyabs fabs
#define phymin fmin
#define phymax fmax


int ProbabilityRandom(int a, int b, float64 a_pro);
int IntRandom(int a, int b);
float64 RealRandom(float64 a, float64 b);

#endif // !MATH_SETTING_H


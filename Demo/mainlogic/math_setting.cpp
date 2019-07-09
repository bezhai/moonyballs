#include "math_setting.h"
#include <random>
#include <ctime>

int ProbabilityRandom(int a, int b, float64 a_pro)
{
    srand((unsigned)time(nullptr));
    double c = rand () /double (RAND_MAX);
    if(c >= a_pro)
        return b;
    else {
        return a;
    }
}

int IntRandom(int a, int b)
{
    srand((unsigned)time(nullptr));
    return  (rand () % (b-a+1))+ a;
}

float64 RealRandom(float64 a, float64 b)
{
    srand((unsigned)time(nullptr));
    double c = rand () /double (RAND_MAX);
    return c * (b - a) + a;
}

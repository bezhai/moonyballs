#include "math_setting.h"
#include <random>
#include <ctime>

static int i;

int ProbabilityRandom(int a, int b, float64 a_pro)
{
    srand((unsigned)time(nullptr) - i);
    srand(rand());
    i += 100;
    double c = rand () /double (RAND_MAX);
    if(c >= a_pro)
        return b;
    else {
        return a;
    }
}

int IntRandom(int a, int b)
{
    srand((unsigned)time(nullptr) - i);
    srand(rand());
     i += 100;
    return  (rand () % (b-a+1))+ a;
}

float64 RealRandom(float64 a, float64 b)
{
    srand((unsigned)time(nullptr) - i);
    srand(rand());
     i += 100;
    double c = rand () /double (RAND_MAX);
    return c * (b - a) + a;
}

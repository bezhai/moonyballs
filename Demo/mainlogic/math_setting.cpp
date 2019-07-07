#include "math_setting.h"
#include <random>
#include <ctime>

int ProbabilityRandom(int a, int b, float64 a_pro)
{
	std::default_random_engine e;
	std::bernoulli_distribution u(a_pro);
	e.seed(unsigned(time(0)));
	if (u(e) == true)
		return a;
	else
		return b;
}

int IntRandom(int a, int b)
{
	std::default_random_engine e;
	std::uniform_int_distribution<int> u(a, b);
	e.seed(unsigned(time(0)));
	return u(e);
}

float64 RealRandom(float64 a, float64 b)
{
	std::default_random_engine e;
	std::uniform_real_distribution<float64> u(a, b);
	e.seed(unsigned(time(0)));
	return u(e);
}
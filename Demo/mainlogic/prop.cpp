#include "prop.h"
#include <random>
#include <ctime>


void PropGenerate::GetcoordXY()
{
	std::default_random_engine e(time(0));
	std::uniform_real_distribution<float64> croodX(STARTX, ENDX);
	std::uniform_real_distribution<float64> croodY(ENDY, STARTY);


}
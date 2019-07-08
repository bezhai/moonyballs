#include "prop.h"
#include <random>
#include <ctime>


void PropGenerate::GetcoordXY(Prop &prop)
{
	float64 r = prop.GetRadius();
	std::default_random_engine e(time(0));
	std::uniform_real_distribution<float64> croodX(STARTX + r, ENDX - r);
	std::uniform_real_distribution<float64> croodY(ENDY + r, ENDY + per_height - r);

	prop.SetcoordX(croodX(e));
	prop.SetcoordY(croodY(e));
}

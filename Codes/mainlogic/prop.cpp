#include "prop.h"
#include <random>
#include <ctime>


void PropGenerate::GetcoordXY(Prop &prop)
{
	float64 r = prop.GetRadius();
    prop.SetcoordX(RealRandom(STARTX + r, ENDX - r));
    prop.SetcoordY(RealRandom(ENDY + r, ENDY + per_height - r));
}

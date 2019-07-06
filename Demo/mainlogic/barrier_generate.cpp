#include <random>
#include <ctime>
#include "barrier_generate.h"

//均匀分布生成通用半径
float64 Generate::GRadius()
{
	std::default_random_engine e(time(0));
	std::uniform_real_distribution<float64> u(min_radius, max_radius);
	return u(e);
}

bool Generate::JudgeBoundary(Barrier* barrier)
{
	std::vector<float64> points;
	barrier->GetPos(points);
	for (int i = 0; i < points.size() / 2; i++)
	{
		if (points[2 * i] <= STARTX || points[2 * i] >= ENDX || points[2 * i + 1] <= ENDY || points[2 * i + 1] >= STARTY)
			return true;
	}
	return false;
}

void Generate::GcoordXY(Barrier* barr, vector<Barrier*> bars)
{
	std::default_random_engine e(time(0));
	std::uniform_real_distribution<float64> croodX(STARTX, ENDX);
	std::uniform_real_distribution<float64> croodY(ENDY, STARTY);

	bool dream = false;//判断是否会重叠
	do
	{
		barr->SetX(croodX(e));
		barr->SetY(croodY(e));
		dream = false;
		for (Barrier* bar : bars)
		{
			if (barr->IsCovered(*bar))
			{
				dream = true;
				break;
			}
		}
	} while (JudgeBoundary(barr) || dream);
}

int BarrierMove::GetFloor(Barrier* barrier)
{
	return (int)(barrier->GetY() / per_height);
}
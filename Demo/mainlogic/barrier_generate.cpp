#include <random>
#include <ctime>
#include "barrier_generate.h"

//均匀分布生成通用半径
float64 Generate::GRadius()
{
	std::default_random_engine e(time(0));
	std::uniform_real_distribution<float64> u(per_height * SMALLFACTION, per_height * BIGFACTION);
	return u(e);
}


void Generate::GcoordXY(Barrier* barr, vector<Barrier*> bars)
{
	float64 r = barr->GetCalculateRadius();
	std::default_random_engine e(time(0));
	std::uniform_real_distribution<float64> croodX(STARTX + r, ENDX - r);
	std::uniform_real_distribution<float64> croodY(ENDY + r, ENDY + per_height - r);

	while (1)
	{
		barr->SetX(croodX(e));
		barr->SetY(croodY(e));
		if (bars.size() == 0)
		{
			return;
		}
		for (Barrier* bar : bars)
		{
			if (!barr->IsCovered(*bar))
				return;
		}
	}//后期需要增加错误处理
}

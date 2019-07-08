#include <random>
#include <ctime>
#include "barrier_generate.h"

//���ȷֲ�����ͨ�ð뾶
float64 Generate::GRadius()
{
	std::default_random_engine e(time(0));
	std::uniform_real_distribution<float64> u(per_height * SMALLFACTION, per_height * BIGFACTION);
	return u(e);
}


void Generate::GcoordXY(Barrier* barr, vector<Barrier*> bars)
{
	float64 r = barr->GetCalculateRadius();
	
	while (1)
	{
		barr->SetX(RealRandom(STARTX + r, ENDX - r));
		barr->SetY(RealRandom(ENDY + r, ENDY + per_height - r));
		if (bars.size() == 0)
		{
			return;
		}
		for (Barrier* bar : bars)
		{
			if (!barr->IsCovered(*bar))
				return;
		}
	}//������Ҫ���Ӵ�����
}

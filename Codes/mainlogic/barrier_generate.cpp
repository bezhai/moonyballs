#include <random>
#include <ctime>
#include "barrier_generate.h"

//均匀分布生成通用半径
float64 Generate::GRadius()
{
    std::default_random_engine e((uint32)time(nullptr));
	std::uniform_real_distribution<float64> u(per_height * SMALLFACTION, per_height * BIGFACTION);
	return u(e);
}


void Generate::GcoordY(Barrier* barr, vector<Barrier*> &bars)
{
	float64 r = barr->GetCalculateRadius();
	barr->SetY(RealRandom(ENDY + r, ENDY + per_height - r));
}

void Generate::GcoordX(vector<Barrier*> &bars)
{
    int size = (int)bars.size();
    float64 restX = (ENDX - STARTX) / (size + 1);
	for (int i = 0; i < size; i++)
	{
        bars[i]->SetX(restX * i + 80);
	}
}

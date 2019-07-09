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
	float64 restX = ENDX - STARTX;
	for (int i = 0; i < size; i++)
        restX -= 2 * bars[i]->GetCalculateRadius();
	vector<float64> listX;
	for (int i = 0; i < size; i++)
	{
        listX.push_back(RealRandom(0.0, restX));
	}
	std::sort(listX.begin(), listX.end());
	for (int i = size - 1; i > 0; i--)
		listX[i] -= listX[i - 1];
	float64 tempX = STARTX;
	for (int i = 0; i < size; i++)
	{
		tempX += bars[i]->GetCalculateRadius() + listX[i];
		bars[i]->SetX(tempX);
		tempX += bars[i]->GetCalculateRadius();
	}
}

#ifndef BARRIER_GENERATE_H
#define BARRIER_GENERATE_H

#include "barriers.h"
#include "basic_shape.h"

//���ߴ磬Ϊÿ���С��1/3
const float64 max_radius = per_height * (2 / 3);
//��С�ߴ磬Ϊÿ���С��1/4
const float64 min_radius = per_height * (2 / 5);

//�й������ϰ���������ռ�
namespace Generate
{
	//���ȷֲ�����ͨ�ð뾶
	float64 GRadius();
	//�ж��Ƿ񴥱ߣ����򷵻�true
	bool JudgeBoundary(Barrier* br);
	//���ȷֲ��������꣬�����ж��Ƿ������������������������
	void GcoordXY(Barrier* barr, vector<Barrier*> bars);
}

namespace BarrierMove
{
	int GetFloor(Barrier *barrier);//����ϰ������ڲ�
}

#endif // !BARRIER_GENERATE_H

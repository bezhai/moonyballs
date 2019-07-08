#ifndef BARRIER_GENERATE_H
#define BARRIER_GENERATE_H

#include "barriers.h"
#include "basic_shape.h"

#define SMALLFACTION 0.25
#define BIGFACTION 0.3334

//�й������ϰ���������ռ�
namespace Generate
{
	//���ȷֲ�����ͨ�ð뾶
	float64 GRadius();
	//���ȷֲ��������꣬�����ж��Ƿ������������������������
	void GcoordY(Barrier* barr, vector<Barrier*> &bars);
	void GcoordX(vector<Barrier*> &bars);
}


#endif // !BARRIER_GENERATE_H

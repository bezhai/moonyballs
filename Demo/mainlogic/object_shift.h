#ifndef OBJECT_LOGIC_H
#define OBJECT_LOGIC_H

#include "crash_control.h"
#include "barrier_generate.h"
#include "prop.h"

enum COLOR
{RED, GREEN, BLUE};

namespace MainControl
{
	void SingleBallCalc(PlayerBall &ball, Barrier** bars, Prop** circles);
	/*
	*PlayerBall:float64 x, float64 y, float64 r, float64 speed, float64 angle
	*ͨ����С������˶����ó���һ֡���꣬��Ҫget�������x��y
	*����barsΪ�洢�ϰ�������ַ������
	*�Ѿ����ɼ������ж���hp
	*/
	void BarrierMovement(Barrier**, Prop**);
	int GetColor(Barrier* bar, COLOR);
	PlayerBall PlayerGenerate();
	Barrier* BarrierGenerate(Barrier**);//����Ϊ֮ǰ���ɵ��ϰ�����������
}


#endif // !OBJECT_LOGIC_H


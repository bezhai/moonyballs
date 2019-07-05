#ifndef OBJECT_LOGIC_H
#define OBJECT_LOGIC_H

#include "crash_control.h"
#include "barrier_generate.h"
#include "prop.h"


namespace MainControl
{
	void SingleBallCalc(PlayerBall &ball, Barrier** bars, CircleBarrier* _circle, int bars_num, int _circle_num, Prop** circles, int32 prop_num);
	/*
	*PlayerBall:float64 x, float64 y, float64 r, float64 speed, float64 angle
	*ͨ����С������˶����ó���һ֡���꣬��Ҫget�������x��y
	*����barsΪ�洢�ϰ�������ַ������
	*�Ѿ����ɼ������ж���hp
	*/
	void BarrierMovement(Barrier**, int32 , CircleBarrier** ,int32 , Circle** , int32 );
	int GetRed(Barrier* bar);
	int GetGreen(Barrier* bar);
	int GetBlue(Barrier* bar);
	PlayerBall PlayerGenerate();
	Barrier* BarrierGenerate(Barrier**, int num);//����Ϊ֮ǰ���ɵ��ϰ�����������
}


#endif // !OBJECT_LOGIC_H


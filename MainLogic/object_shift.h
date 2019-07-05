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
	*通过对小球分析运动，得出下一帧坐标，需要get函数获得x和y
	*其中bars为存储障碍物对象地址的数组
	*已经集成减少所有对象hp
	*/
	void BarrierMovement(Barrier** bars, int32 bars_num, CircleBarrier** b_circle,int32 b_c_num, Circle** circles, int32 prop_num);
	int GetRed(Barrier* bar);
	int GetGreen(Barrier* bar);
	int GetBlue(Barrier* bar);
}


#endif // !OBJECT_LOGIC_H


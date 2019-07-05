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
	void BarrierMovement(Barrier**, int32 , CircleBarrier** ,int32 , Circle** , int32 );
	int GetRed(Barrier* bar);
	int GetGreen(Barrier* bar);
	int GetBlue(Barrier* bar);
	PlayerBall PlayerGenerate();
	Barrier* BarrierGenerate(Barrier**, int num);//参数为之前生成的障碍物对象的数组
}


#endif // !OBJECT_LOGIC_H


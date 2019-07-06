#ifndef OBJECT_LOGIC_H
#define OBJECT_LOGIC_H

#include "crash_control.h"
#include "barrier_generate.h"
#include "prop.h"

enum COLOR
{RED, GREEN, BLUE};

namespace MainControl
{
	void SingleBallCalc(vector<PlayerBall*>, vector<Barrier*>, vector<Prop*>);
	/*
	*PlayerBall:float64 x, float64 y, float64 r, float64 speed, float64 angle
	*通过对小球分析运动，得出下一帧坐标，需要get函数获得x和y
	*其中bars为存储障碍物对象地址的数组
	*已经集成减少所有对象hp
	*/
	void BarrierMovement(vector<Barrier*>, vector<Prop*>);
	int GetColor(Barrier*, COLOR);
	void PlayerGenerate(vector<PlayerBall*>);//生成一次小球
	void BarrierGenerate(vector<Barrier*>, int bar_num);//参数为之前生成的障碍物对象的数组
	void PropGenerate(vector<Prop*>, float64 coin_p, float64 table_p, float64 plus_p);//p代表概率

}


#endif // !OBJECT_LOGIC_H


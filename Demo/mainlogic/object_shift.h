#ifndef OBJECT_LOGIC_H
#define OBJECT_LOGIC_H

#include "crash_control.h"
#include "barrier_generate.h"
#include "prop.h"

enum COLOR
{RED, GREEN, BLUE};

namespace MainControl
{
	void BallCalc(vector<PlayerBall*>, vector<Barrier*>, vector<Prop*>);
	/*
	*PlayerBall:float64 x, float64 y, float64 r, float64 speed, float64 angle
	*通过对小球分析运动，得出下一帧坐标，需要get函数获得x和y
	*其中bars为存储障碍物对象地址的向量
	*已经集成减少所有对象hp
	*/
    void SetBeginAngle(vector<PlayerBall*>&, double angle);     // 设置起始角度
    void ItemsMovement(vector<Barrier*>, vector<Prop*>);        // 全体上一层
    int GetColor(Barrier*, COLOR);              // 获取颜色RGB值
	void PlayerGenerate(vector<PlayerBall*>&);//生成一次小球
	void BarrierGenerate(vector<Barrier*>&, int bar_num);//参数为之前生成的障碍物对象的向量，后者为生成障碍物的数量
	void PropGenerate(vector<Prop*>&, float64 coin_p, float64 table_p, float64 plus_p);//p代表概率
	bool EndJudge(vector<PlayerBall*>);//判断小球是否全部结束运动，是则返回true
	//一个函数判断是否失败和道具销毁
	//
}

#endif // !OBJECT_LOGIC_H


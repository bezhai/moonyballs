/****************************************************************************
*文件名：crash_control.h
*提供方法：
*/

#ifndef CRASH_CONTROL_H
#define CRASH_CONTROL_H

#include "basic_shape.h"

//定义障碍物的线段类
class Segment
{
private:
	float32 x1;
	float32 y1;
	float32 x2;
	float32 y2;

public:
	Segment(float32 _x1 = 0.0f, float32 _y1 = 0.0f, float32 _x2 = 0.0f, float32 _y2 = 0.0f)
	{
		x1 = _x1; x2 = _x2; y1 = _y1; y2 = _y2;
	}
	~Segment() {}
	//计算倾斜角(-pai ,pai)
	inline float32 CalcAngle()
	{
		return phyatan(y2 - y1, x2 - x1);
	}

	//计算点到线段距离
	float32 CalcDistance(BasicShape point);
};

namespace CrashJudge
{
	//判断是否碰撞线段，如果是返回线段，否则返回NULL
	bool SegmentCrash(Segment seg, PlayerBall play);
	//根据当前事件给出下一帧的坐标
	PlayerBall NextCoord(Segment seg, PlayerBall play, bool boolien);
}

#endif // !CRASH_CONTROL_H

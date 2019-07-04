/****************************************************************************
*文件名：crash_control.h
*提供方法：
*/

#ifndef CRASH_CONTROL_H
#define CRASH_CONTROL_H

#include "basic_shape.h"
#include "barriers.h"
#include <vector>

//定义障碍物的线段类
class Segment
{
private:
	float64 x1;
	float64 y1;
	float64 x2;
	float64 y2;

public:
	Segment(float64 _x1 = 0.0f, float64 _y1 = 0.0f, float64 _x2 = 0.0f, float64 _y2 = 0.0f)
	{
		x1 = _x1; x2 = _x2; y1 = _y1; y2 = _y2;
	}
	~Segment() {}
	//计算倾斜角(-pai ,pai)
	inline float64 CalcAngle()
	{
		return phyatan(y2 - y1, x2 - x1);
	}

	//计算点到线段距离
	float64 CalcDistance(BasicShape point);
};

//一些关于碰撞的命名空间
namespace CrashJudge
{
	//根据当前事件给出单个球下一帧的方向
	void SetAngle(std::vector<Segment> seg_list, PlayerBall &play);
	//判断是否碰撞线段，如果是返回true，否则返回false
	bool SegmentCrash(Segment seg, PlayerBall &play);
	//判断是否触碰边界，只要不是底边则改变方向，返回false，否则返回true
	bool BoundaryCrash(PlayerBall &play);
	//判断是否碰撞到球，并改变方向
	void BallCrash(PlayerBall &play, CircleBarrier circle);
	//角度公式需要调整障碍物向量的方向，当角度差小于pai/2时，不需要反向
	float64 AdjustAngle(float64 barri_angle, float64 ball_angle);
	//当触底时，小球的运动方程
	void BallEndMove(PlayerBall &play);
}


namespace BarrierManager
{
	//把障碍物分割为线段
	void DevideBarrier(Barrier* barrier, vector<Segment> &seg_list);
}

#endif // !CRASH_CONTROL_H

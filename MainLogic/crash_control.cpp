#include "crash_control.h"

float32 Segment::CalcDistance(BasicShape point)
{
	//计算点到线段端点的距离
	float32 d1 = GetDistance(point, BasicShape(x1, y1));
	float32 d2 = GetDistance(point, BasicShape(x2, y2));

	//如果x2-x1=0，那么执行下列选择
	if (phyabs(x2 - x1) <= INFINITE_S)
	{
		//如果垂线交点在线段外
		float32 y3 = point.GetcoordY();
		if (phymin(y1, phymin(y2, y3)) == y3 || phymax(y1, phymax(y2, y3)) == y3)
		{
			return phymin(d1, d2);
		}
		//如果垂线交点在线段内
		else
		{
			return phyabs(x1 - point.GetcoordX());
		}
	}

	//如果y2-y1=0，那么执行下列选择
	if (phyabs(y2 - y1) <= INFINITE_S)
	{
		//如果垂线交点在线段外
		float32 x3 = point.GetcoordX();
		if (phymin(x1, phymin(x2, x3)) == x3 || phymax(x1, phymax(x2, x3)) == x3)
		{
			return phymin(d1, d2);
		}
		//如果垂线交点在线段内
		else
		{
			return phyabs(y1 - point.GetcoordY());
		}
	}

	//直线方程为Ax+y+B=0，距离公式为d=|Ax0+y0+B|/sqrt(A^2+1)
	float32 A = (y2 - y1) / (x1 - x2);
	float32 B = -A * x1 - y1;//代入点(x1, y1)坐标
	//过点作直线的垂线Cx+y+D=0, C=-1/A, D=-Cx0-y0
	float32 C = -1 / A;
	float32 D = -C * point.GetcoordX() - point.GetcoordY();
	//求两条直线的交点横坐标
	float32 x3 = (B - D) / (C - A);
	//判断交点是否在线段外
	if (phymin(x1, phymin(x2, x3)) == x3 || phymax(x1, phymax(x2, x3)) == x3)
	{
		return phymin(d1, d2);
		//点在直线外，点与某端点的距离为最短距离
	}
	else
	{
		return phyabs(A * point.GetcoordX() + point.GetcoordY() + B) / physqrt(A * A + 1);
		//点在线段内， 使用点和直线的最小距离公式
	}

}

bool CrashJudge::SegmentCrash(Segment seg, PlayerBall play)
{
	//判断小球圆心和障碍物线段的距离与小球半径大小
	if (seg.CalcDistance(play) <= play.GetRadius())
		return true;
	else
		return false;
}

PlayerBall CrashJudge::NextCoord(Segment seg, PlayerBall play, bool boolien)
{
	if (boolien)
	{
		//如果碰撞到障碍物，方向改变
		float32 barri_angle = seg.CalcAngle();
		float32 ball_angle = play.GetAngle();
		//角度公式需要调整障碍物向量的方向，当角度差小于pai/2时，不需要反向
		if (phyabs(barri_angle - ball_angle) <= PAI / 2)
		{
			if (barri_angle >= 0)
				barri_angle -= PAI;
			else
				barri_angle += PAI;
		}
		play.SetAngle(2 * barri_angle - ball_angle);
	}

	play.Movement();
	return play;
}

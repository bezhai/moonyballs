#include "crash_control.h"

float64 Segment::CalcDistance(BasicShape point)
{
	//计算点到线段端点的距离
	float64 d1 = GetDistance(point, BasicShape(x1, y1));
	float64 d2 = GetDistance(point, BasicShape(x2, y2));

	//如果x2-x1=0，那么执行下列选择
	if (phyabs(x2 - x1) <= INFINITE_S)
	{
		//如果垂线交点在线段外
		float64 y3 = point.GetcoordY();
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
		float64 x3 = point.GetcoordX();
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
	float64 A = (y2 - y1) / (x1 - x2);
	float64 B = -A * x1 - y1;//代入点(x1, y1)坐标
	//过点作直线的垂线Cx+y+D=0, C=-1/A, D=-Cx0-y0
	float64 C = -1 / A;
	float64 D = -C * point.GetcoordX() - point.GetcoordY();
	//求两条直线的交点横坐标
	float64 x3 = (B - D) / (C - A);
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

bool CrashJudge::SegmentCrash(Segment seg, PlayerBall &play)
{
	//判断小球圆心和障碍物线段的距离与小球半径大小
	return seg.CalcDistance(play) <= play.GetRadius();
}

float64 CrashJudge::AdjustAngle(float64 barri_angle, float64 ball_angle)
{
	if (phyabs(barri_angle - ball_angle) <= PAI / 2)
	{
		if (barri_angle >= 0)
			barri_angle -= PAI;
		else
			barri_angle += PAI;
	}
	return barri_angle;
}

int32 CrashJudge::SetAngle(vector<Segment> seg_list, PlayerBall &play)
{
	//如果没有出界，则继续按原计划运动，否则执行终止运动
	if (CrashJudge::BoundaryCrash(play) || play.GetActive() == false)
	{
		BallEndMove(play);
		return 0;
	}
	//判断碰撞到障碍物
	for (auto &seg : seg_list)
	{
		if (CrashJudge::SegmentCrash(seg, play))
		{
			//如果碰撞到障碍物，方向改变
			float64 ball_angle = play.GetAngle();
			float64 barri_angle = AdjustAngle(seg.CalcAngle(), ball_angle);
			play.SetAngle(2 * barri_angle - ball_angle);
			if (play.GetRadius() == big_ball_radius)
			{
				return 2;//大球碰撞时减少的hp
			}
			else
			{
				return 1;//小球碰撞时减少的hp
			}
		}
	}
	return 0;
}

bool CrashJudge::BoundaryCrash(PlayerBall &play)
{
	BasicShape _start(STARTX, STARTY);
	BasicShape _end(ENDX, ENDY);
	//当小球触碰到x边界时
	if (play.GetcoordX() <= _start.GetcoordX() || play.GetcoordX() >= _end.GetcoordX())
	{
		float64 _angle = play.GetAngle();
		if (_angle >= 0)
			play.SetAngle(PAI - _angle);
		else
			play.SetAngle(-_angle - PAI);
	}
	//当小球触碰到y上边界时
	if (play.GetcoordY() >= _end.GetcoordY())
	{
		play.SetAngle(-play.GetAngle());
	}
	//当小球触碰到下边界时，返回true
	return (play.GetcoordY() <= _end.GetcoordY());
}

void CrashJudge::BallEndMove(PlayerBall &play)
{
	play.SetInactve();
	play.SetAngle(-PAI / 2);
	play.SetcoordX(ENDX / 2);
	play.SetcoordY(ENDY);
	play.SetSpeed(BASICSPEED);
}

void BarrierManager::DevideBarrier(Barrier* barrier, vector<Segment> &seg_list)
{
	vector<float64> point_list;
	barrier->GetPos(point_list);//从类提取顶点坐标信息
	int i = 0;
	for (; i < point_list.size() / 2 - 1; i++)
	{
		Segment seg_temp(point_list[2 * i], point_list[2 * i + 1], point_list[2 * i + 2], point_list[2 * i + 3]);
		seg_list.push_back(seg_temp);
	}
	Segment temp(point_list[2 * i], point_list[2 * i + 1], point_list[0], point_list[1]);
	seg_list.push_back(temp);
	point_list.clear();
}

void CrashJudge::BallCrash(PlayerBall &play, Barrier* circle)
{
	BasicShape _circle(circle->GetX(), circle->GetY());
	//如果距离小于等于半径之和，即相交
	if (GetDistance(play, _circle) <= play.GetRadius() + circle->GetCalculateRadius())
	{
		float64 tanline_angle;
		//如果球心连线平行于y轴
		if (phyabs(play.GetcoordX() - _circle.GetcoordX()) <= INFINITE_S)
		{
			tanline_angle = 0.0f;
		}
		//如果球心连线平行于x轴
		else if (phyabs(play.GetcoordY() - _circle.GetcoordY()) <= INFINITE_S)
		{
			tanline_angle = PAI / 2;
		}
		else
		{
			tanline_angle = phyatan(play.GetcoordY() - _circle.GetcoordY(), play.GetcoordX() - _circle.GetcoordX());
		}
		tanline_angle = AdjustAngle(tanline_angle, play.GetAngle());
		play.SetAngle(2 * tanline_angle - play.GetAngle());
	}
}

int CrashJudge::GetFloor(PlayerBall play)
{
	int floor = 0;//初始层数，最底层为第0层
	if (play.GetAngle() > 0)//上升时以球最低处为较下层
	{
		floor++;
		floor += (int) ((play.GetcoordY() - play.GetRadius()) / per_height);
	}
	else
	{
		floor += (int)((play.GetcoordY() + play.GetRadius()) / per_height);
	}
	return floor;
}
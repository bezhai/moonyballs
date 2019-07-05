#include "object_shift.h"

void MainControl::SingleBallCalc(PlayerBall &ball, Barrier** bars, CircleBarrier* _circle, int bars_num, int _circle_num, Prop** circles, int32 prop_num)
{
	for (int i = 0; i < bars_num; i++)
	{
		int temp = BarrierMove::GetFloor(bars[i]) - CrashJudge::GetFloor(ball);
		if (temp == 0 || temp == -1)
		{
			vector<Segment> seg_list;
			BarrierManager::DevideBarrier(bars[i], seg_list);
			bars[i]->SetHp(CrashJudge::SetAngle(seg_list, ball));//里面是判断碰撞的函数，将减少hp返回给SetHp
			seg_list.clear();
		}
	}
	for (int i = 0; i < _circle_num; i++)
	{
		CrashJudge::BallCrash(ball, _circle[i]);
	}

	if (ball.GetActive())
		ball.Movement();
	for (int i = 0; i < prop_num; i++)
	{
		if (GetDistance(ball, *circles[i]) <= ball.GetRadius() + circles[i]->GetRadius())
			circles[i]->SubHp(1);
	}
}

void MainControl::BarrierMovement(Barrier** bars, int32 bars_num, CircleBarrier** b_circle, int32 b_c_num, Circle** circles, int32 prop_num)
{
	for (int32 i = 0; i < bars_num; i++)
	{
		bars[i]->AddY(per_height);
	}

	for (int32 i = 0; i < b_c_num; i++)
	{
		b_circle[i]->AddY(per_height);
	}
	for (int32 i = 0; i < prop_num; i++)
	{
		circles[i]->AddcoordY(per_height);
	}
}

int MainControl::GetRed(Barrier* bar)
{
	int hp = bar->GetHp();
	if (hp <= 10)
	{
		return 0;
	}
	else if (hp <= 20)
	{
		return 25 * hp - 250;
	}
	else
	{
		return 250;
	}
}

int MainControl::GetGreen(Barrier* bar)
{

	int hp = bar->GetHp();
	if (hp <= 20)
	{
		return 250;
	}
	else if (hp <= 30)
	{
		return 250 - 25 * hp;
	}
	else
	{
		return 0;
	}
}

int MainControl::GetBlue(Barrier* bar)
{

	int hp = bar->GetHp();
	if (hp <= 10)
	{
		return 100 - 10 * hp;
	}
	else
	{
		return 0;
	}
}

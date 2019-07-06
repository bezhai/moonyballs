#include "object_shift.h"
#include <ctime>

void MainControl::SingleBallCalc(PlayerBall &ball, Barrier** bars, Prop** circles)
{
	for (int i = 0; i < Barrier::GetBarrierNum(); i++)
	{
		if (bars[i]->GetMode() != CIRCLE)
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
		else
		{
			CrashJudge::BallCrash(ball, bars[i]);
		}
	}

	if (ball.GetActive())
		ball.Movement();
	for (int i = 0; i < Prop::GetPropsNum(); i++)
	{
		if (GetDistance(ball, *circles[i]) <= ball.GetRadius() + circles[i]->GetRadius())
			circles[i]->SubHp(1);
	}
}

void MainControl::BarrierMovement(Barrier** bars, Prop** circles)
{
	for (int32 i = 0; i < Barrier::GetBarrierNum() ; i++)
	{
		bars[i]->AddY(per_height);
	}

	for (int32 i = 0; i < Prop::GetPropsNum(); i++)
	{
		circles[i]->AddcoordY(per_height);
	}
}

int MainControl::GetColor(Barrier* bar, COLOR color)
{
	switch (color)
	{
	case RED:
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
	case GREEN:
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
	case BLUE:
		int hp = bar->GetHp();
		if (hp <= 10)
		{
			return 100 - 10 * hp;
		}
		else
		{
			return 0;
		}
	default:
		break;
	}
}

PlayerBall MainControl::PlayerGenerate()
{
	PlayerBall ball = *new PlayerBall(ENDX / 2, STARTY, small_ball_radius, 10.0f, - PAI / 3, true);
	return ball;
}

Barrier* MainControl::BarrierGenerate(Barrier** bars)
{
	MODE mode_num = (MODE)(time(0) % 5);
	if (mode_num == CIRCLE)
	{
		CircleBarrier temp(0, 0, 0, 1);
		temp.SetRadius(Generate::GRadius());
		Generate::GcoordXY(&temp, bars, Barrier::GetBarrierNum());
		return (Barrier *)&temp;
	}
	if (mode_num == TRIANGLE)
	{
		TriangleBarrier temp(0, 0, 0, 1);
		temp.SetCalculateRadius(Generate::GRadius());
		Generate::GcoordXY(&temp, bars, Barrier::GetBarrierNum());
		return (Barrier *)&temp;
	}
	if (mode_num == PENTAGON)
	{
		PentangoBarrier temp(0, 0, 0, 1);
		temp.SetCalculateRadius(Generate::GRadius());
		Generate::GcoordXY(&temp, bars, Barrier::GetBarrierNum());
		return (Barrier *)&temp;
	}
	if (mode_num == RECTANGLE)
	{
		RectangleBarrier temp(0, 0, 10, 10, 2);
		temp.SetCalculateRadius(Generate::GRadius());
		Generate::GcoordXY(&temp, bars, Barrier::GetBarrierNum());
		return (Barrier *)&temp;
	}
}
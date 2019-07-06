#include "object_shift.h"
#include <ctime>

void MainControl::SingleBallCalc(vector<PlayerBall*> balls, vector<Barrier*> bars, vector<Prop*> props)
{
	for (PlayerBall* &ball : balls)
	{
		for (Barrier* &bar : bars)
		{
			if (bar->GetMode() != CIRCLE)
			{
				int temp = BarrierMove::GetFloor(bar) - CrashJudge::GetFloor(*ball);
				if (temp == 0 || temp == -1)
				{
					vector<Segment> seg_list;
					BarrierManager::DevideBarrier(bar, seg_list);
					bar->SetHp(CrashJudge::SetAngle(seg_list, *ball));//里面是判断碰撞的函数，将减少hp返回给SetHp
					seg_list.clear();
				}
			}
			else
			{
				CrashJudge::BallCrash(*ball, bar);
			}
		}

		if (ball->GetActive())
			ball->Movement();
		for (Prop* prop : props)
		{
			if (GetDistance(*ball, *prop) <= ball->GetRadius() + prop->GetRadius())
				prop->SubHp(1);
		}
	}
}


void MainControl::BarrierMovement(vector<Barrier*> bars, vector<Prop*> props)
{
	for (int32 i = 0; i < Barrier::GetBarrierNum() ; i++)
	{
		bars[i]->AddY(per_height);
	}

	for (int32 i = 0; i < Prop::GetPropsNum(); i++)
	{
		props[i]->AddcoordY(per_height);
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

void MainControl::PlayerGenerate(vector<PlayerBall*> balls)
{
	PlayerBall ball = *new PlayerBall(ENDX / 2, STARTY, small_ball_radius, 10.0f, - PAI / 3, true);
	balls.push_back(&ball);
}

void MainControl::BarrierGenerate(vector<Barrier*> bars, int bar_num)
{
	//生成障碍物对象
	for (int i = 0; i < bar_num; i++)
	{
		MODE mode_num = (MODE)(time(0) % 5);
		if (mode_num == CIRCLE)
		{
			CircleBarrier temp(0, 0, 0, 1);
			temp.SetRadius(Generate::GRadius());
			Generate::GcoordXY(&temp, bars);
			bars.push_back(&temp);
		}
		else if (mode_num == TRIANGLE)
		{
			TriangleBarrier temp(0, 0, 0, 1);
			temp.SetCalculateRadius(Generate::GRadius());
			Generate::GcoordXY(&temp, bars);
			bars.push_back(&temp);
		}
		else if (mode_num == PENTAGON)
		{
			PentangoBarrier temp(0, 0, 0, 1);
			temp.SetCalculateRadius(Generate::GRadius());
			Generate::GcoordXY(&temp, bars);
			bars.push_back(&temp);
		}
		else if (mode_num == RECTANGLE)
		{
			RectangleBarrier temp(0, 0, 10, 10, 2);
			temp.SetCalculateRadius(Generate::GRadius());
			Generate::GcoordXY(&temp, bars);
			bars.push_back(&temp);
		}
	}
}

void MainControl::PropGenerate(vector<Prop*>, float64 coin_p, float64 table_p, float64 plus_p)
{
	for (int i = 0; i < ProbabilityRandom(1, 0, coin_p); i++)
	{
		Coin temp(60, 10, coin_radius, 1);

	}
}
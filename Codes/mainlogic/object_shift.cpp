#include <ctime>
#include "object_shift.h"

void MainControl::BallCalc(vector<PlayerBall*> balls, vector<Barrier*> bars, vector<Prop*> props)
{
	for (PlayerBall* &ball : balls)
	{
		if (ball->GetActive() == true)
		{
			if (bars.size() != 0)
			{
				for (Barrier* &bar : bars)
				{
					if (bar->GetMode() != CIRCLE)
					{
						int temp = bar->GetFloor() - CrashJudge::GetFloor(*ball);
						if (temp == 0 || temp == -1)
						{
                            //PlayerBall temp = *ball;
                            //temp.Movement();
                            //float64 x = temp.GetcoordX() - ball->GetcoordX();
                            //float64 y = temp.GetcoordY() - ball->GetcoordY();
                            vector<Segment> seg_list;
							BarrierManager::DevideBarrier(bar, seg_list);
							bar->Damaged(CrashJudge::SetAngle(seg_list, *ball));//�������ж���ײ�ĺ�����������hp���ظ�SetHp
                            //ball->AddcoordX(x);
                            //ball->AddcoordY(y);
							seg_list.clear();
						}
					}
					else
					{
						bar->Damaged(CrashJudge::BallCrash(*ball, bar));
					}
				}
			}

			//���û�г��磬�������ԭ�ƻ��˶�������ִ����ֹ�˶�
			if (CrashJudge::BoundaryCrash(ball))
			{
				CrashJudge::BallEndMove(ball);
			}

			ball->Movement();

			if (props.size() != 0)
			{
				for (Prop* prop : props)
				{
					if (CrashJudge::GetDistance(ball, prop) <= ball->GetRadius() + prop->GetRadius())
					{
						prop->SubHp(1);
						CrashJudge::PropCrashEvent(ball, prop);
					}
				}
			}
		}
	}
}


void MainControl::ItemsMovement(vector<Barrier*> bars, vector<Prop*> props)
{
	if (bars.size() != 0)
	{
		for (Barrier* bar : bars)
		{
			bar->AddFloor();
			bar->AddY(per_height);
		}
	}
	if (props.size() != 0)
	{
		for (Prop* prop : props)
		{
			prop->AddFloor();
			prop->AddcoordY(per_height);
		}
	}
}

int MainControl::GetColor(Barrier* bar, COLOR color)
{
	int hp = bar->GetHp();
	switch (color)
	{
	case RED:
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
		if (hp <= 10)
		{
			return 100 - 10 * hp;
		}
		else
		{
			return 0;
		}
	default:
		return 0;
	}
}

void MainControl::PlayerGenerate(vector<PlayerBall*> &balls)
{
    PlayerBall* temp = new PlayerBall((ENDX + STARTX) / 2, STARTY, small_ball_radius, 40.0, -PAI / 3, true);
	balls.push_back(temp);
}

void MainControl::BarrierGenerate(vector<Barrier*> &bars, int bar_num)
{
	//�����ϰ������
	for (int i = 0; i < bar_num; i++)
	{
        MODE mode_num = (MODE)((IntRandom(0, 3) + i) % 4);
		Barrier* temp;
		if (mode_num == CIRCLE)
		{
			temp = new CircleBarrier(0, 0, 9, Generate::GRadius(), 1);
		}
		else if (mode_num == TRIANGLE)
		{
            temp = new TriangleBarrier(0, 0, 9, Generate::GRadius(), 1);
		}
		else if (mode_num == PENTAGON)
		{
			temp = new PentangoBarrier(0, 0, 9, Generate::GRadius(), 1);
		}
		else
		{
			temp = new SquareBarrier(0, 0, 9, Generate::GRadius(), 1);
		}
		temp->SetRot(RealRandom(-PAI, PAI));
		Generate::GcoordY(temp, bars);
		bars.push_back(temp);
	}
	Generate::GcoordX(bars);
}

void MainControl::PropGenerate(vector<Prop*> &props, float64 coin_p, float64 table_p, float64 plus_p)
{

	for (int i = 0; i < ProbabilityRandom(1, 0, coin_p); i++)
	{
        Prop* prop = new Coin(0, 0, coin_radius, 1);
		PropGenerate::GetcoordXY(*prop);
		props.push_back(prop);
	}
	for (int i = 0; i < ProbabilityRandom(1, 0, table_p); i++)
	{
		Prop* prop = new Turntable(0, 0, turntable_radius);
		PropGenerate::GetcoordXY(*prop);
		props.push_back(prop);
	}
	for (int i = 0; i < ProbabilityRandom(1, 0, plus_p); i++)
	{
		Prop* prop = new PlusSymbol(0, 0, plus_radius);
		PropGenerate::GetcoordXY(*prop);
		props.push_back(prop);
	}
}

void MainControl::SetBeginAngle(vector<PlayerBall*> &balls, double angle)
{
	for (PlayerBall* ball : balls)
	{
		ball->SetAngle(angle);
	}
}

bool MainControl::EndJudge(vector<PlayerBall*> balls)
{
	for (PlayerBall* ball : balls)
		if (ball->GetActive() == true)
			return false;
	return true;
}


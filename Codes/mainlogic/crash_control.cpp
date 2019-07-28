#include "crash_control.h"

float64 Segment::CalcDistance(BasicShape point)
{
    BasicShape a(x1, y1);
    BasicShape b(x2, y2);
	//����㵽�߶ζ˵�ľ���
    float64 d1 = CrashJudge::GetDistance(&point, &a);
    float64 d2 = CrashJudge::GetDistance(&point, &b);

	//���x2-x1=0����ôִ������ѡ��
	if (phyabs(x2 - x1) <= INFINITE_S)
	{
		//������߽������߶���
		float64 y3 = point.GetcoordY();
		if (phymin(y1, phymin(y2, y3)) == y3 || phymax(y1, phymax(y2, y3)) == y3)
		{
			return phymin(d1, d2);
		}
		//������߽������߶���
		else
		{
			return phyabs(x1 - point.GetcoordX());
		}
	}

	//���y2-y1=0����ôִ������ѡ��
	if (phyabs(y2 - y1) <= INFINITE_S)
	{
		//������߽������߶���
		float64 x3 = point.GetcoordX();
		if (phymin(x1, phymin(x2, x3)) == x3 || phymax(x1, phymax(x2, x3)) == x3)
		{
			return phymin(d1, d2);
		}
		//������߽������߶���
		else
		{
			return phyabs(y1 - point.GetcoordY());
		}
	}

	//ֱ�߷���ΪAx+y+B=0�����빫ʽΪd=|Ax0+y0+B|/sqrt(A^2+1)
	float64 A = (y2 - y1) / (x1 - x2);
	float64 B = -A * x1 - y1;//�����(x1, y1)����
	//������ֱ�ߵĴ���Cx+y+D=0, C=-1/A, D=-Cx0-y0
	float64 C = -1 / A;
	float64 D = -C * point.GetcoordX() - point.GetcoordY();
	//������ֱ�ߵĽ��������
	float64 x3 = (B - D) / (C - A);
	//�жϽ����Ƿ����߶���
	if (phymin(x1, phymin(x2, x3)) == x3 || phymax(x1, phymax(x2, x3)) == x3)
	{
		return phymin(d1, d2);
		//����ֱ���⣬����ĳ�˵�ľ���Ϊ��̾���
	}
	else
	{
		return phyabs(A * point.GetcoordX() + point.GetcoordY() + B) / physqrt(A * A + 1);
		//�����߶��ڣ� ʹ�õ��ֱ�ߵ���С���빫ʽ
	}

}

bool CrashJudge::SegmentCrash(Segment seg, PlayerBall &play)
{
	//�ж�С��Բ�ĺ��ϰ����߶εľ�����С��뾶��С
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
	
	//�ж���ײ���ϰ���
	for (auto &seg : seg_list)
	{
		if (CrashJudge::SegmentCrash(seg, play))
		{
			//�����ײ���ϰ������ı�
			float64 ball_angle = play.GetAngle();
			float64 barri_angle = AdjustAngle(seg.CalcAngle(), ball_angle);
			play.SetAngle(2 * barri_angle - ball_angle);
            if (phyabs(play.GetRadius() - big_ball_radius) <= INFINITE_S)
			{
                PlayerBall::AddScore(10);
				return 2;//������ײʱ���ٵ�hp
			}
			else
			{
                PlayerBall::AddScore(5);
				return 1;//С����ײʱ���ٵ�hp
			}
		}
	}
	return 0;
}

bool CrashJudge::BoundaryCrash(PlayerBall* play)
{
	float64 r = play->GetRadius();
	//��С������x�߽�ʱ
	if (play->GetcoordX() <= STARTX + r || play->GetcoordX() >= ENDX - r)
	{
		float64 _angle = play->GetAngle();
		if (_angle >= 0)
			play->SetAngle(PAI - _angle);
		else
			play->SetAngle(-_angle - PAI);
	}
	//��С������y�ϱ߽�ʱ
	if (play->GetcoordY() >= STARTY - r && play->GetAngle() >= 0)
	{
		play->SetAngle(-play->GetAngle());
	}
	//��С�������±߽�ʱ������true
    return (play->GetcoordY() <= (ENDY));
}

void CrashJudge::BallEndMove(PlayerBall* play)
{
	play->SetInactive();
	play->SetAngle(-PAI / 2);
	play->SetcoordX((ENDX + STARTX) / 2);
	play->SetcoordY(STARTY);
	play->SetSpeed(BASICSPEED);
}

void BarrierManager::DevideBarrier(Barrier* barrier, vector<Segment> &seg_list)
{
	vector<float64> point_list;
	barrier->GetPos(point_list);//������ȡ����������Ϣ
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

int CrashJudge::BallCrash(PlayerBall &play, Barrier* circle)
{
	BasicShape _circle(circle->GetX(), circle->GetY());
	//�������С�ڵ��ڰ뾶֮�ͣ����ཻ
	if (CrashJudge::GetDistance(&play, &_circle) <= play.GetRadius() + circle->GetCalculateRadius())
	{
		float64 tanline_angle;
		//�����������ƽ����y��
		if (phyabs(play.GetcoordX() - _circle.GetcoordX()) <= INFINITE_S)
		{
            tanline_angle = 0.0;
		}
		//�����������ƽ����x��
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
		if (play.GetRadius() == big_ball_radius)
		{
            PlayerBall::AddScore(10);
			return 2;//������ײʱ���ٵ�hp
		}
		else
		{
            PlayerBall::AddScore(5);
			return 1;//С����ײʱ���ٵ�hp
		}
	}
	return 0;
}

int CrashJudge::GetFloor(PlayerBall play)
{
	int floor = 0;//��ʼ��������ײ�Ϊ��0��
	if (play.GetAngle() > 0)//����ʱ������ʹ�Ϊ���²�
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

void CrashJudge::PropCrashEvent(PlayerBall* ball, Prop* prop)
{
	if (prop->GetMode() == TURNTABLE)
	{
		ball->SetRadius(big_ball_radius);
	}
	else if(prop->GetMode() == PLUSSYMBOL)
	{
		ball->SetRadius(small_ball_radius);
	}
	else
	{
        money += ((Coin *)prop)->GetMoney();
	}
}

//����������֮��ľ���
float64 CrashJudge::GetDistance(BasicShape* a, BasicShape* b)
{
	return physqrt((a->GetcoordX() - b->GetcoordX()) * (a->GetcoordX() - b->GetcoordX()) + (a->GetcoordY() - b->GetcoordY()) * (a->GetcoordY() - b->GetcoordY()));
}
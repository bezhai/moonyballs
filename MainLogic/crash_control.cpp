#include "crash_control.h"

float32 Segment::CalcDistance(BasicShape point)
{
	//����㵽�߶ζ˵�ľ���
	float32 d1 = GetDistance(point, BasicShape(x1, y1));
	float32 d2 = GetDistance(point, BasicShape(x2, y2));

	//���x2-x1=0����ôִ������ѡ��
	if (phyabs(x2 - x1) <= INFINITE_S)
	{
		//������߽������߶���
		float32 y3 = point.GetcoordY();
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
		float32 x3 = point.GetcoordX();
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
	float32 A = (y2 - y1) / (x1 - x2);
	float32 B = -A * x1 - y1;//�����(x1, y1)����
	//������ֱ�ߵĴ���Cx+y+D=0, C=-1/A, D=-Cx0-y0
	float32 C = -1 / A;
	float32 D = -C * point.GetcoordX() - point.GetcoordY();
	//������ֱ�ߵĽ��������
	float32 x3 = (B - D) / (C - A);
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

bool CrashJudge::SegmentCrash(Segment seg, PlayerBall play)
{
	//�ж�С��Բ�ĺ��ϰ����߶εľ�����С��뾶��С
	if (seg.CalcDistance(play) <= play.GetRadius())
		return true;
	else
		return false;
}

PlayerBall CrashJudge::NextCoord(Segment seg, PlayerBall play, bool boolien)
{
	if (boolien)
	{
		//�����ײ���ϰ������ı�
		float32 barri_angle = seg.CalcAngle();
		float32 ball_angle = play.GetAngle();
		//�Ƕȹ�ʽ��Ҫ�����ϰ��������ķ��򣬵��ǶȲ�С��pai/2ʱ������Ҫ����
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

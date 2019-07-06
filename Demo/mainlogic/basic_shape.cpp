#include "basic_shape.h"


void PlayerBall::Movement()
{
	double x_speed = speed * cos(angle);
	double y_speed = speed * sin(angle);

	AddcoordX(x_speed * TIME);
	AddcoordY(y_speed * TIME + 0.5 *  ACCELERATION * TIME * TIME);//����С������
	y_speed += ACCELERATION * TIME;//����С��y�᷽���ٶ�

	SetSpeed(physqrt(pow(x_speed, 2) + pow(y_speed, 2)));//�����ٶ�
	SetAngle(phyatan(y_speed, x_speed));//���½Ƕ�
}

//����������֮��ľ���
float64 GetDistance(BasicShape a, BasicShape b)
{
	return physqrt((a.coordX - b.coordX) * (a.coordX - b.coordX) + (a.coordY - b.coordY) * (a.coordY - b.coordY));
}
#include "basic_shape.h"


void PlayerBall::Movement()
{
	float64 x_speed = speed * cos(angle);
	float64 y_speed = speed * sin(angle);

	AddcoordX(x_speed * TIME);
	AddcoordY(y_speed * TIME + 0.5 *  ACCELERATION * TIME * TIME);//更新小球坐标
	y_speed += ACCELERATION * TIME;//更新小球y轴方向速度

	SetSpeed(physqrt(pow(x_speed, 2) + pow(y_speed, 2)));//更新速度
	SetAngle(phyatan(y_speed, x_speed));//更新角度
}

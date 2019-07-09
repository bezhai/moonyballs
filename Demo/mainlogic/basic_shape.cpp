#include "basic_shape.h"


void PlayerBall::Movement()
{
    float64 x_speed = speed * cos(angle);
    float64 y_speed = speed * sin(angle);

    AddcoordX(x_speed * TIME);
    AddcoordY(y_speed * TIME + 0.5 *  ACCELERATION * TIME * TIME);//???????????
    y_speed += ACCELERATION * TIME;//???????y???????

    SetSpeed(physqrt(pow(x_speed, 2) + pow(y_speed, 2)));//???????
    SetAngle(phyatan(y_speed, x_speed));//???½??
}

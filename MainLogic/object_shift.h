#ifndef OBJECT_LOGIC_H
#define OBJECT_LOGIC_H

#include "crash_control.h"

void logic(PlayerBall &ball, Barrier** bars, CircleBarrier* _circle, int bars_num, int _circle_num);
/*
*PlayerBall:float64 x, float64 y, float64 r, float64 speed, float64 angle
*ͨ����С������˶����ó���һ֡���꣬��Ҫget�������x��y
*����barsΪ�洢�ϰ�������ַ������
*/

#endif // !OBJECT_LOGIC_H


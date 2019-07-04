#ifndef OBJECT_LOGIC_H
#define OBJECT_LOGIC_H

#include "crash_control.h"

void logic(PlayerBall &ball, Barrier** bars, CircleBarrier* _circle, int bars_num, int _circle_num);
/*
*PlayerBall:float64 x, float64 y, float64 r, float64 speed, float64 angle
*通过对小球分析运动，得出下一帧坐标，需要get函数获得x和y
*其中bars为存储障碍物对象地址的数组
*/

#endif // !OBJECT_LOGIC_H


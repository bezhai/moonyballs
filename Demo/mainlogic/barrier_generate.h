#ifndef BARRIER_GENERATE_H
#define BARRIER_GENERATE_H

#include "barriers.h"
#include "basic_shape.h"

//最大尺寸，为每层大小的1/3
const float64 max_radius = per_height * (2 / 3);
//最小尺寸，为每层大小的1/4
const float64 min_radius = per_height * (2 / 5);

//有关生成障碍物的命名空间
namespace Generate
{
	//均匀分布生成通用半径
	float64 GRadius();
	//判断是否触边，是则返回true
	bool JudgeBoundary(Barrier* br);
	//均匀分布生成坐标，并且判断是否满足条件，满足条件再输出
	void GcoordXY(Barrier* barr, vector<Barrier*> bars);
}

namespace BarrierMove
{
	int GetFloor(Barrier *barrier);//获得障碍物所在层
}

#endif // !BARRIER_GENERATE_H

#ifndef BARRIER_GENERATE_H
#define BARRIER_GENERATE_H

#include "barriers.h"
#include "basic_shape.h"

#define SMALLFACTION 0.25
#define BIGFACTION 0.3334

//有关生成障碍物的命名空间
namespace Generate
{
	//均匀分布生成通用半径
	float64 GRadius();
	//均匀分布生成坐标，并且判断是否满足条件，满足条件再输出
	void GcoordY(Barrier* barr, vector<Barrier*> &bars);
	void GcoordX(vector<Barrier*> &bars);
}


#endif // !BARRIER_GENERATE_H

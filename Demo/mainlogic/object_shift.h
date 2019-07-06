#ifndef OBJECT_LOGIC_H
#define OBJECT_LOGIC_H

#include "crash_control.h"
#include "barrier_generate.h"
#include "prop.h"

enum COLOR
{RED, GREEN, BLUE};

namespace MainControl
{
	void SingleBallCalc(vector<PlayerBall*>, vector<Barrier*>, vector<Prop*>);
	/*
	*PlayerBall:float64 x, float64 y, float64 r, float64 speed, float64 angle
	*ͨ����С������˶����ó���һ֡���꣬��Ҫget�������x��y
	*����barsΪ�洢�ϰ�������ַ������
	*�Ѿ����ɼ������ж���hp
	*/
	void BarrierMovement(vector<Barrier*>, vector<Prop*>);
	int GetColor(Barrier*, COLOR);
	void PlayerGenerate(vector<PlayerBall*>);//����һ��С��
	void BarrierGenerate(vector<Barrier*>, int bar_num);//����Ϊ֮ǰ���ɵ��ϰ�����������
	void PropGenerate(vector<Prop*>, float64 coin_p, float64 table_p, float64 plus_p);//p�������

}


#endif // !OBJECT_LOGIC_H


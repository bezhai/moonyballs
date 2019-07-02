/****************************************************************************
*�ļ�����crash_control.h
*�ṩ������
*/

#ifndef CRASH_CONTROL_H
#define CRASH_CONTROL_H

#include "basic_shape.h"

//�����ϰ�����߶���
class Segment
{
private:
	float32 x1;
	float32 y1;
	float32 x2;
	float32 y2;

public:
	Segment(float32 _x1 = 0.0f, float32 _y1 = 0.0f, float32 _x2 = 0.0f, float32 _y2 = 0.0f)
	{
		x1 = _x1; x2 = _x2; y1 = _y1; y2 = _y2;
	}
	~Segment() {}
	//������б��(-pai ,pai)
	inline float32 CalcAngle()
	{
		return phyatan(y2 - y1, x2 - x1);
	}

	//����㵽�߶ξ���
	float32 CalcDistance(BasicShape point);
};

namespace CrashJudge
{
	//�ж��Ƿ���ײ�߶Σ�����Ƿ����߶Σ����򷵻�NULL
	bool SegmentCrash(Segment seg, PlayerBall play);
	//���ݵ�ǰ�¼�������һ֡������
	PlayerBall NextCoord(Segment seg, PlayerBall play, bool boolien);
}

#endif // !CRASH_CONTROL_H

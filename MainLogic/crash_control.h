/****************************************************************************
*�ļ�����crash_control.h
*�ṩ������
*/

#ifndef CRASH_CONTROL_H
#define CRASH_CONTROL_H

#include "basic_shape.h"
#include "barriers.h"
#include <vector>

//�����ϰ�����߶���
class Segment
{
private:
	float64 x1;
	float64 y1;
	float64 x2;
	float64 y2;

public:
	Segment(float64 _x1 = 0.0f, float64 _y1 = 0.0f, float64 _x2 = 0.0f, float64 _y2 = 0.0f)
	{
		x1 = _x1; x2 = _x2; y1 = _y1; y2 = _y2;
	}
	~Segment() {}
	//������б��(-pai ,pai)
	inline float64 CalcAngle()
	{
		return phyatan(y2 - y1, x2 - x1);
	}

	//����㵽�߶ξ���
	float64 CalcDistance(BasicShape point);
};

//һЩ������ײ�������ռ�
namespace CrashJudge
{
	//���ݵ�ǰ�¼�������������һ֡�ķ���
	void SetAngle(std::vector<Segment> seg_list, PlayerBall &play);
	//�ж��Ƿ���ײ�߶Σ�����Ƿ���true�����򷵻�false
	bool SegmentCrash(Segment seg, PlayerBall &play);
	//�ж��Ƿ����߽磬ֻҪ���ǵױ���ı䷽�򣬷���false�����򷵻�true
	bool BoundaryCrash(PlayerBall &play);
	//�ж��Ƿ���ײ���򣬲��ı䷽��
	void BallCrash(PlayerBall &play, CircleBarrier circle);
	//�Ƕȹ�ʽ��Ҫ�����ϰ��������ķ��򣬵��ǶȲ�С��pai/2ʱ������Ҫ����
	float64 AdjustAngle(float64 barri_angle, float64 ball_angle);
	//������ʱ��С����˶�����
	void BallEndMove(PlayerBall &play);
}


namespace BarrierManager
{
	//���ϰ���ָ�Ϊ�߶�
	void DevideBarrier(Barrier* barrier, vector<Segment> &seg_list);
}

#endif // !CRASH_CONTROL_H

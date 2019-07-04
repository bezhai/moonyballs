#include "object_shift.h"

void logic(PlayerBall &ball, Barrier** bars, CircleBarrier* _circle, int bars_num, int _circle_num)
{
	for (int i = 0; i < bars_num; i++)
	{
		vector<Segment> seg_list;
		BarrierManager::DevideBarrier(bars[i], seg_list);
		CrashJudge::SetAngle(seg_list, ball);
		seg_list.clear();
	}
	for (int i = 0; i < _circle_num; i++)
	{
		CrashJudge::BallCrash(ball, _circle[i]);
	}

	if (ball.GetActive())
		ball.Movement();
}
// barriers.h -- including barriers
// Except circle and rectangle, all shapes are regular
// Including Circle, Rectangle, Triangle, Pentagon, Hexagon
/*
	Base Class: Barrier
	Derived Class: CircleBarrier、RectangleBarrier、TriangleBarrier、PentagonBarrier、HexagonBarrier
*/
#ifndef BARRIERS_H_
#define BARRIERS_H_

#include <vector>
#include "math_setting.h"

using std::vector;

enum MODE { CIRCLE, SQUARE, TRIANGLE, PENTAGON, HEXAGON };	// The judge standard

class Barrier								// The base class of Barrier
{
public:
	Barrier(float64 set_x, float64 set_y, int32 hp, float64 radius, float64 rot);
	virtual ~Barrier();

	inline float64 GetX() { return this->x; }
	inline float64 GetY() { return this->y; }
	inline int32 GetHp() { return this->hp; }
	inline float64 GetCalculateRadius() { return this->radius; }

	inline void SetX(float64 set_x) { this->x = set_x; }
	inline void SetY(float64 set_y) { this->y = set_y; }

	inline void AddX(float64 set_x) { this->x += set_x; }
	inline void AddY(float64 set_y) { this->y += set_y; }

	inline void Damaged(int32 damage = 1) { this->hp -= damage; }
	inline void SetHp(int32 set_hp) { this->hp = set_hp; }

	bool IsCovered(Barrier &br);
	virtual void GetPos(vector<float64> &points) {}
	inline int GetMode() { return mode_num; }
	inline int GetFloor() { return floor; }
	inline void AddFloor() { floor++; }
	inline void SetRot(float64 r) { rotation = r; }
protected:
	inline void SetMode(MODE num) { mode_num = num; }
	float64 rotation;
private:
	float64 x;			// The position of centroid
	float64 y;
	int32 hp;				// The times of being delete
	float64 radius;	// The radius of circumcircle
	MODE mode_num;
	int32 floor;
};


class CircleBarrier :public Barrier			// Circle
{
public:
	CircleBarrier(float64 set_x, float64 set_y, int32 hp, float64 radius, float64 rot);
	virtual ~CircleBarrier();

 };


class SquareBarrier :public Barrier
{
public:
	SquareBarrier(float64 set_x, float64 set_y, int32 hp, float64 radius, float64 rot);
	virtual ~SquareBarrier();

	inline float64 GetRot() { return this->rotation; }
	inline void SetRot(float64 rotation) { this->rotation = rotation; }
	virtual void GetPos(vector<float64> &points);

};
class TriangleBarrier :public Barrier
{
public:
	TriangleBarrier(float64 set_x, float64 set_y, int32 hp, float64 radius, float64 rot);
	virtual ~TriangleBarrier();

	inline float64 GetRot() { return this->rotation; }
	inline void SetRot(float64 rotation) { this->rotation = rotation; }
	virtual void GetPos(vector<float64> &points);
};
class PentangoBarrier :public Barrier
{
public:
	PentangoBarrier(float64 set_x, float64 set_y, int32 hp, float64 radius, float64 rot);
	virtual ~PentangoBarrier();

	inline float64 GetRot() { return this->rotation; }
	inline void SetRot(float64 rotation) { this->rotation = rotation; }
	virtual void GetPos(vector<float64> &points);
};

#endif // !BARRIERS_H_

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

const float64 SQRT_3 = 1.732;

enum MODE { CIRCLE, RECTANGLE, TRIANGLE, PENTAGON, HEXAGON };	// The judge standard
class Barrier								// The base class of Barrier
{
public:
	Barrier(float64 set_x, float64 set_y, int32 hp = 1);
	virtual ~Barrier();

	inline float64 GetX() { return this->x; }
	inline float64 GetY() { return this->y; }
	inline int32 GetHp() { return this->hp; }
	virtual inline float64 GetCalculateRadius() { return this->calculate_radius; }

	inline void SetX(float64 set_x) { this->x = set_x; }
	inline void SetY(float64 set_y) { this->y = set_y; }

	inline void AddX(float64 set_x) { this->x += set_x; }
	inline void AddY(float64 set_y) { this->y += set_y; }

	inline void Damaged(int32 damage = 1) { this->hp -= damage; }
	inline void SetHp(int32 set_hp) { this->hp = set_hp; }

	virtual void SetCalculateRadius(float64 r) { this->calculate_radius = r; }
	bool IsCovered(Barrier &br);
	virtual void GetPos(vector<float64> &points) {}
	int GetMode() { return mode_num; }
protected:
	void SetMode(MODE num) { mode_num = num; }
private:
	float64 x;			// The position of centroid
	float64 y;
	int32 hp;				// The times of being delete
	float64 calculate_radius;	// The radius of circumcircle
	MODE mode_num;
};


class CircleBarrier :public Barrier			// Circle
{
public:
	CircleBarrier(float64 x, float64 y, float64 r, int32 hp = 1);
	virtual ~CircleBarrier();

	virtual inline float64 GetCalculateRadius() { return this->radius; }

	inline void SetRadius(float64 r) { this->radius = r; }
	virtual void SetCalculateRadius(float64 r) { Barrier::SetCalculateRadius(r); }

private:
	float64 radius;
 };


class RectangleBarrier :public Barrier
{
public:
	RectangleBarrier(float64 x, float64 y, float64 len, float64 wid, int32 hp = 1, float64 rot = 0.0);
	virtual ~RectangleBarrier();

	inline float64 GetLength() { return this->length; }
	inline float64 GetWidth() { return this->width; }
	inline float64 GetRot() { return this->rotation; }

	inline void SetLength(float64 length) { this->length = length; }
	inline void SetWidth(float64 width) { this->width = width; }
	inline void SetRot(float64 rotation) { this->rotation = rotation; }

	virtual void SetCalculateRadius(float64 r) { Barrier::SetCalculateRadius(r); }
	virtual void GetPos(vector<float64> &points);

private:
	float64 length;
	float64 width;
	float64 rotation;
};
class TriangleBarrier :public Barrier
{
public:
	TriangleBarrier(float64 x, float64 y, float64 len, int32 hp = 1, float64 rot = 0.0);
	virtual ~TriangleBarrier();

	inline float64 GetLength() { return this->length; }
	inline float64 GetRot() { return this->rotation; }

	inline void SetLength(float64 length) { this->length = length; }
	inline void SetRot(float64 rotation) { this->rotation = rotation; }

	virtual void SetCalculateRadius(float64 r) { Barrier::SetCalculateRadius(r); }
	virtual void GetPos(vector<float64> &points);

private:
	float64 length;		// The length of the triangle's side
	float64 rotation;
};
class PentangoBarrier :public Barrier
{
public:
	PentangoBarrier(float64 x, float64 y, float64 r, int32 hp = 1, float64 rot = 0.0);
	virtual ~PentangoBarrier();

	virtual inline float64 GetCalculateRadius() { return this->radius; }
	inline float64 GetRot() { return this->rotation; }
	
	inline void SetLength(float64 radius) { this->radius = radius; }
	inline void SetRot(float64 rotation) { this->rotation = rotation; }
	
	virtual void SetCalculateRadius(float64 r) { Barrier::SetCalculateRadius(r); }
	virtual void GetPos(vector<float64> &points);
private:
	float64 radius;		// The distance between centroid and a vertex
	float64 rotation;
};
class HexagonBarrier :public Barrier
{
public:
	HexagonBarrier(float64 x, float64 y, float64 r, int32 hp = 1, float64 rot = 0.0);
	virtual ~HexagonBarrier();

	virtual inline float64 GetCalculateRadius() { return this->radius; }
	inline float64 GetRot() { return this->rotation; }

	inline void SetLength(float64 radius) { this->radius = radius; }
	inline void SetRot(float64 rotation) { this->rotation = rotation; }

	virtual void SetCalculateRadius(float64 r) { Barrier::SetCalculateRadius(r); }
	virtual void GetPos(vector<float64> &points);

private:
	float64 radius;		// The distance between centroid and a vertex
	float64 rotation;
};
#endif // !BARRIERS_H_

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

using std::vector;

const double SQRT_3 = 1.732;
enum MODE { CIRCLE, RECTANGLE, TRIANGLE, PENTAGON, HEXAGON };	// The judge standard
class Barrier								// The base class of Barrier
{
public:
	Barrier(double set_x, double set_y, int hp = 1);
	virtual ~Barrier();

	inline double GetX() { return this->x; }
	inline double GetY() { return this->y; }
	inline int GetHp() { return this->hp; }
	inline double GetCalculateRadius() { return this->calculate_radius; }

	inline void SetX(double set_x) { this->x = set_x; }
	inline void SetY(double set_y) { this->y = set_y; }

	inline void Damaged(int damage = 1) { this->hp -= damage; }
	inline void SetHp(int set_hp) { this->hp = set_hp; }

	virtual void SetCalculateRadius(double r) { this->calculate_radius = r; }
	bool IsCovered(const Barrier &br);
	virtual void GetPos(vector<double> &points) {}
private:
	double x;			// The position of centroid
	double y;
	int hp;				// The times of being delete
	double calculate_radius;	// The radius of circumcircle
};
class CircleBarrier :public Barrier			// Circle
{
public:
	CircleBarrier(double x, double y, double r, int hp = 1);
	virtual ~CircleBarrier();

	inline double GetRadius() { return this->radius; }

	inline void SetRadius(double r) { this->radius = r; }
	virtual void SetCalculateRadius(double r) { Barrier::SetCalculateRadius(r); }

private:
	double radius;
 };
class RectangleBarrier :public Barrier
{
public:
	RectangleBarrier(double x, double y, double len, double wid, int hp = 1, double rot = 0.0);
	virtual ~RectangleBarrier();

	inline double GetLength() { return this->length; }
	inline double GetWidth() { return this->width; }
	inline double GetRot() { return this->rotation; }

	inline void SetLength(double length) { this->length = length; }
	inline void SetWidth(double width) { this->width = width; }
	inline void SetRot(double rotation) { this->rotation = rotation; }

	virtual void SetCalculateRadius(double r) { Barrier::SetCalculateRadius(r); }
	virtual void GetPos(vector<double> &points);

private:
	double length;
	double width;
	double rotation;
};
class TriangleBarrier :public Barrier
{
public:
	TriangleBarrier(double x, double y, double len, int hp = 1, double rot = 0.0);
	virtual ~TriangleBarrier();

	inline double GetLength() { return this->length; }
	inline double GetRot() { return this->rotation; }

	inline void SetLength(double length) { this->length = length; }
	inline void SetRot(double rotation) { this->rotation = rotation; }

	virtual void SetCalculateRadius(double r) { Barrier::SetCalculateRadius(r); }
	virtual void GetPos(vector<double> &points);

private:
	double length;		// The length of the triangle's side
	double rotation;
};
class PentangoBarrier :public Barrier
{
public:
	PentangoBarrier(double x, double y, double r, int hp = 1, double rot = 0.0);
	virtual ~PentangoBarrier();

	inline double GetRadius() { return this->radius; }
	inline double GetRot() { return this->rotation; }
	
	inline void SetLength(double radius) { this->radius = radius; }
	inline void SetRot(double rotation) { this->rotation = rotation; }
	
	virtual void SetCalculateRadius(double r) { Barrier::SetCalculateRadius(r); }
	virtual void GetPos(vector<double> &points);
private:
	double radius;		// The distance between centroid and a vertex
	double rotation;
};
class HexagonBarrier :public Barrier
{
public:
	HexagonBarrier(double x, double y, double r, int hp = 1, double rot = 0.0);
	virtual ~HexagonBarrier();

	inline double GetRadius() { return this->radius; }
	inline double GetRot() { return this->rotation; }

	inline void SetLength(double radius) { this->radius = radius; }
	inline void SetRot(double rotation) { this->rotation = rotation; }

	virtual void SetCalculateRadius(double r) { Barrier::SetCalculateRadius(r); }
	virtual void GetPos(vector<double> &points);

private:
	double radius;		// The distance between centroid and a vertex
	double rotation;
};
#endif // !BARRIERS_H_

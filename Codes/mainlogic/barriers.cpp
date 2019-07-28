// barriers.cpp -- barriers methods
#include "barriers.h"
#include <ctime>

const float64 PI = atan(1.0) * 4;

Barrier::~Barrier() {}

Barrier::Barrier(float64 set_x, float64 set_y, int32 hp, float64 radius, float64 rot)
{
	this->x = set_x;
	this->y = set_y;
	this->hp = hp;
	this->radius = radius;
	this->floor = 0;
	this->rotation = rot;
}

bool Barrier::IsCovered(Barrier &br)
{
	float64 center_distance = sqrt((this->x - br.x) * (this->x - br.x) + (this->y - br.y) * (this->y - br.y));
	float64 sum_radius = this->radius + br.radius;
	return sum_radius > center_distance;
}

CircleBarrier::CircleBarrier(float64 set_x, float64 set_y, int32 hp, float64 radius, float64 rot) :Barrier(set_x, set_y, hp, radius, rot)
{
	this->SetMode(CIRCLE);
}

CircleBarrier::~CircleBarrier() {}

SquareBarrier::SquareBarrier(float64 set_x, float64 set_y, int32 hp, float64 radius, float64 rot) : Barrier(set_x, set_y, hp, radius, rot)
{
	this->SetMode(SQUARE);
}

SquareBarrier::~SquareBarrier() {}

TriangleBarrier::TriangleBarrier(float64 set_x, float64 set_y, int32 hp, float64 radius, float64 rot) :Barrier(set_x, set_y, hp, radius, rot)
{
	this->SetMode(TRIANGLE);
}

TriangleBarrier::~TriangleBarrier() {}

PentangoBarrier::PentangoBarrier(float64 set_x, float64 set_y, int32 hp, float64 radius, float64 rot) :Barrier(set_x, set_y, hp, radius, rot)
{
	this->SetMode(PENTAGON);
}

PentangoBarrier::~PentangoBarrier() {}


void TriangleBarrier::GetPos(vector<float64> &points)
{
	float64 tempang;

	float64 x = Barrier::GetX();
	float64 y = Barrier::GetY();
	float64 r = Barrier::GetCalculateRadius();
	float64 rot = this->rotation;

	tempang = rot + PI / 2;
	points.push_back(x + r * cos(tempang));
	points.push_back(y + r * sin(tempang));
	
	tempang = rot + 7 * PI / 6;
	points.push_back(x + r * cos(tempang));
	points.push_back(y + r * sin(tempang));

	tempang = rot + 11 * PI / 6;
	points.push_back(x + r * cos(tempang));
	points.push_back(y + r * sin(tempang));

}

void SquareBarrier::GetPos(vector<float64> &points)
{
	float64 tempang;

	float64 x = Barrier::GetX();
	float64 y = Barrier::GetY();
	float64 r = Barrier::GetCalculateRadius();
	float64 rot = this->rotation;

	tempang = 1 + rot;
	points.push_back(x + r * cos(tempang));
	points.push_back(y + r * sin(tempang));
	
	tempang = PI - 1 + rot;
	points.push_back(x + r * cos(tempang));
	points.push_back(y + r * sin(tempang));

	tempang = PI + 1 + rot;
	points.push_back(x + r * cos(tempang));
	points.push_back(y + r * sin(tempang));

	tempang = 2 * PI - 1 + rot;
	points.push_back(x + r * cos(tempang));
	points.push_back(y + r * sin(tempang));
}

void PentangoBarrier::GetPos(vector<float64> &points)
{
	float64 tempang;

	float64 x = Barrier::GetX();
	float64 y = Barrier::GetY();
	float64 r = Barrier::GetCalculateRadius();
	float64 rot = this->rotation;

	tempang = PI / 10 + rot;
	points.push_back(x + r * cos(tempang));
	points.push_back(y + r * sin(tempang));

	tempang = PI / 2 + rot;
	points.push_back(x + r * cos(tempang));
	points.push_back(y + r * sin(tempang));

	tempang = 9 * PI / 10 + rot;
	points.push_back(x + r * cos(tempang));
	points.push_back(y + r * sin(tempang));

	tempang = 13 * PI / 10 + rot;
	points.push_back(x + r * cos(tempang));
	points.push_back(y + r * sin(tempang));

	tempang = 17 * PI / 10 + rot;
	points.push_back(x + r * cos(tempang));
	points.push_back(y + r * sin(tempang));
}
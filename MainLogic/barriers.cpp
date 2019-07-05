// barriers.cpp -- barriers methods
#include "barriers.h"
#include <ctime>

const float64 PI = atan(1.0) * 4;

Barrier::~Barrier() {}

Barrier::Barrier(float64 set_x, float64 set_y, int32 hp)
{
	this->x = set_x;
	this->y = set_y;
	this->hp = hp;
}

bool Barrier::IsCovered(Barrier &br)
{
	float64 center_distance = sqrt((this->x - br.x) * (this->x - br.x) + (this->y - br.y) * (this->y - br.y));
	float64 sum_radius = this->calculate_radius + br.calculate_radius;
	return sum_radius > center_distance;
}

CircleBarrier::CircleBarrier(float64 x, float64 y, float64 r, int32 hp) :Barrier(x, y, hp)
{
	this->radius = r;
	this->SetCalculateRadius(r);
}

CircleBarrier::~CircleBarrier() {}

RectangleBarrier::RectangleBarrier(float64 x, float64 y, float64 len, float64 wid, int32 hp, float64 rot) : Barrier(x, y, hp)
{
	this->length = len;
	this->width = wid;
	this->SetCalculateRadius(sqrt(pow(len, 2.0) + pow(wid, 2.0)));
}

RectangleBarrier::~RectangleBarrier() {}

TriangleBarrier::TriangleBarrier(float64 x, float64 y, float64 len, int32 hp, float64 rot) :Barrier(x, y, hp)
{
	this->length = len;
	this->rotation = rot;
	this->SetCalculateRadius(len / SQRT_3);
}

TriangleBarrier::~TriangleBarrier() {}

PentangoBarrier::PentangoBarrier(float64 x, float64 y, float64 r, int32 hp, float64 rot) :Barrier(x, y, hp)
{
	this->radius = r;
	this->rotation = rot;
	this->SetCalculateRadius(r);
}

PentangoBarrier::~PentangoBarrier() {}

HexagonBarrier::HexagonBarrier(float64 x,float64 y, float64 r,int32 hp, float64 rot) :Barrier(x, y, hp)
{
	this->radius = r;
	this->rotation = rot;
	this->SetCalculateRadius(r);
}

HexagonBarrier::~HexagonBarrier() {}

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

void RectangleBarrier::GetPos(vector<float64> &points)
{
	float64 delta = atan(this->width / this->length);
	float64 tempang;

	float64 x = Barrier::GetX();
	float64 y = Barrier::GetY();
	float64 r = Barrier::GetCalculateRadius();
	float64 rot = this->rotation;

	tempang = delta + rot;
	points.push_back(x + r * cos(tempang));
	points.push_back(y + r * sin(tempang));
	
	tempang = PI - delta + rot;
	points.push_back(x + r * cos(tempang));
	points.push_back(y + r * sin(tempang));

	tempang = PI + delta + rot;
	points.push_back(x + r * cos(tempang));
	points.push_back(y + r * sin(tempang));

	tempang = 2 * PI - delta + rot;
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

void HexagonBarrier::GetPos(vector<float64> &points)
{
	float64 tempang;

	float64 x = Barrier::GetX();
	float64 y = Barrier::GetY();
	float64 r = Barrier::GetCalculateRadius();
	float64 rot = this->rotation;

	tempang = rot;
	points.push_back(x + r * cos(tempang));
	points.push_back(y + r * sin(tempang));

	tempang = PI / 3 + rot;
	points.push_back(x + r * cos(tempang));
	points.push_back(y + r * sin(tempang));

	tempang = 2 * PI / 3 + rot;
	points.push_back(x + r * cos(tempang));
	points.push_back(y + r * sin(tempang));

	tempang = PI + rot;
	points.push_back(x + r * cos(tempang));
	points.push_back(y + r * sin(tempang));

	tempang = 4 * PI / 3 + rot;
	points.push_back(x + r * cos(tempang));
	points.push_back(y + r * sin(tempang));

	tempang = 5 * PI / 3 + rot;
	points.push_back(x + r * cos(tempang));
	points.push_back(y + r * sin(tempang));
}
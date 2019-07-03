// barriers.cpp -- barriers methods
#include "barriers.h"
#include <iostream>
#include <ctime>
#include <cmath>

const double PI = atan(1.0) * 4;

Barrier::~Barrier() {}

Barrier::Barrier(double set_x, double set_y, int hp)
{
	this->x = set_x;
	this->y = set_y;
	this->hp = hp;
}

bool Barrier::IsCovered(const Barrier &br)
{
	double center_distance = sqrt(pow((this->x - br.x), 2.0) + pow((this->y - br.y), 2.0));
	double sum_radius = this->calculate_radius + br.calculate_radius;
	return sum_radius > center_distance;
}

CircleBarrier::CircleBarrier(double x, double y, double r, int hp) :Barrier(x, y, hp)
{
	this->radius = r;
	this->SetCalculateRadius(r);
}

CircleBarrier::~CircleBarrier() {}

RectangleBarrier::RectangleBarrier(double x, double y, double len, double wid, int hp, double rot) : Barrier(x, y, hp)
{
	this->length = len;
	this->width = wid;
	this->SetCalculateRadius(sqrt(pow(len, 2.0) + pow(wid, 2.0)));
}

RectangleBarrier::~RectangleBarrier() {}

TriangleBarrier::TriangleBarrier(double x, double y, double len, int hp, double rot) :Barrier(x, y, hp)
{
	this->length = len;
	this->rotation = rot;
	this->SetCalculateRadius(len / SQRT_3);
}

TriangleBarrier::~TriangleBarrier() {}

PentangoBarrier::PentangoBarrier(double x, double y, double r, int hp, double rot) :Barrier(x, y, hp)
{
	this->radius = r;
	this->rotation = rot;
	this->SetCalculateRadius(r);
}

PentangoBarrier::~PentangoBarrier() {}

HexagonBarrier::HexagonBarrier(double x,double y, double r,int hp, double rot) :Barrier(x, y, hp)
{
	this->radius = r;
	this->rotation = rot;
	this->SetCalculateRadius(r);
}

HexagonBarrier::~HexagonBarrier() {}

void TriangleBarrier::GetPos(double points[])
{
	double tempang;

	double x = Barrier::GetX();
	double y = Barrier::GetY();
	double r = Barrier::GetCalculateRadius();
	double rot = this->rotation;

	tempang = rot + PI / 2;
	points[0] = x + r*cos(tempang);
	points[1] = y + r*sin(tempang);

	tempang = rot + 7 * PI / 6;
	points[2] = x+ r*cos(tempang);
	points[3] = y + r*sin(tempang);

	tempang = rot + 11 * PI / 6;
	points[4] = x + r*cos(tempang);
	points[5] = y + r*sin(tempang);

}

void RectangleBarrier::GetPos(double points[])
{
	double delta = atan(this->width / this->length);
	double tempang;

	double x = Barrier::GetX();
	double y = Barrier::GetY();
	double r = Barrier::GetCalculateRadius();
	double rot = this->rotation;

	tempang = delta + rot;
	points[0] = x + r * cos(tempang);
	points[1] = x + r * sin(tempang);
	
	tempang = PI - delta + rot;
	points[2] = x + r * cos(tempang);
	points[3] = y + r * sin(tempang);

	tempang = PI + delta + rot;
	points[4] = x + r * cos(tempang);
	points[5] = y + r * sin(tempang);

	tempang = 2 * PI - delta + rot;
	points[6] = x + r * cos(tempang);
	points[7] = y + r * sin(tempang);
}

void PentangoBarrier::GetPos(double points[])
{
	double tempang;

	double x = Barrier::GetX();
	double y = Barrier::GetY();
	double r = Barrier::GetCalculateRadius();
	double rot = this->rotation;

	tempang = PI / 10 + rot;
	points[0] = x + r * cos(tempang);
	points[1] = x + r * sin(tempang);

	tempang = PI / 2 + rot;
	points[2] = x + r * cos(tempang);
	points[3] = x + r * sin(tempang);

	tempang = 9 * PI / 10 + rot;
	points[4] = x + r * cos(tempang);
	points[5] = x + r * sin(tempang);

	tempang = 13 * PI / 10 + rot;
	points[6] = x + r * cos(tempang);
	points[7] = x + r * sin(tempang);

	tempang = 17 * PI / 10 + rot;
	points[8] = x + r * cos(tempang);
	points[9] = x + r * sin(tempang);
}

void HexagonBarrier::GetPos(double points[])
{
	double tempang;

	double x = Barrier::GetX();
	double y = Barrier::GetY();
	double r = Barrier::GetCalculateRadius();
	double rot = this->rotation;

	tempang = rot;
	points[0] = x + r * cos(tempang);
	points[1] = x + r * sin(tempang);

	tempang = PI / 3 + rot;
	points[2] = x + r * cos(tempang);
	points[3] = x + r * sin(tempang);

	tempang = 2 * PI / 3 + rot;
	points[4] = x + r * cos(tempang);
	points[5] = x + r * sin(tempang);

	tempang = PI + rot;
	points[6] = x + r * cos(tempang);
	points[7] = x + r * sin(tempang);

	tempang = 4 * PI / 3 + rot;
	points[8] = x + r * cos(tempang);
	points[9] = x + r * sin(tempang);

	tempang = 5 * PI / 3 + rot;
	points[10] = x + r * cos(tempang);
	points[11] = x + r * sin(tempang);
}
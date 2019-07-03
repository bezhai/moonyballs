/****************************************************************************
*�ļ�����basic_shape.h
*�ṩ������
*/

#ifndef BASIC_SHAPE_H
#define BASIC_SHAPE_H

#include "math_setting.h"

//���Ͻǣ����½�
#define STARTX   0
#define STARTY 640
#define ENDX   360
#define ENDY     0
#define BALLRADIUS 10.0f
#define BASICSPEED 10.0f

//������״������λ�ö���
class BasicShape
{
private:
	float64 coordX;
	float64 coordY;
public:
	BasicShape(float64 x = ENDX / 2, float64 y = STARTY)
	{
		coordX = x;
		coordY = y;
	}
	~BasicShape() {}
	virtual BasicShape operator + (BasicShape b)
	{
		BasicShape a;
		a.coordX = coordX + b.coordX;
		a.coordY = coordY + b.coordY;
		return a;
	}
    virtual void operator = (BasicShape b)
	{
		coordX = b.coordX;
		coordY = b.coordY;
	}
	inline void SetcoordX(float64 x)
	{
		coordX = x;
	}
	inline void SetcoordY(float64 y)
	{
		coordY = y;
	}
	inline void AddcoordX(float64 x)
	{
		coordX += x;
	}
	inline void AddcoordY(float64 y)
	{
		coordY += y;
	}
	inline float64 GetcoordX()
	{
		return coordX;
	}
	inline float64 GetcoordY()
	{
		return coordY;
	}
	//��ȡ��������
	friend float64 GetDistance(BasicShape a, BasicShape b);
};

//������Բ�������뾶
class Circle : public BasicShape
{
private:
	float64 radius;
public:
	Circle() {}
	Circle(float64 x, float64 y, float64 r = BALLRADIUS) : BasicShape(x, y)
	{
		radius = r;
	}
	~Circle() {}
	inline virtual Circle operator + (Circle b)
	{
		Circle a;
		a.SetcoordX(this->GetcoordX() + b.GetcoordX());
		a.SetcoordY(this->GetcoordY() + b.GetcoordY());
		return a;
	}
	inline virtual void operator = (Circle b)
	{
		SetcoordX(b.GetcoordX());
		SetcoordY(b.GetcoordY());
		this->radius = b.radius;
	}
	inline float64 GetRadius()
	{
		return radius;
	}
};

//��������Ҳٿص��򣬰����ٶȺͷ���
class PlayerBall : public Circle
{
public:
	PlayerBall(float64 x, float64 y, float64 r, float64 v = BASICSPEED, float64 _angle = -PAI / 2) : Circle(x, y, r)
	{
		speed = v;
		angle = _angle;
	}
	~PlayerBall() {}
	void SetSpeed(float64 v)
	{
		speed = v;
	}
	void SetAngle(float64 _angle)
	{
		angle = _angle;

	}
	inline void SetActive() { activity = true; }
	inline void SetInactve() { activity = false; }
	inline float64 GetAngle()
	{
		return angle;
	}
	inline float64 GetSpeed()
	{
		return speed;
	}
	void Movement();

private:
	float64 speed;
	float64 angle;
	bool activity;
};

float64 GetDistance(BasicShape a, BasicShape b);

#endif // !BASIC_SHAPE_H


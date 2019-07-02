/****************************************************************************
*�ļ�����basic_shape.h
*�ṩ������
*/

#ifndef BASIC_SHAPE_H
#define BASIC_SHAPE_H

#include "math_setting.h"

//������״������λ�ö���
class BasicShape
{
private:
	float32 coordX;
	float32 coordY;
public:
	BasicShape(float32 x = 0.0f, float32 y = 0.0f)
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
	inline void SetcoordX(float32 x)
	{
		coordX = x;
	}
	inline void SetcoordY(float32 y)
	{
		coordY = y;
	}
	inline void AddcoordX(float32 x)
	{
		coordX += x;
	}
	inline void AddcoordY(float32 y)
	{
		coordY += y;
	}
	inline float32 GetcoordX()
	{
		return coordX;
	}
	inline float32 GetcoordY()
	{
		return coordY;
	}
	//��ȡ��������
	friend float32 GetDistance(BasicShape a, BasicShape b);
};

//������Բ�������뾶
class Circle : public BasicShape
{
private:
	float32 radius;
public:
	Circle() {}
	Circle(float32 x, float32 y, float32 r = 0) : BasicShape(x, y)
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
	inline float32 GetRadius()
	{
		return radius;
	}
};

//��������Ҳٿص��򣬰����ٶȺͷ���
class PlayerBall : public Circle
{
public:
	PlayerBall(float32 x, float32 y, float32 r, float32 v, float32 _angle) : Circle(x, y, r)
	{
		speed = v;
		angle = _angle;
	}
	~PlayerBall() {}
	void SetSpeed(float32 v)
	{
		speed = v;
	}
	void SetAngle(float32 _angle)
	{
		angle = _angle;

	}
	inline float32 GetAngle()
	{
		return angle;
	}
	inline float32 GetSpeed()
	{
		return speed;
	}
	void Movement();

private:
	float32 speed;
	float32 angle;
	
};



#endif // !BASIC_SHAPE_H


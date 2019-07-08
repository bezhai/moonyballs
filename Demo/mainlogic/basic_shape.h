/****************************************************************************
*�ļ�����basic_shape.h
*�ṩ������
*/

#ifndef BASIC_SHAPE_H
#define BASIC_SHAPE_H

#include "math_setting.h"

//���Ͻǣ����½�
#define STARTX  40
#define STARTY 565
#define ENDX   560
#define ENDY     0

#define BASICSPEED 40.0f
#define TIME 0.1f
#define ACCELERATION -5.0f
#define INFINITE_S 0.0025f
#define PAI 3.1415926

//һ����ʮ�㣬ÿһ��ĸ߶�Ϊ1/10
const float64 per_height = (STARTY - ENDY) / 10;
const float64 big_ball_radius = 10.0f;
const float64 small_ball_radius = 6.0f;

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
    virtual void operator = (BasicShape b)
	{
		coordX = b.coordX;
		coordY = b.coordY;
	}
	inline void SetcoordX(float64 x){ coordX = x;}
	inline void SetcoordY(float64 y){ coordY = y;}
	inline void AddcoordX(float64 x){ coordX += x;}
	inline void AddcoordY(float64 y){ coordY += y;}
	inline float64 GetcoordX(){ return coordX;}
	inline float64 GetcoordY(){ return coordY;}
};

//������Բ�������뾶
class Circle : public BasicShape
{
public:
	Circle() {}
	Circle(float64 x, float64 y, float64 r) : BasicShape(x, y){ radius = r;}
	~Circle() {}
	virtual void operator = (Circle b)
	{
		SetcoordX(b.GetcoordX());
		SetcoordY(b.GetcoordY());
		this->radius = b.radius;
	}
	inline void SetRadius(float64 r) { radius = r; }
	inline float64 GetRadius(){ return radius; }
private:
	float64 radius;
};

//��������Ҳٿص��򣬰����ٶȺͷ��򣬻�Ծ״̬
class PlayerBall : public Circle
{
public:
	PlayerBall(float64 x, float64 y, float64 r, float64 v, float64 _angle, bool activity) : Circle(x, y, r)
	{
		speed = v;
		angle = _angle;
		this->activity = activity;
	}
	~PlayerBall() { }
	inline void SetSpeed(float64 v){ speed = v; }
	inline void SetAngle(float64 _angle){ angle = _angle; }
	inline void SetActive() { activity = true; }
	inline void SetInactive() { activity = false; }
	inline float64 GetAngle(){ return angle; }
	inline float64 GetSpeed()
	{
		return speed;
	}
	inline bool GetActive(){ return activity;}
	void Movement();

private:
	float64 speed;
	float64 angle;
	bool activity;
};

#endif // !BASIC_SHAPE_H


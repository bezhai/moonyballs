/****************************************************************************
*文件名：basic_shape.h
*提供方法：
*/

#ifndef BASIC_SHAPE_H
#define BASIC_SHAPE_H

#include "math_setting.h"

//左上角，右下角
#define STARTX  40
#define STARTY 560
#define ENDX   560
#define ENDY     0

#define BASICSPEED 10.0f
#define TIME 0.02f
#define ACCELERATION -5.0f
#define INFINITE_S 0.005f
#define PAI 3.1415926

//一共有十层，每一层的高度为1/10
const float64 per_height = (STARTY - ENDY) / 10;
const float64 big_ball_radius = 10.0f;
const float64 small_ball_radius = 6.0f;

//基本形状，包括位置定义
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
	inline void SetcoordX(float64 x){ coordX = x;}
	inline void SetcoordY(float64 y){ coordY = y;}
	inline void AddcoordX(float64 x){ coordX += x;}
	inline void AddcoordY(float64 y){ coordY += y;}
	inline float64 GetcoordX(){ return coordX;}
	inline float64 GetcoordY(){ return coordY;}
	//获取两点间距离
	friend float64 GetDistance(BasicShape a, BasicShape b);
};

//定义了圆，包括半径
class Circle : public BasicShape
{
public:
	Circle() {}
	Circle(float64 x, float64 y, float64 r) : BasicShape(x, y){ radius = r;}
	~Circle() {}
	virtual Circle operator + (Circle b)
	{
		Circle a;
		a.SetcoordX(this->GetcoordX() + b.GetcoordX());
		a.SetcoordY(this->GetcoordY() + b.GetcoordY());
		return a;
	}
	virtual void operator = (Circle b)
	{
		SetcoordX(b.GetcoordX());
		SetcoordY(b.GetcoordY());
		this->radius = b.radius;
	}
	inline float64 GetRadius(){ return radius;}
private:
	float64 radius;
};

//定义了玩家操控的球，包括速度和方向，活跃状态
class PlayerBall : public Circle
{
public:
	PlayerBall(float64 x, float64 y, float64 r = small_ball_radius, float64 v = BASICSPEED, float64 _angle = -PAI / 2, bool activity = true) : Circle(x, y, r)
	{
		speed = v;
		angle = _angle;
		num++;
	}
	~PlayerBall() { num--; }
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
	inline float64 GetAngle(){ return angle; }
	inline float64 GetSpeed()
	{
		return speed;
	}
	inline bool GetActive(){ return activity;}
	void Movement();
	static int GetPlayerNum() { return num; }

private:
	float64 speed;
	float64 angle;
	bool activity;
	static int num;
};

int PlayerBall::num = 0;

float64 GetDistance(BasicShape a, BasicShape b);

#endif // !BASIC_SHAPE_H


#include "basic_shape.h"

#ifndef PROP_H
#define PROP_H

const float64 coin_radius = 6.0f;
const float64 turntable_radius = 10.f;
const float64 plus_radius = 7.0f;

class Prop : public Circle
{
public:
	Prop(float64 x, float64 y, float64 r) : Circle(x, y, r) {}
	~Prop() {}
	inline void SubHp(int32 num) { hp -= num; }
protected:
	inline void SetHp(int32 num) { hp = num; }
private:
	int hp;
};

//定义了金币，包括面值
class Coin : public Prop
{
public:
	Coin(float64 x, float64 y, float64 r = coin_radius, int value = 1) : Prop(x, y, r)
	{
		coin_value = value;
		SetHp(1);
	}
	virtual ~Coin() {}
private:
	int coin_value;
};

class Turntable : public Prop
{
public:
	Turntable(float64 x, float64 y, float64 r = turntable_radius) : Prop(x, y, r)
	{
		SetHp(3);
	}
	~Turntable() {}
};

class PlusSymbol : public Prop
{
public:
	PlusSymbol(float64 x, float64 y, float64 r = plus_radius) : Prop(x, y, r)
	{
		SetHp(3);
	}
	~PlusSymbol() {}
private:
	int hp;
};

#endif // !PROP_H

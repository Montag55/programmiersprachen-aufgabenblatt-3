#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
#include <cmath>
#include "mat2.hpp"


class Circle
{
public:
	Circle();
	Circle(Vec2 const& mp, float r);
	float circumference() const;
	float area() const;
	bool is_inside(Vec2 const& p)const;

	//Getter
	Vec2 center() const;
	float radius() const;
	

	//Setter
	void center(Vec2 const& mp);
	void radius(float r);
	

private:
	Vec2 m_center;
	float m_radius;	
	
};
bool operator<(Circle const& c, Circle const& d);
bool operator>(Circle const& c, Circle const& d);
bool operator==(Circle const& c,Circle const& d);

#endif
#include "circle.hpp"
#include "vec2.hpp"
#include <cmath>
#include "mat2.hpp"



Circle::Circle():
	m_center{Vec2()},
	m_radius{3.0f} 
	{}


Circle::Circle(Vec2 const& mp, float r):
	m_center{mp},
	m_radius{r}
	{}


//Getter
Vec2 Circle::center() const {
	return m_center;
}
float Circle::radius() const {
	return m_radius;
}



//Setter
void Circle::center(Vec2 const& mp){
	m_center = mp;
}
void Circle::radius(float r){
	m_radius = r;
}



//Kreisumfang
float Circle::circumference() const{
	float r= radius();
	return(2*M_PI*r);
}

//Kreisfläche
float Circle::area() const{
	float r= radius();
	return(M_PI*r*r);
}


//is_inside
bool Circle::is_inside(Vec2 const& p)const{
	if (abst(center(), p)<=radius()){
		return true;
	}
	return false;
}


bool operator<(Circle const& c, Circle const& d){
    return c.radius()<d.radius();
}
 
bool operator>(Circle const& c, Circle const& d){
    return c.radius()>d.radius();
}
 
bool operator==(Circle const& c, Circle const& d){
    return c.radius()==d.radius();
}
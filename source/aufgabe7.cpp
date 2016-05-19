	#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include "circle.hpp"
#include "vec2.hpp"
#include "mat2.hpp"
#include <vector>

template <typename T>
void swaps(T & a, T & b){
	T c = a;
	a = b;
	b = c;
}

TEST_CASE("describe_factorial","[aufgabe3]"){
	std::vector<Circle>v(5);
	Circle a(Vec2(0.0f, 0.0f), 1.0f);
	Circle b(Vec2(0.0f, 0.0f), 2.0f);
	Circle c(Vec2(0.0f, 0.0f), 3.0f);
	Circle d(Vec2(0.0f, 0.0f), 4.0f);
	Circle e(Vec2(0.0f, 0.0f), 5.0f);
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	v.push_back(d);
	v.push_back(e);
	std::sort(std::begin(v), std::end(v));
	REQUIRE(std::is_sorted(v.begin(), v.end()));
}

TEST_CASE("describe_swap","[aufgabe8]"){
	int a = 1;
	int b = 2;
	swaps(a, b);
	REQUIRE(b == 1);
}

TEST_CASE("describe_sort", "[aufgabe9]"){
	std::vector<Circle>v(5);
	Circle a(Vec2(0.0f, 0.0f), 1.0f);
	Circle b(Vec2(0.0f, 0.0f), 6.0f);
	Circle c(Vec2(0.0f, 0.0f), 3.0f);
	Circle d(Vec2(0.0f, 0.0f), 4.0f);
	Circle e(Vec2(0.0f, 0.0f), 5.0f);
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	v.push_back(d);
	v.push_back(e);
	std::sort (v.begin(), v.end(), [](Circle a, Circle b) { return a.radius() < b.radius();});
	REQUIRE(std::is_sorted(v.begin(), v.end()));
}

int main ( int argc , char * argv []){
return Catch :: Session (). run ( argc , argv );
}


#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include "circle.hpp"
#include "vec2.hpp"
#include "mat2.hpp"
#include <cstdlib>
#include <vector>
#include <list>
#include <iostream>
#include <iterator>

template <typename b1, typename b2>
void swap(b1 & a, b2 & b){
	b1 c = a;
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
	swap(a, b);
	REQUIRE(b == 1);
}

int main ( int argc , char * argv []){
return Catch :: Session (). run ( argc , argv );
}


	#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include "circle.hpp"
#include "vec2.hpp"
#include "mat2.hpp"
#include <vector>
#include <algorithm>

template <typename T>
void swaps(T & a, T & b){
	T c = a;
	a = b;
	b = c;
}
//3.11
/*template <typename container, typename praedikat>
container filter(container const& a, praedikat const& b){
	container a1;
	for (unsigned i = 0; i < a.size(); ++i) {
		if(b(container[i])) {
			a1.push_back(container[i]);
		}
	}
	return a1;
}*/

template <typename Container, typename Praedikat>
Container filter(Container const& a, Praedikat const& b){
	Container a1;
	for (unsigned i = 0; i < a.size(); ++i) {
		if(b(a[i])) {
			a1.push_back(a[i]);
		}
	}
	return a1;
}

bool is_even(int a){
	if (a % 2 == 0)
		return true;
	return false;
}

//3.3
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
//3.8
TEST_CASE("describe_swap","[aufgabe8]"){
	int a = 1;
	int b = 2;
	swaps(a, b);
	REQUIRE(b == 1);
}
//3.9
TEST_CASE("describe_sort", "[aufgabe9]"){
	std::vector<Circle> v;
	Circle a{ Vec2(0.0f, 0.0f), 1.0f };
	Circle b{ Vec2(0.0f, 0.0f), 6.0f };
	Circle c{ Vec2(0.0f, 0.0f), 3.0f };
	Circle d{ Vec2(0.0f, 0.0f), 4.0f };
	Circle e{ Vec2(0.0f, 0.0f), 5.0f };
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	v.push_back(d);
	v.push_back(e);
	std::sort(v.begin(), v.end(), [](Circle const& a, Circle const& b){ return a.radius() < b.radius(); });
	REQUIRE(std::is_sorted(v.begin(), v.end()));
}
//3.10
TEST_CASE("describe_tranform", "[aufgabe10]"){
	std::vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::vector<int> v2{9, 8, 7, 6, 5, 4, 3, 2, 1};
	std::vector<int> v3(9);
	std::transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), [](int a, int b){return a+b;});
	REQUIRE(std::all_of(v3.begin(), v3.end(), [](int a){return a == 10;}));
}
//3.11
TEST_CASE ("describe_filter", "[aufgabe11]"){
    std::vector<int> v{1, 2, 3, 4, 5, 6};
    std::vector<int> alleven = filter(v, is_even);
	REQUIRE(std::all_of(alleven.begin(), alleven.end(), is_even));
}


int main(int argc, char* argv[]){
	return Catch::Session().run(argc, argv);
}


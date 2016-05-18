#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>

bool is_even(int a){
	if (a % 2 == 0)
		return true;
	return false;
}

bool is_odd(int a){
	if (a % 2 != 0)
		return true;
	return false;
}


TEST_CASE("describe_factorial","[aufgabe3]"){
	std::vector<int>v(100);
	for (std::vector<int>::iterator it = v.begin();
			it!=v.end(); ++it){
		*it=std::rand();
	}
	v.erase(std::remove_if(v.begin(), v.end(), is_odd), v.end());	
	REQUIRE(std::all_of(v.begin(), v.end (), is_even));
}



int main ( int argc , char * argv []){
return Catch :: Session (). run ( argc , argv );
}


#include <cstdlib>
#include <vector>
#include <list>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <set>
#include <map>

//3.2
int main(){
	std::list<int>l0(100);
	for (std::list<int>::iterator it = l0.begin();
			it!=l0.end(); ++it){
		*it=std::rand() % 100 + 0;
	}
	l0.sort();
	std::vector<int>v0(l0.size());
	std::copy(std::begin(l0), std::end(l0), std::begin(v0));
	
//3.3
	std::set<int> s0 (std::begin(l0), std::end(l0));
	std::cout<< "Mächtigkeit: "<< s0.size() << "\n";	
	std::cout<<"Zahlen nicht in Liste:"<<"\n";
	for(int i=0; i<101; i++){
			if(s0.count(i)==0)
				std::cout<< i <<"\n";
		}
//3.4
	std::map<int, int> m0;
	for (std::vector<int>::iterator i = v0.begin(); i != v0.end(); ++i){
		m0[*i]+= 1;
	}
	std::cout<<"Häufigkeit: (Zahl : Vorkommen) "<<"\n";
	for(auto i:m0){
		std::cout<< i.first << " : " << i.second <<"\n";
	}
	return 0;

}
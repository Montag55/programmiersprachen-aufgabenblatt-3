#include <cstdlib>
#include <vector>
#include <list>
#include <iostream>
#include <iterator>
#include <algorithm>

int main()
{
	std::vector <int> v0 (10);						//10 Stellen großer Vektor wird mit (immer wieder dem gleichen
													//random shit vollgemacht. v0 = vektor
	for (std::vector<int>::iterator it=v0.begin(); it!=v0.end();++it)	// it = iterator
	{
    	*it=std::rand();		// An der Stelle "it" wird eine random Zahl eingefügt.
	}
		// oder
		// for ( auto & v : v0 ) {
		// v = std :: rand ();
		// }
	std::copy(std::begin(v0), std::end(v0), 		 //kopiert den oben erstellten Vektor
	  std::ostream_iterator<int>(std::cout, "\n"));	 //und gibt diesen direkt aus.

	std::list<int>l0(v0.size());					//erstellt leere liste mit der gleichen größe des Vektors. l0 = liste

	std::copy(std::begin(v0), std::end(v0), std::begin(l0)); // kopiert Vektor komplett in Liste.

	std::list<int>l1(std::begin(l0), std::end(l0));	// konstruiert neue Liste und kopiert die Werte der 1. l1 = liste
	std::reverse(std::begin(l1), std::end(l1));		// dreht die komplette neue Liste um
	std::copy(std::begin(l1), std::end(l1), 		// kopiert die neue Liste komplett und gibt sie aus.
	  std::ostream_iterator<int>(std::cout, "\n"));

	l1.sort();										//Sortiert die Liste, wobei die kleinste Stelle in die 
													// in die erste stelle gesetzt wird.
	std::copy(l1.begin(), l1.end(), 
	  std::ostream_iterator<int>(std::cout, "\n")); //printet die neue Liste direkt.

	std::generate(std::begin(v0), std::end(v0), std::rand); //belegt v0 mit neuen random zahlen

	std::copy(v0.rbegin(), v0.rend(), 				
	  std::ostream_iterator<int>(std::cout, "\n"));	//gibt den vektor v0 neu aus, wobei der

	return 0;
}
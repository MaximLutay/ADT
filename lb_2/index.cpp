#include <iostream>
#include <cmath>
#include<cassert>

typedef unsigned long long int BIG;//BIG bit = 64;//64bit
 //typedef unsigned  long int BIG; BIG bit = 32;//32bit



#include"header.hpp"
struct ch_structurus {
	BIG *p_massivus;

	BIG n_studentus;
	BIG n_blockus_alocatedus;

	BIG n_passus;
	BIG n_failus;
};





int main() {
	BIG n_students;

	std::cout << ">Vvedite chislo 67 ili bolshe : ";


	std::cin >> n_students;

	ch_structurus  *ch1 = nullptr;
	ch_structurus *ch2 = nullptr;
	bool createdus;


	ch_structurus *ch3un = nullptr;
	ch_structurus *ch4in = nullptr;
	ch_structurus *ch5di = nullptr;
	ch_structurus *ch6sy = nullptr;



	if (n_students > 7 * pow(10, 9)) {
		std::cout << ">Too much students,bigger then people on the Earth :) \n";
		createdus = false;
	}
	else {
		ch1 = $create(n_students);							//f
		ch2 = $create(n_students);
		createdus = true;

		std::cout << "\n>ch1 65";							//f  //first=zero + n_block //last = 63 + n_block
		$pass(ch1, 65);										//f			
		$pass(ch1, 64);							//f
		$pass(ch1, 63);							//f
		$pass(ch1, 62);							//f
		$pass(ch1, 61);							//f

		std::cout << "\n>ch2 65";
		$pass(ch2, 66);							//f
		$pass(ch2, 64);							//f
		$pass(ch2, 63);							//f
		$pass(ch2, 61);							//f

		std::cout << "\n>ch3";
		ch3un = $union(ch1, ch2);							//f

		std::cout << "\n>ch4";
		ch4in = $intersection(ch1, ch2);							//f

		std::cout << "\n>ch5";
		ch5di = $difference(ch1, ch2);							//f

		std::cout << "\n>ch6";
		ch6sy = $symmetricdifference(ch1, ch2);							//f

		for (BIG f = 0;f < ch3un->n_blockus_alocatedus;f++) {
			assert(*(ch3un->p_massivus + f) == (*(ch1->p_massivus + f) | *(ch2->p_massivus + f)));
			assert(*(ch4in->p_massivus + f) == (*(ch1->p_massivus + f) & *(ch2->p_massivus + f)));
			assert(*(ch5di->p_massivus + f) == (*(ch1->p_massivus + f) & ~*(ch2->p_massivus + f)));
			assert(*(ch6sy->p_massivus + f) == (*(ch1->p_massivus + f) ^ *(ch2->p_massivus + f)));
		}







	};



	system("pause");

	if (createdus) {

		$delete(ch1); 			//f
		$delete(ch2);
		$delete(ch3un);
		$delete(ch4in);
		$delete(ch5di);
		$delete(ch6sy);

	};
	return 0;
}








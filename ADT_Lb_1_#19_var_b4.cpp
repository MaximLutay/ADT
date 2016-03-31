// ADT_Lb_19_b4.cpp: определяет точку входа для консольного приложения.
//ДАННЫЙ КОД СОДЕРЖИТ НЕОБЪЯСНИМУЮ АВТОРОМ  (V) o_O (v)

#include "stdafx.h"
#include <iostream>



void outPrint(int *address, int n_elem, char separ = '\n');





int main(){
	int n_of_curr_elem = 0;
	int i = 0;
	int k = 3;
	int* p_first_mass = new int[k];



int temp = 1;	//для запуска цикла
while (temp>0) {
		std::cin >> temp;

							*(p_first_mass + i) = temp;

n_of_curr_elem++;    /*!this line is important, don't touch!*/		i++;

				if (n_of_curr_elem == k - 1) {																//если остался один свободный
					int *p_new_mass = new int[k = k + 2];													//добавим 2 итого 3 свободных 
					memcpy(p_new_mass, p_first_mass, sizeof(int) * n_of_curr_elem);
					delete[] p_first_mass;
					p_first_mass = p_new_mass;
				};
};
	


	
	n_of_curr_elem--;

	outPrint(p_first_mass,n_of_curr_elem,'|');
	std::cout << "\n";

	system("pause");//УБРАТЬ


	int *p_start_sbmas=NULL;
	int *p_ended_sbmas = NULL;
	int hm = 3;
	
	for (int m = 0;m < n_of_curr_elem-3;m++) {																									// рекурсивные функции – моветон


		bool already = false;
		int s = m;
		int  sub_s_lenghth= 1;    //если хоть один раз выполнится цикл с while то sub_s_length = 2 тоесть в подмассиве 2 элемента


		int* u = (p_first_mass + s);int *v = (p_first_mass + s + 1);

		//test std::cout << "\n0..M = " << m << "\n";



		while ((*u > *v) && (p_ended_sbmas<= (p_first_mass+n_of_curr_elem)  ) ) {++s;  u++;  v++;	//если первый и второй удовлетворяют ++s -> удовлетворяют ли второй и третий ++s и.т.д.     в итоге sub_s_length = количество элементов подмассива 

		++sub_s_lenghth;
			 
			
			if (s >= m+2) {																			//то 											
				
				if (!already) { p_start_sbmas = (p_first_mass + m);already = true;};				// создаем начало подпоследовательности 1 раз если  есть три элемента в субмассиве //больше не создаем
				p_ended_sbmas = p_start_sbmas + sub_s_lenghth+1;									//первый элемент не входящий в подпоследовательность sub_s_length + 1 
				
			
				
			};

			

		};																							//конец while цикла
		

		if (already) { for (int h = 0;h < sub_s_lenghth ; h++) { std::cout << *(p_start_sbmas + h) << "  |  "; }; m = m + sub_s_lenghth-1;std::cout << "\n"; }; //выводим элементы и продолжаем с последнего 

		
		p_start_sbmas = NULL;													//обнуляем
		
		
																				





};													//конец for цикла







    return 0;
}											//конец main а 





// Зэ Энд









void outPrint(int *address, int n_elem,char separ) {

	for (int r = 0;r < n_elem;r++) {
		std::cout << *(address + r) <<separ;
	
	};

};











/*
| | | | | | | | | | | | | | | | ...




| | | | |                               -    N		
  | | | |	                        -    N
    | | | |  	                        +    Y
    | | | | |                           +    Y
    | | | | | |                         +    Y      <--	output this  --  
									|
    | | | | | | |                       -    N 			  ------
       	      | | | |	                -    N	
	            | | | |	        -    N
	              | | | |           +    Y
	              | | | | |         +    Y
                  | | | | | |           +    Y      <--	output this  --  
									|
                  | | | | | | |         -    N  		  ------
				    
					    .  .  .

						if N_o try another
						if Y_eah try this+1
*/

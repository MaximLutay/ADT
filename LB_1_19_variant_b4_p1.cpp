// ADT_Lb_19_b4.cpp: Ð¾Ð¿ÑÐµÐ´ÐµÐ»ÑÐµÑ ÑÐ¾ÑÐºÑ Ð²ÑÐ¾Ð´Ð° Ð´Ð»Ñ ÐºÐ¾Ð½ÑÐ¾Ð»ÑÐ½Ð¾Ð³Ð¾ Ð¿ÑÐ¸Ð»Ð¾Ð¶ÐµÐ½Ð¸Ñ.
//

#include "stdafx.h"
#include <iostream>



void outPrint(int *address, int n_elem, char separ = '\n');





int main(){
	int n_of_curr_elem = 0;
	int i = 0;
	int k = 3;
	int* p_first_mass = new int[k];



int temp = 1;	//Ð´Ð»Ñ Ð·Ð°Ð¿ÑÑÐºÐ° ÑÐ¸ÐºÐ»Ð°
while (temp>0) {
		std::cin >> temp;

							*(p_first_mass + i) = temp;

n_of_curr_elem++;    /*!this line is important, don't touch!*/		i++;

				if (n_of_curr_elem == k - 1) {																//ÐµÑÐ»Ð¸ Ð¾ÑÑÐ°Ð»ÑÑ Ð¾Ð´Ð¸Ð½ ÑÐ²Ð¾Ð±Ð¾Ð´Ð½ÑÐ¹
					int *p_new_mass = new int[k = k + 2];													//Ð´Ð¾Ð±Ð°Ð²Ð¸Ð¼ 2 Ð¸ÑÐ¾Ð³Ð¾ 3 ÑÐ²Ð¾Ð±Ð¾Ð´Ð½ÑÑ 
					memcpy(p_new_mass, p_first_mass, sizeof(int) * n_of_curr_elem);
					delete[] p_first_mass;
					p_first_mass = p_new_mass;
				};
};
	


	
	n_of_curr_elem--;

	outPrint(p_first_mass,n_of_curr_elem,'|');
	std::cout << "\n";

	system("pause");//Ð£ÐÐ ÐÐ¢Ð¬


	int *p_start_sbmas=NULL;
	int *p_ended_sbmas = NULL;
	int hm = 3;
	
	for (int m = 0;m < n_of_curr_elem-3;m++) {																									// ÑÐµÐºÑÑÑÐ¸Ð²Ð½ÑÐµ ÑÑÐ½ÐºÑÐ¸Ð¸ â Ð¼Ð¾Ð²ÐµÑÐ¾Ð½


		bool already = false;
		int s = m;
		int  sub_s_lenghth= 1;    //ÐµÑÐ»Ð¸ ÑÐ¾ÑÑ Ð¾Ð´Ð¸Ð½ ÑÐ°Ð· Ð²ÑÐ¿Ð¾Ð»Ð½Ð¸ÑÑÑ ÑÐ¸ÐºÐ» Ñ while ÑÐ¾ sub_s_length = 2 ÑÐ¾ÐµÑÑÑ Ð² Ð¿Ð¾Ð´Ð¼Ð°ÑÑÐ¸Ð²Ðµ 2 ÑÐ»ÐµÐ¼ÐµÐ½ÑÐ°


		int* u = (p_first_mass + s);int *v = (p_first_mass + s + 1);

		//test std::cout << "\n0..M = " << m << "\n";



		while ((*u > *v) && (p_ended_sbmas<= (p_first_mass+n_of_curr_elem)  ) ) {++s;  u++;  v++;	//ÐµÑÐ»Ð¸ Ð¿ÐµÑÐ²ÑÐ¹ Ð¸ Ð²ÑÐ¾ÑÐ¾Ð¹ ÑÐ´Ð¾Ð²Ð»ÐµÑÐ²Ð¾ÑÑÑÑ ++s -> ÑÐ´Ð¾Ð²Ð»ÐµÑÐ²Ð¾ÑÑÑÑ Ð»Ð¸ Ð²ÑÐ¾ÑÐ¾Ð¹ Ð¸ ÑÑÐµÑÐ¸Ð¹ ++s Ð¸.Ñ.Ð´.     Ð² Ð¸ÑÐ¾Ð³Ðµ sub_s_length = ÐºÐ¾Ð»Ð¸ÑÐµÑÑÐ²Ð¾ ÑÐ»ÐµÐ¼ÐµÐ½ÑÐ¾Ð² Ð¿Ð¾Ð´Ð¼Ð°ÑÑÐ¸Ð²Ð° 

		++sub_s_lenghth;
			 
			
			if (s >= m+2) {																			//ÑÐ¾ 											
				
				if (!already) { p_start_sbmas = (p_first_mass + m);already = true;};				// ÑÐ¾Ð·Ð´Ð°ÐµÐ¼ Ð½Ð°ÑÐ°Ð»Ð¾ Ð¿Ð¾Ð´Ð¿Ð¾ÑÐ»ÐµÐ´Ð¾Ð²Ð°ÑÐµÐ»ÑÐ½Ð¾ÑÑÐ¸ 1 ÑÐ°Ð· ÐµÑÐ»Ð¸  ÐµÑÑÑ ÑÑÐ¸ ÑÐ»ÐµÐ¼ÐµÐ½ÑÐ° Ð² ÑÑÐ±Ð¼Ð°ÑÑÐ¸Ð²Ðµ //Ð±Ð¾Ð»ÑÑÐµ Ð½Ðµ ÑÐ¾Ð·Ð´Ð°ÐµÐ¼
				p_ended_sbmas = p_start_sbmas + sub_s_lenghth+1;									//Ð¿ÐµÑÐ²ÑÐ¹ ÑÐ»ÐµÐ¼ÐµÐ½Ñ Ð½Ðµ Ð²ÑÐ¾Ð´ÑÑÐ¸Ð¹ Ð² Ð¿Ð¾Ð´Ð¿Ð¾ÑÐ»ÐµÐ´Ð¾Ð²Ð°ÑÐµÐ»ÑÐ½Ð¾ÑÑÑ sub_s_length + 1 
				
			
				
			};

			

		};																							//ÐºÐ¾Ð½ÐµÑ while ÑÐ¸ÐºÐ»Ð°
		

		if (already) { for (int h = 0;h < sub_s_lenghth ; h++) { std::cout << *(p_start_sbmas + h) << "  |  "; }; m = m + sub_s_lenghth-1;std::cout << "\n"; }; //Ð²ÑÐ²Ð¾Ð´Ð¸Ð¼ ÑÐ»ÐµÐ¼ÐµÐ½ÑÑ Ð¸ Ð¿ÑÐ¾Ð´Ð¾Ð»Ð¶Ð°ÐµÐ¼ Ñ Ð¿Ð¾ÑÐ»ÐµÐ´Ð½ÐµÐ³Ð¾ 

		
		p_start_sbmas = NULL;													//Ð¾Ð±Ð½ÑÐ»ÑÐµÐ¼
		
		
																				





};													//ÐºÐ¾Ð½ÐµÑ for ÑÐ¸ÐºÐ»Ð°







    return 0;
}											//ÐºÐ¾Ð½ÐµÑ main Ð° 





// ÐÑ Ð­Ð½Ð´









void outPrint(int *address, int n_elem,char separ) {

	for (int r = 0;r < n_elem;r++) {
		std::cout << *(address + r) <<separ;
	
	};

};











/*
| | | | | | | | | | | | | | | | ...




| | | | |	-    N		
  | | | |	-	 N
    | | | |  +    Y
    | | | | |   +  Y
    | | | | | |  +  Y			  <--	output this  --  
														|
    | | | | | | |   -       N   				  ------
       	      | | | |	 - N	
	            | | | |	 - N
	              | | | |  + Y
	              | | | | |   +  Y
                  | | | | | |  +  Y			  <--	output this  --  
														            |
                  | | | | | | |   -    N    				  ------
				    
					    .  .  .

						if N o try another
						if Y eah try this+1
*/

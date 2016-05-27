
#include "source.cpp"


#include <iostream>
#include<ctime>
#include<cassert>







int main(){
	srand(time(0));
	
	node  root(0);
	
	clock_t clock1 = clock();

	
	for(int k = 4000;k>0;k--){
		$insert(&root , k);
	};
	
	clock_t clock2 = clock();

		
	//std::cout<<$getsize(&root);
	std::cout<<"\n obr sort Dlt clk = "<<clock2 - clock1<<"\n";
	
	
	
	clock_t clock3 = clock();

	
	for(int k = 0;k<4000;k++){
		$insert(&root , k);
	};
	
	clock_t clock4 = clock();

		
	//std::cout<<$getsize(&root);
	std::cout<<"\n sort Dlt clk = "<<clock4 - clock3<<"\n";
	
	
	
	clock_t clock5 = clock();

	
	for(int k = 0;k<4000;k++){
		$insert(&root ,rand()%80000);
	};
	
	clock_t clock6 = clock();

		
	//std::cout<<$getsize(&root);
	std::cout<<"\n rand Dlt clk = "<<clock6 - clock5<<"\n";
	

	
	return 0;
};

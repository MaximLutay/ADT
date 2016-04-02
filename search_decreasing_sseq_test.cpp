#include "search_decreasing_sseq_integer_vector.hpp"


int main() {
	IntegerVector *p_desb = new IntegerVector;
	IntegerVectorInit(*p_desb);
	IntegerVectorReadTillZeroOrLess(*p_desb, std::cin);



	IntegerVectorAnalyze_and_Output(p_desb);



	
	system("pause");
	
	return 0;
};



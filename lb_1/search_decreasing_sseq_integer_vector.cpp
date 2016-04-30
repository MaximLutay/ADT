#include "search_decreasing_sseq_integer_vector.hpp"

#include <cstring>
#include <iostream>
#include <cassert>


void IntegerVectorInit(IntegerVector & _vector, int _allocatedSize)
{
	_vector.m_pData = new int[_allocatedSize];
	_vector.m_nAllocated = _allocatedSize;
	_vector.m_nUsed = 0;
}


void IntegerVectorDestroy(IntegerVector & _vector)
{
	delete[] _vector.m_pData;
}


void IntegerVectorClear(IntegerVector & _vector)
{
	_vector.m_nUsed = 0;
}


bool IntegerVectorIsEmpty(const IntegerVector & _vector)
{
	return _vector.m_nUsed == 0;
}


void IntegerVectorGrow(IntegerVector & _vector)
{
	int nAllocatedNew = _vector.m_nAllocated + 5; //âîçðàñòàíèå íà 5
	int * pNewData = new int[nAllocatedNew];

	memcpy(pNewData, _vector.m_pData, sizeof(int) * _vector.m_nAllocated);

	delete[] _vector.m_pData;
	_vector.m_pData = pNewData;

	_vector.m_nAllocated = nAllocatedNew;
}


void IntegerVectorPushBack(IntegerVector & _vector, int _data)
{
	if (_vector.m_nUsed == _vector.m_nAllocated)
		IntegerVectorGrow(_vector);

	_vector.m_pData[_vector.m_nUsed++] = _data;
}



void IntegerVectorPopBack(IntegerVector & _vector)
{
	assert(!IntegerVectorIsEmpty(_vector));

	--_vector.m_nUsed;
}


void IntegerVectorRead(IntegerVector & _vector, std::istream & _stream)
{
	while (true)
	{
		int temp;
		_stream >> temp;
		if (_stream)
			IntegerVectorPushBack(_vector, temp);
		else
			break;
	}
}


void IntegerVectorReadTillZeroOrLess(IntegerVector & _vector, std::istream & _stream)
{
	while (true)
	{
		int temp;
		_stream >> temp;
		if (_stream && temp > 0)
			IntegerVectorPushBack(_vector, temp);
		else
			break;
	}
}


void IntegerVectorPrint(const IntegerVector & _vector, std::ostream & _stream, char _sep)
{
	for (int i = 0; i < _vector.m_nUsed; i++)
		_stream << _vector.m_pData[i] << _sep;
}


void IntegerVectorInsertAt(IntegerVector & _vector, int _position, int _data)
{
	assert(_position >= 0 && _position < _vector.m_nUsed);

	int newUsed = _vector.m_nUsed + 1;
	if (newUsed > _vector.m_nAllocated)
		IntegerVectorGrow(_vector);

	for (int i = _vector.m_nUsed; i > _position; i--)
		_vector.m_pData[i] = _vector.m_pData[i - 1];

	_vector.m_pData[_position] = _data;

	_vector.m_nUsed = newUsed;
}


void IntegerVectorDeleteAt(IntegerVector & _vector, int _position)
{
	assert(_position >= 0 && _position < _vector.m_nUsed);

	for (int i = _position + 1; i < _vector.m_nUsed; i++)
		_vector.m_pData[i - 1] = _vector.m_pData[i];

	--_vector.m_nUsed;
}


void IntegerVectorAnalyze_and_Output(IntegerVector *_vector){
	int *u = nullptr;
	int *v = nullptr;
	int n_subelements;
	int *start_sub = nullptr;

	bool created = false;

	for (int m = 0;m < (_vector->m_nUsed);m++) {
		u = _vector->m_pData + m;
		v = _vector->m_pData + m + 1;
		n_subelements = 1;


		while (   *u > *v   ) {
			n_subelements++;
			u++;
			v++;

			if (!created) { 
				start_sub = _vector->m_pData + m;
			};
		};//endwhile


		--n_subelements;// !important


		if (n_subelements > 0 ) {
			if (_vector->m_pData + m + n_subelements >= _vector->m_pData + _vector->m_nUsed ) {  //ïðîâåðêà íà âûâîä òîëüêî â ïðåäåëàõ
				for (int r = 0;r < n_subelements;r++) {
					std::cout << *(start_sub + r) << "  ";
				};
			}else {
				for (int r = 0;r <= n_subelements;r++) {
					std::cout << *(start_sub + r) << "  ";
				};
			};

			std::cout << "\n";

		};
		m += n_subelements;


	};//endfor




};

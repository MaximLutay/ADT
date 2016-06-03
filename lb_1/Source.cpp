#include <iostream>
#include<memory.h>

struct IntegerDeque
{
	//  оличество €чеек в массиве-директории
	int m_directorySize;

	//  оличество €чеек в каждом блоке данных
	int m_blockSize;

	// ћассив-директори€: указатели на блоки данных
	int ** m_pDirectory;

	// »ндексы верхней и нижней позиции из зан€тых €чеек в директории
	int m_frontBlockIndex, m_backBlockIndex;

	//  оличество зан€тых элементов в первом и последнем блоках
	int m_frontUsed, m_backUsed;
};

int main() {



};



IntegerDeque * createIntDeq(int _m_block_size) {
	IntegerDeque *temp = new IntegerDeque;

	temp->m_directorySize = 0;
	temp->m_blockSize = _m_block_size;
	temp->m_frontUsed = temp->m_backUsed = 0;
	temp->m_frontBlockIndex = temp->m_backBlockIndex = 0;
	temp->m_pDirectory = new int*[1];
	temp->m_pDirectory[0] = new int[temp->m_blockSize];

	return temp;
};

void directoryGrowTop(IntegerDeque * _deq) {
	int **temp = new int*[_deq->m_directorySize+1];
	for (int k = 0;k < _deq->m_directorySize;k++) {
		*(temp + 1 + k) = new int[_deq->m_blockSize];
		memcpy(  *(temp + 1 + k), *(_deq->m_pDirectory + k), _deq->m_blockSize*sizeof(int)  );
	};
	directoryDelete(_deq);
	_deq->m_pDirectory = temp;
	_deq->m_directorySize++;
};

void directoryGrowBottom(IntegerDeque * _deq) {
	int **temp = new int*[_deq->m_directorySize + 1];
	for (int k = 0;k < _deq->m_directorySize;k++) {
		*(temp + k) = new int[_deq->m_blockSize];
		memcpy(*(temp + 1 + k), *(_deq->m_pDirectory + k), _deq->m_blockSize*sizeof(int));
	};
	directoryDelete(_deq);
	_deq->m_pDirectory = temp;
	_deq->m_directorySize++;
};

void directoryDelete(IntegerDeque * _deq) {
	for (int i = 0;i < _deq->m_directorySize;i++) {
		delete[] *(_deq->m_pDirectory + i);
	};
	delete[] _deq->m_pDirectory;
};


void push_front(IntegerDeque *_deq,int _value) {
	if (_deq->m_frontUsed == _deq->m_blockSize) {
		directoryGrowTop(_deq);
		_deq->m_frontUsed = 1;
		_deq->m_pDirectory[0][_deq->m_blockSize - _deq->m_frontUsed] = _value;
	}else {
		_deq->m_pDirectory[0][_deq->m_blockSize - _deq->m_frontUsed - 1] = _value;
		_deq->m_frontUsed++;
	};
};

void push_back(IntegerDeque *_deq, int _value) {
	if (_deq->m_backUsed == _deq->m_blockSize) {
		directoryGrowBottom(_deq);
		_deq->m_backUsed = 1;
		_deq->m_pDirectory[_deq->m_backBlockIndex][_deq->m_backUsed-1] = _value;
	}else {
		_deq->m_pDirectory[_deq->m_backBlockIndex][_deq->m_backUsed - 1] = _value;
		_deq->m_backUsed++;
	};
};



void directoryDecreaseTop(IntegerDeque *_deq){
	int **temp = new int*[_deq->m_directorySize - 1];
	for (int k = 0;k < _deq->m_directorySize-1;k++) {
		*(temp + k) = new int[_deq->m_blockSize];
		memcpy(*(temp + k), *(_deq->m_pDirectory + 1+k), _deq->m_blockSize*sizeof(int));
	};
	directoryDelete(_deq);
	_deq->m_pDirectory = temp;
};
void directoryDecreaseBottom(IntegerDeque *_deq){
	int **temp = new int*[_deq->m_directorySize - 1];
	for (int k = 0;k < _deq->m_directorySize - 1;k++) {
		*(temp + k) = new int[_deq->m_blockSize];
		memcpy(*(temp + k), *(_deq->m_pDirectory + k), _deq->m_blockSize*sizeof(int));
	};
	directoryDelete(_deq);
	_deq->m_pDirectory = temp;
};






int pop_front(IntegerDeque *_deq) {
	if (_deq->m_frontUsed == 1) {
		directoryDecreaseTop;
		_deq->m_frontUsed = _deq->m_blockSize;
	}else {
		int *temp = new int[_deq->m_blockSize];
		
	};
};

int pop_back() {
};




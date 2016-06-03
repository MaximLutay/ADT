#include <iostream>
#include<memory.h>

struct IntegerDeque
{
	// Êîëè÷åñòâî ÿ÷ååê â ìàññèâå-äèðåêòîðèè
	int m_directorySize;

	// Êîëè÷åñòâî ÿ÷ååê â êàæäîì áëîêå äàííûõ
	int m_blockSize;

	// Ìàññèâ-äèðåêòîðèÿ: óêàçàòåëè íà áëîêè äàííûõ
	int ** m_pDirectory;

	// Èíäåêñû âåðõíåé è íèæíåé ïîçèöèè èç çàíÿòûõ ÿ÷ååê â äèðåêòîðèè
	int m_frontBlockIndex, m_backBlockIndex;

	// Êîëè÷åñòâî çàíÿòûõ ýëåìåíòîâ â ïåðâîì è ïîñëåäíåì áëîêàõ
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
		int temoint = _deq->m_pDirectory[0][0];
		directoryDecreaseTop(_deq);
		_deq->m_frontUsed = _deq->m_blockSize;
		return temoint;
	}else {
		int *temp = new int[_deq->m_blockSize];
		memcpy((temp + _deq->m_blockSize - _deq->m_frontUsed), (*(_deq->m_pDirectory + 0) + _deq->m_blockSize - _deq->m_frontUsed), sizeof(int)*(_deq->m_frontUsed - 1));
		_deq->m_frontUsed--;

		int temoint = front(_deq);

		_deq->m_pDirectory[0] = temp;
		return temoint;
	};
};

int pop_back(IntegerDeque *_deq) {
	if (_deq->m_backUsed == 1) {
		int temoint = _deq->m_pDirectory[_deq->m_backBlockIndex - 1][0];
		directoryDecreaseBottom(_deq);
		_deq->m_backUsed = _deq->m_blockSize;
		return temoint;
	}else {
		int temoint = back(_deq);
		int *temp = new int[_deq->m_blockSize];
		memcpy(  temp, *(_deq->m_pDirectory + _deq->m_backBlockIndex) , sizeof(int)*(_deq->m_backUsed - 2));
		_deq->m_backUsed--;
		return temoint;
	};
};


int back(IntegerDeque *_deq) {
	return _deq->m_pDirectory[_deq->m_backBlockIndex - 1][_deq->m_backUsed - 1];
};


int front(IntegerDeque *_deq) {
	return _deq->m_pDirectory[0][_deq->m_blockSize - _deq->m_frontUsed - 1];
};

bool is_empty(IntegerDeque *_deq) {
	if (( _deq->m_directorySize == 1) && (_deq->m_frontUsed == 0)) {
		return true;
	};
	return false;

};




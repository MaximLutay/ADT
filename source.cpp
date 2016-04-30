#include "header.hpp"

#include <iostream>
#include<cassert>

BIG bit = 64;



struct ch_structurus {
	BIG *p_massivus;

	BIG n_studentus;
	BIG n_blockus_alocatedus;

	BIG n_passus;
	BIG n_failus;
};






ch_structurus * $create(BIG _n_studentus) {
	ch_structurus * _ptr = new ch_structurus;

	_ptr->n_blockus_alocatedus = (_n_studentus - 1) / bit + 1;
	_ptr->n_studentus = _n_studentus;

	_ptr->p_massivus = new BIG[_ptr->n_blockus_alocatedus];

	_ptr->n_passus = 0;
	_ptr->n_failus = 0;

	$clearall(_ptr, _ptr->n_blockus_alocatedus);	/*optional *//* i.e. _ptr->n_failus = _ptr->n_studentus*//*all students fail*/	//f


	std::cout << "\n >__test__/* blocks : " << _ptr->n_blockus_alocatedus << "   */";	//t

	return _ptr;
}


void $delete(ch_structurus *_p) {
	delete[] _p->p_massivus;
	delete _p;
}


void $clearall(ch_structurus*_p, BIG _n_blockus_allocatedus) {
	for (BIG _h = 0;_h < _n_blockus_allocatedus;_h++) {
		*(_p->p_massivus + _h) = 0;
		assert(*(_p->p_massivus + _h) == 0);							//t
	};
	_p->n_failus = _p->n_studentus;

}





void $pass(ch_structurus* _p, BIG _position) {
	if (_position < _p->n_studentus) {
		_p->n_passus++;
		_p->n_failus--;
		BIG _shift = 1;
		_shift <<= (_position % bit);
		BIG _block = _position / bit;

		*(_p->p_massivus + _block) |= _shift;

		std::cout << "\n>__test__/*   pass...result :" << *(_p->p_massivus + _block) << "   */";

	}
	else {
		std::cout << "\n>__test__/*    pass...result :  illegal operation   */";					//t
	};

}


void $fail(ch_structurus *_p, BIG _position) {
	if (_position < _p->n_studentus) {
		_p->n_passus--;
		_p->n_failus++;
		BIG _shift = 1;
		_shift <<= (_position % bit);
		BIG _block = _position / bit;

		*(_p->p_massivus + _block) &= ~(_shift);

		std::cout << "\n>__test__/*   fail...result: " << *(_p->p_massivus + _block) << "   */";

	}
	else {
		std::cout << "\n>__test__/*   fail...result : illegal operation   */";					//t
	};

}







bool $isempty(ch_structurus *_p) {
	bool _temp = _p->n_studentus == 0;
	return _temp;
}

bool $isfull(ch_structurus *_p) {
	bool _temp = (_p->n_studentus == (_p->n_failus + _p->n_passus));
	return _temp;
}

BIG $size(ch_structurus *_p) {
	BIG _temp = _p->n_studentus;
	return _temp;
}

ch_structurus * $union(ch_structurus *_p1, ch_structurus *_p2) {
	ch_structurus * _ptr = $create(_p1->n_studentus);
	for (BIG q = 0;q < _p1->n_blockus_alocatedus;q++) {
		*(_ptr->p_massivus + q) = *(_p1->p_massivus + q) | *(_p2->p_massivus + q);
	};
	return _ptr;
}

ch_structurus * $intersection(ch_structurus *_p1, ch_structurus *_p2) {
	ch_structurus * _ptr = $create(_p1->n_studentus);
	for (BIG q = 0;q < _p1->n_blockus_alocatedus;q++) {
		*(_ptr->p_massivus + q) = *(_p1->p_massivus + q) & *(_p2->p_massivus + q);
	};
	return _ptr;

}

ch_structurus * $difference(ch_structurus *_p1, ch_structurus *_p2) {
	ch_structurus * _ptr = $create(_p1->n_studentus);
	for (BIG q = 0;q < _p1->n_blockus_alocatedus;q++) {
		*(_ptr->p_massivus + q) = *(_p1->p_massivus + q) & ~*(_p2->p_massivus + q);
	};
	return _ptr;
}

ch_structurus * $symmetricdifference(ch_structurus *_p1, ch_structurus *_p2) {
	ch_structurus * _ptr = $create(_p1->n_studentus);
	for (BIG q = 0;q < _p1->n_blockus_alocatedus;q++) {
		*(_ptr->p_massivus + q) = *(_p1->p_massivus + q) ^ *(_p2->p_massivus + q);
	};
	return _ptr;
}

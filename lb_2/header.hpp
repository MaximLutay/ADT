#pragma once
#ifndef __header_hpp_
#define  __header_hpp_

typedef unsigned long long int BIG;

struct ch_structurus;


ch_structurus * $create(BIG _n_studentus);										//allocate memory
void $delete(ch_structurus *_p);												//delete allocated memory

void $clearall(ch_structurus*_p, BIG _n_blockus_allocatedus);					//insert false for all	

void $pass(ch_structurus*_p, BIG _position);									//insert true
void $fail(ch_structurus *_p, BIG _position);									//insert false

bool $isempty(ch_structurus *_p);												// is empty ? true : false
bool $isfull(ch_structurus *_p);												//is full? true : false

BIG $size(ch_structurus *_p);													//size

ch_structurus * $union(ch_structurus *_p1, ch_structurus *_p2);					//union
ch_structurus * $intersection(ch_structurus *_p1, ch_structurus *_p2);			//intersection
ch_structurus * $difference(ch_structurus *_p1, ch_structurus *_p2);			//difference
ch_structurus * $symmetricdifference(ch_structurus *_p1, ch_structurus *_p2);   //symmetricdifference




#endif

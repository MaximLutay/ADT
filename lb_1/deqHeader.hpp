#pragma once
#ifndef __Header__
#define  __Header__


struct IntegerDeque;
IntegerDeque * createIntDeq(int _m_block_size);
void directoryGrowTop(IntegerDeque * _deq);
void directoryGrowBottom(IntegerDeque * _deq);
void directoryDelete(IntegerDeque * _deq);
void push_front(IntegerDeque *_deq, int _value);
void push_back(IntegerDeque *_deq, int _value);
void directoryDecreaseTop(IntegerDeque *_deq);
void directoryDecreaseBottom(IntegerDeque *_deq);
int pop_front(IntegerDeque *_deq);
int pop_back(IntegerDeque *_deq);
int back(IntegerDeque *_deq);
int front(IntegerDeque *_deq);
bool is_empty(IntegerDeque *_deq);










#endif

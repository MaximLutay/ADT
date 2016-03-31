#include "stdafx.h"

#include"point3D_queue.hpp"




struct Point3D {
	float x, y, z;
};

struct Point3DQueueElement {
	Point3D value;
	Point3DQueueElement * p_next;
};



struct Point3DQueue {

	Point3DQueueElement * p_beg, *p_end;

};




Point3DQueue * Point3DQueueCreate() {                                         
	Point3DQueue * p_queue = new Point3DQueue;
	p_queue->p_beg = p_queue->p_end = nullptr;
	return p_queue;
};




void Point3DQueuePush(  Point3D values, Point3DQueue * ptr) {

	Point3DQueueElement * p_new_element = new Point3DQueueElement;								
	p_new_element->value = values;

	p_new_element->p_next = nullptr;

	if (ptr->p_beg == nullptr) {
		ptr->p_beg = ptr->p_end = p_new_element;
	}else {
		ptr->p_end->p_next = p_new_element;
		ptr->p_end = p_new_element;
	};

};


void Point3DQueuePop(Point3DQueue * ptr) {                              
	Point3DQueueElement * tmp_p_beg = ptr->p_beg;						
	ptr->p_beg = ptr->p_beg->p_next;									
	delete tmp_p_beg;                                                   
};


Point3D Point3DQueueFront(Point3DQueue * ptr) {
	Point3D FrontElement = ptr->p_beg->value;
	return (FrontElement);
};



void Point3DQueueDestroy(Point3DQueue *ptr) {

	Point3DQueueElement * curr = ptr->p_beg;
	while (curr!= nullptr){
		Point3DQueueElement * temp = curr;
		ptr->p_beg = curr->p_next;
		delete temp;

	};

};

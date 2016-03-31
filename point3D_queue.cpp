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

	Point3DQueueElement element;

	Point3DQueueElement * p_beg, *p_end;

};




Point3DQueue * Point3DQueueCreate() {                                         //создание структуры без создания узлов
	Point3DQueue * p_first = new Point3DQueue;
	p_first->p_beg = p_first->p_end = nullptr;
	return p_first;
};

void Point3DQueuePush(/*float l, float m, float n*/  Point3D values, Point3DQueue * ptr) {		//создание узла и его инициализация  //ЗАМЕНИТЬ НА ВВОД СТРУКТУРЫ!!!!!
	Point3DQueueElement * p_new_element = new Point3DQueueElement;								//создание элемента
												/*p_new_element->value.x = l;					//присваивание подэлементов элемента
												p_new_element->value.y = m;
												p_new_element->value.z = n;
												*/
	p_new_element->value.x = values.x;
	p_new_element->value.y = values.y;
	p_new_element->value.z = values.z;

	p_new_element->p_next = nullptr;

	ptr->element = *p_new_element;											//создание узла

	if (ptr->p_beg == ptr->p_end) {                                       //если узлов нет
		ptr->p_beg = ptr->p_end = p_new_element;                         //то новый узел  и начало,и конец
	}
	else {                                                               //если есть 
		ptr->p_end->p_next = p_new_element;                              //следующий элемент того который был последним - новый узел
		ptr->p_end = p_new_element;                                      //новый узел теперь последний
	};

};
void Point3DQueuePop(Point3DQueue * ptr) {                               //удаление с начала
	Point3DQueueElement * tmp_p_beg = ptr->p_beg;                        //создание копии
	ptr->p_beg = ptr->element.p_next;									 //второй элемент - начальный 
	delete tmp_p_beg;                                                    //удаляем то, что было раньше начальным

};



Point3D Point3DQueueFront(Point3DQueue * ptr) {
	
	Point3D FrontElement = ptr->p_beg->value;

	return (FrontElement);

};


void Point3DQueueDestroy(Point3DQueue *ptr) {

	Point3DQueueElement * curr = ptr->p_beg;
	while (curr) {
		Point3DQueueElement * temp = curr;
		ptr->p_beg = curr->p_next;
		delete temp;

	};

};

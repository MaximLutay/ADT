// ADT_LB_19_b4_p2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
#include<cassert>
#include"point3D_queue.hpp"

struct Point3D {
	float x, y, z;
};


int main()
{
	Point3DQueue* pQ = Point3DQueueCreate();
	
	std::cout << ">created queue\n";
	
	Point3D p1 = { 0.0, 0.0, 0.0 };
	Point3D p2 = { 1.0, 1.0, 1.0 };
	Point3D p3 = { -1.0, -1.0, -1.0 };
	std::cout << ">created points\n";

	Point3DQueuePush(p1, pQ);
	Point3DQueuePush(p2, pQ);
	Point3DQueuePush(p3, pQ);


	std::cout << ">added points\n";

	
	Point3DQueuePop(pQ);                      

	std::cout << ">deleted first\n";
	
	Point3D triangle = Point3DQueueFront(pQ); 

	std::cout << ">watched first\n";

	assert(triangle.x == p2.x && triangle.y == p2.y && triangle.z == p2.z);
	std::cout << ">checked\n";

	std::cout << triangle.x << "\n" << triangle.y << "\n" << triangle.z << "\n";

	
	
	system("pause");
	

	Point3DQueueDestroy(pQ);//<-trouble Need help

	std::cout << ">deleted\n";



    return 0;
}

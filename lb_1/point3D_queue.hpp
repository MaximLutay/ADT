
struct Point3D ;

struct Point3DQueueElement ;

struct Point3DQueue;




Point3DQueue * Point3DQueueCreate();

void Point3DQueuePush(  Point3D values, Point3DQueue * ptr);


void Point3DQueuePop(Point3DQueue * ptr) ;



Point3D Point3DQueueFront(Point3DQueue * ptr) ;


void Point3DQueueDestroy(Point3DQueue *ptr) ;

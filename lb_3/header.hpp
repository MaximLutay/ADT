#pragma once
#ifndef __header_hpp_
#define  __header_hpp_

	struct node ;





node* $find(node* p, int k);
int $getsize(node* p) ;
void $fixsize(node* p) ;
node* $rotateright(node* p); 
node* $rotateleft(node* q) ;
node* $insertroot(node* p, int k) ;
node* $insert(node* p, int k) ;
node* $join(node* p, node* q) ;
node* $remove(node* p, int k);




#endif

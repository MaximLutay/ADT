#include <iostream>
#include<ctime>
#include<cassert>



	struct node 
	{
		int key;  
		int size; 
		node* left; 
		node* right; 
		node(int k) { key = k; left = right = 0; size = 1; } 
	} ;





node* $find(node* p, int k);
int $getsize(node* p) ;
void $fixsize(node* p) ;
node* $rotateright(node* p); 
node* $rotateleft(node* q) ;
node* $insertroot(node* p, int k) ;
node* $insert(node* p, int k) ;
node* $join(node* p, node* q) ;
node* $remove(node* p, int k);





int main(){
	
	
	node  root(-1);
	
	for(int k = 10;k>0;k--){
		$insert(&root , k);
	};
	
	std::cout<<$getsize(&root);
	

	
	return 0;
};






node* $find(node* p, int k) {
    if( !p ){ return 0;}; // в пустом дереве можно не искать
    if( k == p->key ){
        return p; };
    if( k < p->key ){
        return $find(p->left,k);} 
    else{
        return $find(p->right,k);}; 
};


int $getsize(node* p) 
{
	if( !p ) return 0; 
	return p->size; 
}

void $fixsize(node* p) 
{
	p->size = $getsize(p->left)+$getsize(p->right)+1; 
};


node* $rotateright(node* p) 
{
	std::cout<<"\n>rTR";
	node* q = p->left; 
	if( !q ) return p; 
	p->left = q->right; 
	q->right = p; 
	q->size = p->size; 
	$fixsize(p); 
	return q; 
};



node* $rotateleft(node* q) 
{
	std::cout<<"\n>rTL";
	node* p = q->right;
	if( !p ) return q;
	q->right = p->left;
	p->left = q;
	p->size = q->size;
	$fixsize(q);
	return p;
};


node* $insertroot(node* p, int k) {
	
	std::cout<<"\n>Iroot";
	if( !p ) return new node(k); 
	if( k<p->key ) 
	{
		p->left = $insertroot(p->left,k); 
		return $rotateright(p); 
	}
	else 
	{
		p->right = $insertroot(p->right,k);
		return $rotateleft(p);
	}
};



node* $insert(node* p, int k) 
{
	std::cout<<"\n>I";
	if( !p ) return new node(k); 
	if( rand()%(p->size+1)==0 ) 
		return $insertroot(p,k); 
	if( p->key > k ) {
		p->left = $insert(p->left,k); std::cout<<"L";
	}else{
		p->right = $insert(p->right,k); std::cout<<"R";
	};	
    $fixsize(p); 
	return p; 
};



node* $join(node* p, node* q) 
{
	if( !p ) return q;
	if( !q ) return p;
	if( rand()%(p->size+q->size) < p->size ) 
	{
		p->right = $join(p->right,q); 
		$fixsize(p); 
		return p; 
	}
	else 
	{
		q->left = $join(p,q->left); 
		$fixsize(q); 
		return q; 
	}
};



node* $remove(node* p, int k) 
{
	if( !p ) return p; 
	if( p->key==k ) 
	{
		node* q = $join(p->left,p->right); 
		delete p; 
		return q; 
	}
	else if( k<p->key ) 
		p->left = $remove(p->left,k); 
	else 
		p->right = $remove(p->right,k); 
	return p; 
};



int $maxDepth( node *p){
	
};


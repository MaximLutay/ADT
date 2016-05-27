//used resources
//http://neerc.ifmo.ru/wiki/index.php?title=%D0%A0%D0%B0%D0%BD%D0%B4%D0%BE%D0%BC%D0%B8%D0%B7%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%BD%D0%BE%D0%B5_%D0%B1%D0%B8%D0%BD%D0%B0%D1%80%D0%BD%D0%BE%D0%B5_%D0%B4%D0%B5%D1%80%D0%B5%D0%B2%D0%BE_%D0%BF%D0%BE%D0%B8%D1%81%D0%BA%D0%B0
//https://habrahabr.ru/post/145388/
//Р.Седжвик Фундаментальные алгоритмы на С++ 

#include <iostream>
#include<ctime>

struct randTree {
	struct Node{
		int vlu;
		int totalSize;    //P($insertRoot)=1/(n+1), n = n of edges//totalsize+= children
		Node* left;
		Node* right;
		Node(int _val) { vlu = _val;left = right = NULL; totalSize = 1; };//конструктор  {можно ? оставить : (удалить ,дописать )}
	};

	Node *root;

	int depth;
};


/*
Node* $find(Node* _el, int _k);
Node* $insert(Node* _el, int _k);
int $getSize(Node* _el);
void $fixSize(Node* _el);
Node* $rotateRight(Node* _el);
Node* $rotateLeft(Node* q);
Node* $insertRoot(Node* _el, int _k);
Node* $join(Node* _el, Node* q);
Node* $remove(Node* _el, int _k);
*/

int main() {

	srand(time(0));
	randTree *myTr = $createRandTree();


	for (int i = 20;i > -1;i--) {
	
	
	
	};


	



	system("pause");
	
	$destroyRandTree(myTr);

	return 0;
};




randTree* $createRandTree() {
	randTree *tmp = new randTree;
	tmp->root = 0;
	return tmp;
};

void $destroyRandTree( randTree *_ptr ) {
	$destroyRandTreeNodes(_ptr->root);
	delete _ptr;
};
void $destroyRandTreeNodes( randTree::Node * _node) {
	if (!_node) { return; };

	$destroyRandTreeNodes(_node->left);
	$destroyRandTreeNodes(_node->right);
	delete _node;
};

void $rotateLeft(randTree::Node *_node) {
	randTree::Node *temp = _node->right;
	_node->right = temp->left;
	temp->left = _node;
	_node = temp;
};
void $rotateRight(randTree::Node *_node) {
	randTree::Node *temp = _node->left;
	_node->left = temp->right;
	temp->right = _node;
	_node = temp;
};

randTree::Node $insertRoot(randTree::Node * _node, int _val) { 
	if (_node == 0) { _node = new randTree::Node(_val);return 0;};

	if(_val < _node->vlu ){//have to be root
		$insert(_node->left, _val);
		$rotateRight(_node);
	}else {
		$insert(_node->right, _val);
		$rotateLeft(_node);
	};
};
randTree::Node $insert(randTree::Node* _node, int _val) {
	if (_node == 0) { _node = new randTree::Node(_val);return 0; };
	
	if (!rand() % (_node->totalSize + 1)) { $insertRoot(_node, _val);};//вероятность нуля = 1/(размер+1), если ноль вставка в корень   //1С :)

	if (_val < _node->vlu) {
		$insert(_node->left, _val);
		$getAndSetSize(_node);
	}else {
		$insert(_node->right, _val);
		$getAndSetSize(_node);
	};

};

int $getAndSetSize(randTree::Node* _node) {

	if (_node == 0) { return 0;
	}else{
		_node->totalSize = ($getAndSetSize(_node->left) + $getAndSetSize(_node->right) + 1);
		return _node->totalSize;
	}; 
};

randTree::Node * $search(randTree::Node *_node, int _val) {


		if (_node->vlu == _val) {
			return _node;
		}else {
			if (_node == 0) { return nullptr; };
			if (_node->vlu > _val) {
				return $search(_node->right,_val);
			}else {
				return $search(_node->left, _val);
			};
		};
	
};
bool $hasKey(randTree *_tree, int _val) {
	return $search(_tree->root, _val) != nullptr ;
};

randTree::Node * $searchMin(randTree::Node *_node) {
	
	randTree::Node * temp = _node;
	while (_node && _node->left) {
		temp = _node->left;
	};
	return temp;
};
randTree::Node * $searchMax(randTree::Node *_node) {

	randTree::Node * temp = _node;
	while (_node && _node->right) {
		temp = _node->right;
	};
	return temp;
};

int $randTreeMin(randTree _ptr) {
	return $searchMin(_ptr.root)->vlu;
};

int $randTreeMax(randTree _ptr) {
	return $searchMax(_ptr.root)->vlu;
};


randTree::Node * $alliance(randTree::Node * _f, randTree::Node * _s) {
	randTree::Node *temp = 0;



	if (_f == 0 && _s == 0) {
		return temp;

	}
	else if (_f == 0 || _s == 0) {

		if (_f == 0) {

			temp =  _s;
		};

		if (_s == 0) {
			temp =  _f;
		};
	}else {

		if (rand() % (_f->totalSize + _s->totalSize) < _f->totalSize) {
			_f->right = $alliance(_f->right, _s);
			$getAndSetSize(_f);
			temp = _f;
		}else {
			_s->left = $alliance(_f, _s->left);
			$getAndSetSize(_s);
			temp = _s;
		};
	};
	
	return temp;

};



void $remove(randTree *_tree, int _val ) {
	randTree::Node * nd = _tree->root;
	randTree::Node * toDel = $search(nd, _val);

	nd = $alliance( toDel->left,toDel->right);
	$getAndSetSize(nd);
};


void $spOutput(randTree *_tree) {

};




//why all above doesn't work as needed?
/*Node* $find(Node* _el, int _k){ 

	if (!_el) {
		return 0;	
	};
	
	
	if (_k == _el->key) {
		return _el;
	}else if (_k < _el->key) {		
		return $find(_el->left, _k);	
	}else {		
		return $find(_el->right, _k);	
	};

};
Node* $insert(Node* _el, int _k){

	if (!_el) {  		
		return new Node(_k);
	};
	
	if (rand() % (_el->size + 1) == 0) {	
		return $insertRoot(_el, _k);
	};

	if (_el->key>_k) {
		_el->left = $insert(_el->left, _k);std::cout << "\n<<_l_\n";
	}else {
		_el->right = $insert(_el->right, _k);std::cout << "\n<<_r_\n";
	};



	$fixSize(_el);


	return _el;
};


int $getSize(Node* _el){
	if (!_el) { return 0; };
	return _el->size;
};


void $fixSize(Node* _el){
	_el->size = $getSize(_el->left) + $getSize(_el->right) + 1;

};


Node* $rotateRight(Node* _el){
	Node* q = _el->left;
	if (!q) { return _el; };
	_el->left = q->right;
	q->right = _el;
	q->size = _el->size;
	$fixSize(_el);
	return q;
};



Node* $rotateLeft(Node* q){
	Node* _el = q->right;
	if (!_el) { return q; };
	q->right = _el->left;
	_el->left = q;
	_el->size = q->size;
	$fixSize(q);
	return _el;
};


Node* $insertRoot(Node* _el, int _k){
	std::cout << "\n<<root_";
	if (!_el) return new Node(_k);
	if (_k<_el->key)
	{
		_el->left = $insertRoot(_el->left, _k);
		return $rotateRight(_el);
	}else{
		_el->right = $insertRoot(_el->right, _k);
		return $rotateLeft(_el);
	};
};



Node* $join(Node* _el, Node* q) // объединение двух деревьев
{
	if (!_el) {
		return q; 
	}else if (!q) {
		return _el;
	};

	if (rand() % (_el->size + q->size) < _el->size){ //выбираем корень
		_el->right = $join(_el->right, q);
		$fixSize(_el);
		return _el;
	}else{
		q->left = $join(_el, q->left);
		$fixSize(q);
		return q;
	};
};



Node* $remove(Node* _el, int _k) // удаление из дерева _el первого найденного узла с ключом _k 
{

	std::cout << "\??>$removerun_";
	if (!_el) { return _el; 
	} if (_el->key == _k){
		Node* q = $join(_el->left, _el->right);
		delete _el;
		return q;
	}else if (_k < _el->key) {
		_el->left = $remove(_el->left, _k);
	}else {
		_el->right = $remove(_el->right, _k);
	};
	return _el;
};


*/
#include "leftistHeap.h"

// Node Methods

Node::Node(std::pair<float, int> e) {
	this->_elem = e;
	this->_dist = 0;
	this->_parent = NULL;
	this->_left = NULL;
	this->_right = NULL;
}

Node::Node(std::pair<float, int> e, int d, Node *parent, Node *l, Node *r) {
	this->_elem = e;
	this->_dist = d;
	this->_parent = parent;
	this->_left = l;
	this->_right = r;
}

// LeftistHeap Methods

// Public methods

LeftistHeap::LeftistHeap() {
	_root = NULL;
	_map = new std::unordered_map<int, Node*>;
}

LeftistHeap::LeftistHeap(Node *newRoot,
		std::unordered_map<int, Node*> *newMap) {
	_root = newRoot;
	_map = newMap;
}

int LeftistHeap::getMin() {
	return _root->_elem.second;
}

void LeftistHeap::deleteMin() {
	if (!isEmpty()) {
		_map->erase(_root->_elem.first);
		Node *aux = _root;
		if (_root->_left != NULL)
			_root->_left->_parent = NULL;
		if (_root->_right != NULL)
			_root->_right->_parent = NULL;
		_root = mergeHeaps(_root->_left, _root->_right);
		delete aux;
	}
}

void LeftistHeap::deleteMin(std::pair<float, int> &minElem) {
	minElem = _root->_elem;
	deleteMin();
}

void LeftistHeap::insert(std::pair<int, int> elem) {
	if (_map->find(elem.second) != _map->end()) {
		std::cerr << elem.second << " already exists in the heap.\n";
		return;
	}
	Node *newElem = new Node(elem);
	_map->insert(std::make_pair(elem.second, newElem));
	_root = mergeHeaps(_root, newElem);
}

void LeftistHeap::decreaseKey(int elem, float newDist) {	// Permite decrementar el valor de la distancia del nodo que contiene al elemento "elem"
	// Busca en el mapa el valor indicado por "elem"
	std::unordered_map<int, Node*>::iterator iter = _map->find(elem);
	// Comprueba que exista en el monticulo
	if (iter != _map->end()) {
		// Si se trata de la raiz, decrece el valor correspondiente
		if (iter->second == _root) {
			_root->_elem.first = newDist;
		}
		// En caso de no ser la raiz, crea un nuevo nodo con los valores apropiados
		else {
			Node *aux = new Node(
					std::make_pair(newDist, iter->second->_elem.second),
					0,
					iter->second->_parent,
					iter->second->_left, 
					iter->second->_right
					);
			// Comprueba si se trata del hijo izquierdo o derecho de su padre
			if ((aux->_parent->_left->_elem.second == elem)) {
				// Si se trata del izquierdo, el puntero _left del padre se apunta a NULL
				aux->_parent->_left = NULL;
				// Se intercambian los hijos del padre que el derecho no debe ser hijo unico
				swapChildren(aux->_parent);
			} else
				// Si se trata del derecho, el puntero _right del padre se apunta a NULL
				aux->_parent->_right = NULL;
			// Perdemos el puntero _parent, descolgando de forma efectiva nuestro nodo a decrementar del monticulo
			aux->_parent = NULL;
			// Se indica a nuestros hijos _left y _right que aux es el nuevo nodo padre, ya que es una direccion de memoria distinta
			if (aux->_left != NULL)
				aux->_left->_parent = aux;
			if (aux->_right != NULL)
				aux->_right->_parent = aux;
			// Llamamos a mergeHeaps() con la raiz original de nuestro monticulo y el nuevo nodo que hemos descolgado
			_root = mergeHeaps(_root, aux);
			// Eliminamos la antigua direccion del nodo del mapa e insertamos la nueva
			_map->erase(elem);
			_map->insert(std::make_pair(elem, aux));
		}
	}
}

void LeftistHeap::merge(LeftistHeap &b) {
	if (this == &b)
		return;
	_root = mergeHeaps(_root, b._root);
	b._root = NULL;
}

bool LeftistHeap::isEmpty() {
	return _root == NULL;
}

void LeftistHeap::emptyHeap() {
	clearMem(_root);
	_root = NULL;
	_map->empty();
}

void LeftistHeap::printHeap() {
	LeftistHeap aux;
	aux = *this;
	std::pair<float, int> x;
	while (!aux.isEmpty()) {
		aux.deleteMin(x);
		std::cerr << '(' << x.second << ' ' << x.first << ')' << ' ';
	}
	std::cerr << '\n';
}

LeftistHeap& LeftistHeap::operator =(LeftistHeap &h) {
	if (this != &h) {
		emptyHeap();
		_root = cloneNode(h._root);
	}
	return *this;
}

std::unordered_map<int, Node*>* LeftistHeap::map() {
	return _map;
}

// Private methods

Node* LeftistHeap::mergeHeaps(Node *heap1, Node *heap2) {
	if (heap1 == NULL)
		return heap2;
	if (heap2 == NULL)
		return heap1;
	if (heap1->_elem.first <= heap2->_elem.first) {
		return MergeRecursive(heap1, heap2);
	}
	return MergeRecursive(heap2, heap1);
}

Node* LeftistHeap::MergeRecursive(Node *heap1, Node *heap2) {
	// Aparte de realizar el merge de forma correcta, se encarga de asignar el padre de cada nodo en cada asignacion
	if (heap1->_left == NULL) {
		heap1->_left = heap2;
		heap2->_parent = heap1;
	} else {
		heap1->_right = mergeHeaps(heap1->_right, heap2);
		heap1->_right->_parent = heap1;
		if (heap1->_left->_dist < heap1->_right->_dist)
			swapChildren(heap1);
		heap1->_dist = heap1->_right->_dist + 1;
	}
	return heap1;
}

void LeftistHeap::swapChildren(Node *parent) {
	Node *aux = parent->_right;
	parent->_right = parent->_left;
	parent->_left = aux;
}

void LeftistHeap::clearMem(Node *node) {
	if (node != NULL) {
		clearMem(node->_left);
		clearMem(node->_right);
		delete node;
	}
}

Node* LeftistHeap::cloneNode(Node *node) {
	if (node == NULL)
		return NULL;
	return new Node(node->_elem, node->_dist, node->_parent,
			cloneNode(node->_left), cloneNode(node->_right));
}

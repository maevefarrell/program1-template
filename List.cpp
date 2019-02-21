#include "List.h"

//Constructor
List::List(){
	this->head = NULL;
	this->tail = NULL;
}

//Destructor
List::~List(){
	Node * curr = this.head();

	for(int i=0;i<size();i++){
		Node * n = curr->next;
		delete curr;
		curr = n;
	}
	this->head = NULL;
	this->tail = NULL;
}

//get head() and tail()
Node * List::getHead(){
	return this->head;
}
Node * List::getTail(){
	return this->tail;
}

//inserts an element at index, increasing the List size by 1
//if the insert index is out of bounds, you should append to the end of the list
void List::insert(int index, Planet * p){
	Node * curr = new Node();
	curr->planetData = p;
	if(this->getHead()==NULL){
		this->head = curr;
		this->tail = curr;
		curr->next = NULL;
		curr->prev = NULL;
	} else if(index > size()){
		this.getTail()->next = curr;
		curr->prev = this.getTail();
		this->tail = curr;
		curr->next = NULL;

	} else{
		Node * n = this->getHead();
		for(int i=0;i<index-1;i++){
			n = n->next;
		}
		curr->prev = n;
		curr->next = n->next;
		n->next->prev = curr;
	}
}

Planet * List::read(int index){
	Node * curr = this->getHead();

	if(index>size()){
		return NULL;
	} else{
		Planet * retPlanet;
		for(int i=0;i<index;i++){
			curr = curr->next;
		}
	}
	return curr->planetData;

}

bool List::remove(int index){
	Node * n = this->getHead();
	for(int i = 0; i<index;i++){
		n = n->next;
	}
	n->prev->next = n->next;
	n->next->prev = n->prev;
	delete n;
}

unsigned List::size(){
	unsigned int numElements = 0;
	Node * curr = getHead();
	while(curr->next!=NULL){
		numElements++;
		curr = curr->next;
	}
	numElements++;
	return numElements;
}

#include "List.h"

//Constructor
List::List(){
	this->head = NULL;
	this->tail = NULL;
	size = 0;
}

//Destructor
List::~List(){
	Node * curr = this.head();

	for(int i=0;i<size;i++){
		Node * n = curr->next;
		delete curr;
		curr = n;
	}
	this->head = NULL;
	this->tail = NULL;
}

//get head() and tail()
Node * List::head(){
	return this->head;
}
Node * List::tail(){
	return this->tail;
}

//inserts an element at index, increasing the List size by 1
//if the insert index is out of bounds, you should append to the end of the list
void List::insert(int index, Planet * p){
	Node curr = new Node();
	curr->planetData = p;
	if(this.head()==NULL){
		this->head = curr;
		this->tail = curr;
		curr->next = NULL;
		curr->prev = NULL;
	} else if(index > size){
		this.tail()->next = curr;
		curr->prev = this.tail();
		this->tail = curr;
		curr->next = NULL;

	} else{
		Node * n = this.head();
		for(int i=0;i<index-1;i++){
			n = n->next;
		}
		curr->prev = n;
		curr->next = n->next;
		n->next->prev = curr;
	}
	this->size++;
}

Planet * List::read(int index){
	if(index>size){
		return NULL;
	} else{
		Planet * retPlanet;
		Node * curr = this.head();
		for(int i=0;i<index;i++){
			curr = curr->next;
		}
	}
	return curr->planetData;

}

bool List::remove(int index){
	Node * n = this.head();
	for(int i = 0; i<index;i++){
		n = n->next;
	}
	n->prev->next = n->next;
	n->next->prev = n->prev;
	delete n;
	this->size--;
}

unsigned List::size(){
	unsigned int numElements = 0;
	Node * curr = head();
	while(curr->next!=NULL){
		numElements++;
		curr = curr->next;
	}
	numElements++;
	return numElements;
}

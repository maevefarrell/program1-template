#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "Planet.h"
class Node{
  public:
		Node * next;
		Node * prev;
		Planet * planetData;
};

class List{
	private:
		Node * head;
		Node * tail;

	public:
		List();
		~List();
		Node * getHead();
		Node * getTail();
		void insert(int index, Planet * p);
		Planet * read(int index);
		bool remove(int index);
		unsigned size();


};

#endif

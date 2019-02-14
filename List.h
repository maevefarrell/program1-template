#ifndef LIST_H
#define LIST_H
#include <iostream>
class Node{
   	private:
		Node * next;
		Node * prev;
		Planet * planetData;	
}

class List{
	private:
		Node * head;
		Node * tail;
		int size;
	public:
		List();
		~List();
		Node * head();
		Node * tail();
		void insert(int index, Planet * p);
		Planet * read(int index);
		bool remove(int index);
		unsigned size;


}

#endif

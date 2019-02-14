#ifndef LIST_H
#define LIST_H

class Node{
   	private:
		Node * next;
		Node * prev;
		int data;	
}

class List{
	private:
		Node * currentNode;
		
	public:
		List();
		~List();
		void insert(int index, Planet * p);
		Planet * read(int index);
		bool remove(int index);
		unsigned size;


}

#endif

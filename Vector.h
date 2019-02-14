#ifndef VECTOR_H
#define VECTOR_H

class Vector{
	private:
		int arrSize;
		Planet ** planArr;
	public:
	Vector(); //constructor
	~Vector(); //destructor
	void insert(int index, Planet *p); //inserts element at index
	Planet* read(int index); //returns pointer to planet object at index
	bool remove(int index); // removes planet object at index
	unsigned size(); //returns current size of vector

#endif

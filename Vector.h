#ifndef VECTOR_H
#define VECTOR_H
#include "Planet.h"
#include <iostream>

class Vector{
	private:
		int arrSize;

	public:
		Planet ** planArr;
		Vector(); //constructor
		~Vector(); //destructor
		void insert(int index, Planet *p); //inserts element at index
		Planet* read(int index); //returns pointer to planet object at index
		bool remove(int index); // removes planet object at index
		unsigned size(); //returns current size of vector
};
#endif

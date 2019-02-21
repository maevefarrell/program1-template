#include "Vector.h"

Vector::Vector() {
	this->planArr = NULL;
	this->arrSize = 0;
}

Vector::~Vector() {
	for(int i = 0; i < arrSize; i++) {
		planArr[i] = NULL;
		delete (planArr[i]);
	}

	planArr = NULL;
	delete planArr;

}

void Vector::insert(int index, Planet *p) {
	arrSize++;
	planArr = new Planet*[arrSize];
	if(index > arrSize) {
		planArr[arrSize] = p;
	}
	else {
		for(int i = index; i < (arrSize-1); i++) {
			planArr[i+1] = planArr[i];
		}
		planArr[index] = p;
	}
}

Planet* Vector::read(int index) {
	if(index > arrSize || index < 0) {
		return NULL;
	}

	for(int i = 0; i < arrSize; i++) {
		if(i == index) {
			return planArr[i];
		}
	}
}

bool Vector::remove(int index) {
	for(int i = 0; i < arrSize; i++) {
		if(i == index) {
			delete (planArr[i]);
			delete planArr;
		}
	}
	arrSize--;
	planArr = new Planet*[arrSize];
}

unsigned Vector::size() {
	return arrSize;
}

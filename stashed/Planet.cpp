#include "Planet.h"
#include <stdlib.h>
#include <iostream>

Planet::Planet(int distance){
	const char arrayChar[3] = {'h', 'r', 'g'};
	char randChar = arrayChar[(rand() % 3)];
	this->id = &this;
	this->distance = distance;
    this->pos = (rand() % 360);
	this->type = randChar;
}

int Planet::orbit(){
	if (this->pos < 359) {
		this->pos++;
	}
	else {
		this->pos = 0;
	}

	return pos;
}

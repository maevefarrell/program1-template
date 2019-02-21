#include "Planet.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
int randNum(int zerotoval){
	int retval = rand() % (zerotoval);
	return (retval);
}
Planet::Planet(int id){
	this->id = id;
	this->distance = randNum(3000);
  this->pos = randNum(359);
	int teipe = randNum(2);
	switch(teipe){
		case 0:
			this->type='r';
		case 1:
			this->type='g';
		case 2:
			this->type='h';
	}

}

int Planet::orbit(){
	if(pos+1==360){
	   pos=0;
	} else{
	   pos++;
	}
	int retPos = this->pos;
	return retPos;
}

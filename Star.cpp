#include "Star.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

Starlist::Starlist(){
	planets = new List();
}
unsigned int Starlist::getCurrentNumPlanets(){
	unsigned int retval = 0;
  Node * n = planets->getHead();
  if(n!=NULL){
    retval = 1;
  }
  while(n->next!=NULL){
    retval++;
    n = n->next;
  }
  return retval;
}
Starlist::~Starlist(){
	delete planets;
}
long Starlist::addPlanet(){
	Planet * p = new Planet(getCurrentNumPlanets());
  planets->insert(p->getID(),p);
  long retval = p->getID();
  return retval;

}
bool Starlist::removePlanet(int id){
	return planets->remove(id);
}
Planet * Starlist::getPlanet(int id){
	Node * retN = planets->getHead();
  Planet * retp = NULL;
  while(retN->next!=NULL){
    if((retN->planetData)->getID()==id){
      retp = retN->planetData;
    }
    retN = retN->next;
  }
  return retp;
}

void Starlist::orbit(){
	Node * n = planets->getHead();
  while(n->next!=NULL){
    n->planetData->orbit();
    n = n->next;
  }
}
void Starlist::printStarInfo(){
	std::cout<<"The current star has "<<getCurrentNumPlanets()<<" planets."<<std::endl;
	std::cout<<"Planets:"<<std::endl;
  Node * n = planets->getHead();
	while(n->next!=NULL){
		std::cout<<"Planet "<<n->planetData->getType()<<n->planetData->getID()<<" is "<<n->planetData->getDistance()<<" million miles away at position "<<n->planetData->getPos()<<" around the star."<<std::endl;
    n = n->next;
	}
}

Starvector::Starvector() {
	this->planets = new Vector();
}

Starvector::~Starvector() {
	delete planets;
}

long Starvector::addPlanet() {
	int distance = rand() % 401; //is this correct
	Planet * p = new Planet(distance);
	int index = rand() % planets->size();

	planets->insert(index, p);

	return p->getID();
}

bool Starvector::removePlanet(int id) {
	for(int i = 0; i < planets->size(); i++) {
		if((planets->planArr[i])->getID() == id) {
			planets->remove(id);
			return true;
		}
	}

	return false;
}

Planet * Starvector::getPlanet(int id) {
	for(int i = 0; i < planets->size(); i++) {
		if((planets->planArr[i])->getID() == id) {
			return planets->planArr[i];
		}
	}
}

void Starvector::orbit() {
	for(int i = 0; i < planets->size(); i++) {
		(planets->planArr[i])->orbit();
	}
}

void Starvector::printStarInfo() {
	printf("This vector of stars is of size %d\n", planets->size());
}

unsigned int Starvector::getCurrentNumPlanets() {
	return planets->size();
}

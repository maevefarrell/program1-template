#include "Star.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

Starlist::Starlist(){
	planets = *(new List());
}
unsigned int Starlist::getCurrentNumPlanets(){
	unsigned int retval = 0;
  Node * n = planets->head;
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
  planets.insert(*p.getID(),p);
  long retval = *p.getID();
  returm retval;

}
bool Starlist::removePlanet(int id){
	return planets.remove(id);
}
Planet * Starlist::getPlanet(int id){
	Node * retN = planets->head;
  Planet * retp = NULL;
  while(retN->next!=NULL){
    if((retN->planetData).getID()==id){
      retp = retN->planetData;
    }
    retN = retN->next;
  }
  return retp;
}

void Starlist::orbit(){
	Node * n = planets->head;
  while(n->next!=NULL){
    n->planetData->orbit();
    n = n->next;
  }
}
void Starlist::printStarInfo(){
	std::cout<<"The current star has "<<getCurrentNumPlanets()<<" planets."<<std::endl;
	std::cout<<"Planets:"<<std::endl;
  Node * n = planets->head;
	while(n->next!=NULL){
		std::cout<<"Planet "<<n->planetData.getType()<<n->planetData.getID()<<" is "<<n->planetData.getDistance()<<" million miles away at position "<<n->planetData.getPos()<<" around the star."<<std::endl;
    n = n->next;
	}
}

#include "Starvector.h"
#include "Vector.h"
#include "Planet.h"
#include "Star.h"

Starvector::Starvector() {
	this->planets = new Vector();
}

Starvector::~Starvector() {
	delete planets;
}

long Starvector::addPlanets() {
	int distance = rand() % 401; //is this correct
	Planet * p = new Planet(distance);
	int index = rand() % planets.size();

	planets.insert(index, p);

	return &p;
}

bool Starvector::removePlanet(int id) {
	for(int i = 0; i < planets.size(); i++) {
		if((planets->planArr[i]).id == id) {
			planets.remove(id);
			return true;
		}
	}

	return false;
}

Planet * Starvector::getPlanet(int id) {
	for(int i = 0; i < planets.size(); i++) {
		if((planets->planArr[i]).id == id) {
			return planets->planArr[i];
		}
	}
}

void Starvector::orbit() {
	for(int i = 0; i < planets.size(); i++) {
		(planets->planArr[i]).orbit();
	}
}

void Starvector::printStarInfo() {
	printf("This vector of stars is of size %d\n", arrSize);
}

unsigned int Starvector::getCurrentNumPlanets() {
	return planets.size();
}

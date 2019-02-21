#include "Star.h"
#include "Planet.h"
#include <stdlib.h>
#include <iostream>

Star::Star() {
	this->current_planets = 0;
	this->planets= NULL;
}

Star::~Star() {
	int i;
	for(i = 0; i< current_planets; i++) {
		delete (planets[i]);
	}

	delete[] planets; 
}

int Star::addPlanet(){
	Planet ** temp_ptrs = new Planet*[(current_planets+1)];
	for(int i = 0; i < current_planets; i++) {
		temp_ptrs[i] = planets[i];
	}

	Planet * new_planet;
	new_planet = new Planet(&new_planet);
	temp_ptrs[current_planets] = new_planet;
	current_planets++;

	delete[] planets;

	planets = temp_ptrs;

	return new_planet->getID();
	
}

Planet* Star::getPlanet(int id) {
	int i;
	for(i = 0; i < current_planets; i++) {
		if((*planets[i]).getID() == id) {
			return planets[i];
		}
	}

	return NULL;
}

bool Star::removePlanet(int id) {
	if(this->getPlanet(id) == NULL) {
		return false;
	}
	Planet** temp_ptrs = new Planet*[current_planets-1];
	
	int count = 0;
	for(int i = 0; i < current_planets; i++) {
		if((*planets[i]).getID() != id) {
			temp_ptrs[count] = planets[i];
			count++;
		}

		else {
			delete planets[i];
		}
	}
	delete[] planets;
	planets = temp_ptrs;

	current_planets--;
	return true;	
}

Planet Star::getFurthest() {
	Planet furthest = *(planets[0]);


	for(int i = 0; i < current_planets; i++) {
		if((*planets[i]).getDistance() > furthest.getDistance()) {
			furthest = *(planets[i]);
		}
	}

	return furthest;
}

void Star::orbit() {
	for(int i = 0; i < current_planets; i++) {
		(*planets[i]).orbit();
	}
}

void Star::printStarInfo() {
	std::cout << "The star currently has " << current_planets;

	int i;
	for(i = 0; i < current_planets; i++) {
		std::cout << "Planet " << i << " is " << (*planets[i]).getDistance() << " at position " << (*planets[i]).getPos() << " around the star." << std::endl;
	}
}

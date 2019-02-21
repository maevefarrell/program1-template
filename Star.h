#ifndef STARLIST_H
#define STARLIST_H
#include "Planet.h"
#include "List.h"
#include "Vector.h"
class Starlist{
	private:

	public:
        List* planets;
        Starlist();
				~Starlist();
        long addPlanet();
				bool removePlanet(int);
				Planet * getPlanet(int);
        Planet getFurthest();
        void orbit();
        void printStarInfo();
        unsigned int getCurrentNumPlanets();
        //you may add any additional methodas you may need.
};

class Starvector{
	public:
	Vector *planets;
	Starvector(); //constructor
	~Starvector(); //destructor
	long addPlanet(); //returns ID of newly created planet
	bool removePlanet(int); //returns true upon successful deletion and false if planet ID isn't found
	Planet * getPlanet(int); //returns a pointer to planet
	void orbit(); //iterate through planets in vector and alters orbit position by 1
	void printStarInfo(); //prints star information
	unsigned int getCurrentNumPlanets(); //returns size of vector

};

#endif

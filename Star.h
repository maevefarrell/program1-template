#ifndef STARLIST_H
#define STARLIST_H
#include "Planet.h"
#include "List.h"
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

#endif

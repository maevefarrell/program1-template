#ifndef STAR_H
#define STAR_H
#include "Planet.h"


class Star{
	private:
        int current_planets;
        int next_id;
		int max_planets;
	public:
        Planet ** planets;
        Star();
		~Star();
        int addPlanet();
		Planet* getPlanet(int);
		bool removePlanet(int);
        Planet getFurthest();
        void orbit();
        void printStarInfo();
       	inline int getCurrentNumPlanets() {
			return this->current_planets;
		};
        //you may add any additional methodas you may need.
};

#endif

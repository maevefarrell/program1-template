#ifndef PLANET_H
#define PLANET_H

class Planet{
	private:
		int id;
		int pos;
		char type;
		int distance;
	public:
		Planet(){this->id=0;this->distance=0;this->pos=0;this->type='0';};
		Planet(int);
        	int orbit();
					char getType(){return this->type;};
					int getID(){return this->id;};
        	int getDistance(){return this->distance;};
        	int getPos(){return this->pos;};
		//you may add any additional methods you may need.
};

#endif

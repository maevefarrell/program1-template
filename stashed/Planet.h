#ifndef PLANET_H
#define PLANET_H

class Planet{
	private:
		int id;
		int pos;
		int distance;
		char type;
	public:
		Planet(){this->id=-1;};
		Planet(int);
        int orbit();
		inline int getID() {
			return this->id;
		};
		inline int getDistance() {
			return this->distance;
		};
		inline int getPos() {
			return this->pos;
		};
		inline char getType() {
			return this->type;
		};
		//you may add any additional methods you may need.
};

#endif

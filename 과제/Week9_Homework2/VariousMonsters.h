#pragma once
#include "Monster.h"
#include <ctime>

class Zombie : public Monster {
public:
	Zombie(string n = "ÇãÁ¢Á»ºñ", string i = "¡×", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~Zombie() { cout << " Zombie"; }
};

class Vampire : public Monster {
public:
	Vampire(string n = "¹ìÆÄÀÌ¾î", string i = "¡Ú", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~Vampire() { cout << " Vampire"; }

	void move(int** map, int maxx, int maxy) {
		int dir = rand() % 4;
		if (dir == 0) x--;
		else if (dir == 1) x++;
		else if (dir == 2) y--;
		else y++;
		clip(maxx, maxy);
		eat(map);
	}
};

class KGhost : public Monster {
public:
	KGhost(string n = "Ã³³à±Í½Å", string i = "¢¾", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~KGhost() { cout << " KGhost"; }

	void move(int** map, int maxx, int maxy) {
		x = rand() % maxx;
		y = rand() % maxy;
		clip(maxx, maxy);
		eat(map);
	}
};

class Jiangshi : public Monster {
	bool	bHori;
public:
	Jiangshi(string n = "´ë·ú°­½Ã", string i = "¡ê", int x = 0, int y = 0, bool bH = true)
		: Monster(n, i, x, y), bHori(bH) {}
	~Jiangshi() { cout << " Jiangshi"; }

	void move(int** map, int maxx, int maxy) {
		int dir = rand() % 2;
		int jump = rand() % 2 + 1;
		if (bHori) x += ((dir == 0) ? -jump : jump);
		else y += ((dir == 0) ? -jump : jump);
		clip(maxx, maxy);
		eat(map);
	}
};
class Siangshi : public Jiangshi {
	bool bHori;
public:
	Siangshi(string n = "½´ÆÛ°­½Ã", string i = "¡ê", int x = 0, int y = 0, bool bH = true)
		:Jiangshi(n, i, x, y), bHori(bH) {}
	~Siangshi() { cout << "Siangshi"; }
	void move(int** map, int maxx, int maxy) {
		int dir = rand() % 2;
		int jump = rand() % 2 + 1;
		if (bHori) y += ((dir == 0) ? -jump : jump);
		else x += ((dir == 0) ? -jump : jump);
		clip(maxx, maxy);
		eat(map);
	}
};


class Smombi : public Monster {
public:
	Smombi(string n = "½º¸öºñ", string i = "¢Ó", int x = 0, int y = 0)
		:Monster(n, i, x, y) {}
	~Smombi() { cout << "Smombi"; }
	void move(int** map, int maxx, int maxy) {
		int dir = rand() % 4;
		if (dir == 0) {
			x++;
			y++;
		}
		else if (dir == 1) {
			x--;
			y++;
		}
		else if (dir == 2) {
			x--;
			y--;
		}
		else {
			x++;
			y--;
		}
		clip(maxx, maxy);
		eat(map);
	}
};


class Creature : public Monster {
public:
	Creature(string n = "Ã¢Á¶¹°", string i = "¡Ù", int x = 0,int y = 0)
		:Monster(n,i,x,y){}
	~Creature() { cout << "Creature"; }
	void move(int** map, int maxx, int maxy) {
		int dir = rand() % 4;
		if (dir == 0) { x+=2; }
		else if (dir == 1) {x-=2;}
		else if (dir == 2) {y-=2;}
		else {y+=2;}
		clip(maxx, maxy);
		eat(map);
	}
};
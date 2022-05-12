#pragma once
#include "Canvas.h"
#define DIM 40

class Monster {
	string name, icon;	// 몬스터 이름과 화면 출력용 아이콘
	int x, y, nItem,nEnergy;// 현재 위치와 먹은 아이템 수
    int MonsterCount;
	void clip(int maxx, int maxy) {
		if (x < 0) x = 0;
		if (x >= maxx) x = maxx - 1;
		if (y < 0) y = 0;
		if (y >= maxy) y = maxy - 1;
	}
	void eat(int** map) {
		if (map[y][x] == 1) {
			map[y][x] = 0;
			nItem++;
			nEnergy += 8;
		}
		else {
			if (nEnergy != 0)
				nEnergy -= 1;
		}
	}
	
public:
	Monster(string n = "나괴물", string i = "※", int px = 0, int py = 0)
		: name(n), icon(i), x(px), y(py), nItem(0),nEnergy(0) {}
	~Monster() { cout << "\t" << name << icon << " 물러갑니다~~~\n"; }
	int getEnergy() {
		return nEnergy;
	}
	void MoveMonster(Monster* Copy) {
		name = Copy->name;
		icon = Copy->icon;
		x = Copy->x;
		y = Copy->y;
		nItem = Copy->nItem;
		nEnergy = Copy->nEnergy;
	}
	void draw(Canvas& canvas) { canvas.draw(x, y, icon); }
	void move(int** map, int maxx, int maxy) {
		switch (rand() % 8) {
		case 0: y--; break;
		case 1: x++; y--; break;
		case 2: x++; break;
		case 3: x++; y++; break;
		case 4: y++; break;
		case 5: x--; y++; break;
		case 6: x--; break;
		case 7: x--; y--; break;
		}
		clip(maxx, maxy);
		eat(map);
	}
    void printCount(int MonsterCount) {
		int HowMonster;
		HowMonster = MonsterCount;
		cout << "전체 몬스터수 : " << HowMonster << "\n" << endl;
		
	     if(HowMonster == 3) {
			cout << "몬스터 한마리가 죽었습니다" << endl;
		}
		else if (HowMonster == 2) {
			cout << "몬스터 한마리가 죽었습니다" << endl;
		}
		else if (HowMonster == 1) {
			cout << "몬스터 한마리가 죽었습니다" << endl;
		}
	}
	void print() { cout << "\t" << name << icon << ":" << nItem <<" E : " <<nEnergy <<endl; }
};
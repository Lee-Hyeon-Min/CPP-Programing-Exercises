#pragma once
#include <cstdio>
extern void loadRanking(const char* filename);
extern void storeRanking(const char* filename);
extern void printRanking();
extern int addRanking(int nMove, double tElap);
struct PlayInfo {
	char	name[200];
	int	nMove;
	double	tElapsed;
};

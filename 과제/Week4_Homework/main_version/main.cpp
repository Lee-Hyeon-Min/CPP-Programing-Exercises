#include <stdio.h>
#include <windows.h>
#include "Ranking.h"

extern int playFifteenPuzzle();
void main()
{
	loadRanking("ranking.txt");
	int rank = playFifteenPuzzle();
	printRanking();
	storeRanking("ranking.txt");

}
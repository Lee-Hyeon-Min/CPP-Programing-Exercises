#include <stdio.h>
#include <windows.h>
#include "Ranking.h"

extern int playFifteenPuzzle();
int main()
{
	loadRanking("ranking.bin");
	int rank = playFifteenPuzzle();
	printRanking();
	storeRanking("ranking.bin");
}
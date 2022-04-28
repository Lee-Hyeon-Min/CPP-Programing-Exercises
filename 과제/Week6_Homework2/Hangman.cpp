#include "Hangman.h"
#include "Mydic.h"
#include <cstdio>
#include <cstdlib>
int main()
{
	srand((unsigned)time(NULL));
	int number = rand() % WORDSMAX;
	Hangman game;
	MyDic find;
	find.load("SaveDic.txt");
	game.play(find.getEng(number));
	cout << find.getEng(number)<< " " << find.getKor(number) << endl;
	return 0;
}
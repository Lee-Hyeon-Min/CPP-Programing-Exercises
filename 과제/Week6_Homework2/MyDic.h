#include "Hangman.h"
#define WORDSMAX 10
struct WordPair {
	string eng;
	string kor;
};

class MyDic {
	WordPair words[WORDSMAX];
	int nWords = 0;
public:
	void add(string eng, string kor)
	{
		for (int i = MAXWORDS - 1; i > 0; i--)
		{
			words[i].eng = words[i - 1].eng;
			words[i].kor = words[i - 1].kor;
		}
		words[0].eng = eng;
		words[0].kor = kor;

		nWords += 1;
	}
	void load(string filename) {
		ifstream f1(filename);
		if (f1) {

			for (int i = 0; i < WORDSMAX; i++) {
				f1 >> words[i].eng>>words[i].kor;
			}
		}
		f1.close();
	}
	void save(string filename) {
		ofstream f2(filename);
		if (f2) {
			for (int i = 0; i < WORDSMAX; i++)
			{
				f2 << words[i].eng << words[i].kor<<endl;
			}
		}
		f2.close();
	}
	void print()
	{
		for (int i = 0; i < WORDSMAX-1; i++)
		{
			cout << words[i].eng << words[i].kor << endl;
		}
		
	}
	string getEng(int id) {
		return words[id].eng;
	}
	string getKor(int id) {
		return words[id].kor;
	}
};



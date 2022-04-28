#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define MAXWORDS 10
using namespace std;//std 이름 공간을 사용을 선언

class Hangman {//Hangman 게임 클래스 선언
	string progress[64];// 맴버 변수 선언, 모든 맴버는 기본적으로 private
	string problem;
	string answer;
	string guessed;
	int nTries;
	const int maxTries = 7;

	void load(const char* progName = "HangmanProgress.txt") {//파일에서 행맨의 단계별 출력내용을 파일에서 읽음
		ifstream fs(progName);
		if (fs) {
			getline(fs, progress[0]);
			for (int i = 0; i < 64; i++)
				getline(fs, progress[i]);
		}
	}

	void print() {//화면 출력 함수
		system("cls");
		cout << " Hangman Game\n";
		for (int i = 0; i < 8; i++)
			cout << '\t' << progress[nTries * 8 + i] << endl;
		cout << "\n\t" << answer;
		cout << "\n\n" << guessed;
	}
	int countMatched(char ch) {
		int nMatched = 0;
		for (int pos = -1;;) {
			pos = problem.find(ch, pos + 1);
			if (pos < 0)break;
			answer[pos] = ch;
			nMatched++;
		}
		return nMatched;
	}
	void guess() {
		char ch = _getch();
		if (ch >= 'a' && ch <= 'z') {
			int pos = guessed.find(ch);
			if (pos <= 0) {
				guessed[ch - 'a'] = ch;
				if (countMatched(ch) == 0)nTries++;
			}
		}

	}
public:
	void play(string prob) {
		load();
		problem = prob;
		answer = string(problem.length(), '-');
		guessed = string(24, '.');
		nTries = 0;
		while (nTries < maxTries && answer != problem) {
			print();
			guess();
		}
		print();
		cout << "\n\t" << ((nTries == maxTries) ? "Fail!!" : "Correct") << endl;
	}
};


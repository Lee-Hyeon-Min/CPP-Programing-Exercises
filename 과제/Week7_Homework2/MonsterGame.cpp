#include "MonsterWorld.h"
#include <time.h>

int main()
{
	srand((unsigned)time(NULL));
	int w = 16, h = 8;

	MonsterWorld game(w, h);
	Monster m("����", "��", rand() % w, rand() % h);
	Monster a("��", "��", rand() % w, rand() % h);
	Monster b("��", "��", rand() % w, rand() % h);
	Monster c("��", "��", rand() % w, rand() % h);
	game.add(m);
	game.add(a);
	game.add(b);
	game.add(c);

	game.play(500, 10);
}
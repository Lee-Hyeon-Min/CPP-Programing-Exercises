#include "MonsterWorld.h"
#include <time.h>

int main()
{
	srand((unsigned)time(NULL));
	int w = 16, h = 8;

	MonsterWorld game(w, h);
	Monster m("몬스터", "※", rand() % w, rand() % h);
	Monster a("가", "★", rand() % w, rand() % h);
	Monster b("나", "☆", rand() % w, rand() % h);
	Monster c("다", "○", rand() % w, rand() % h);
	game.add(m);
	game.add(a);
	game.add(b);
	game.add(c);

	game.play(500, 10);
}
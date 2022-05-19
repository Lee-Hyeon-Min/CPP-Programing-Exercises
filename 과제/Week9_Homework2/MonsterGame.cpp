#include "MonsterWorld.h"
#include "VariousMonsters.h"

void main()
{
	srand((unsigned int)time(NULL));
	int w = 16, h = 8;
	MonsterWorld game(w, h);
	game.add(new Zombie("ÇãÁ¢ÇÑÁ»ºñ", "¡Ý", rand() % w, rand() % h));
	game.add(new Vampire("¹ìÆÄÀÌ¾îÂ¯", "¡Ú", rand() % w, rand() % h));
	game.add(new KGhost("¾îÂ¼´Ù±Í½Å", "¢¾", rand() % w, rand() % h));
	game.add(new Jiangshi("¸ø¸Ô¾îµµ°í", "¡ê", rand() % w, rand() % h, true));
	game.add(new Jiangshi("¸ø¸Ô¾î¼¼·Î", "¢Õ", rand() % w, rand() % h, false));
	game.add(new Smombi("½º¸öºñ", "¢Ó", rand() % w, rand() % h));
	game.add(new Creature("¾Ö¹ú·¹", "¡Ù", rand() % w, rand() % h));
	game.add(new Siangshi("¸ø¸Ô´Â°¡·Î", "¡ß", rand() % w, rand() % h, false));
	game.add(new Siangshi("¸ø¸Ô´Â¼¼·Î", "¡Þ", rand() % w, rand() % h, true));
	game.play(500, 10);
	printf("------°ÔÀÓ Á¾·á-------------------\n");
}
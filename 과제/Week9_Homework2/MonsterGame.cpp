#include "MonsterWorld.h"
#include "VariousMonsters.h"

void main()
{
	srand((unsigned int)time(NULL));
	int w = 16, h = 8;
	MonsterWorld game(w, h);
	game.add(new Zombie("����������", "��", rand() % w, rand() % h));
	game.add(new Vampire("�����̾�¯", "��", rand() % w, rand() % h));
	game.add(new KGhost("��¼�ٱͽ�", "��", rand() % w, rand() % h));
	game.add(new Jiangshi("���Ծ��", "��", rand() % w, rand() % h, true));
	game.add(new Jiangshi("���Ծ��", "��", rand() % w, rand() % h, false));
	game.add(new Smombi("������", "��", rand() % w, rand() % h));
	game.add(new Creature("�ֹ���", "��", rand() % w, rand() % h));
	game.add(new Siangshi("���Դ°���", "��", rand() % w, rand() % h, false));
	game.add(new Siangshi("���Դ¼���", "��", rand() % w, rand() % h, true));
	game.play(500, 10);
	printf("------���� ����-------------------\n");
}
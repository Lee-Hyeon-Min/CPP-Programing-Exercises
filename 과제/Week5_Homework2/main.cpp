#include "mine.h"

int nx, ny;

int main()
{
	printf("������ ����: ");
	scanf_s("%d", &nx);
	printf("������ ����: ");
	scanf_s("%d", &ny);
	printf("\n");
	int total;
	printf("�ż��� �� ������ ����: ");
	scanf_s("%d", &total);
	playMineSweeper(total);

}
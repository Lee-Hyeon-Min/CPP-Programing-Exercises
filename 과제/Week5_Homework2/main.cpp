#include "mine.h"

int nx, ny;

int main()
{
	printf("가로의 길이: ");
	scanf_s("%d", &nx);
	printf("세로의 길이: ");
	scanf_s("%d", &ny);
	printf("\n");
	int total;
	printf("매설할 총 지뢰의 갯수: ");
	scanf_s("%d", &total);
	playMineSweeper(total);

}
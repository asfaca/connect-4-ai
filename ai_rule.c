#include "ai_header.h"

int decide_win_or_lose_or_continue(int **map)
{
	int i, k;
	for (i = 0; i < 6; i++)
	{
		for (k = 0; k < 4; k++)
		{
			if (map[i][k] == 1 && map[i][k + 1] == 1 && map[i][k + 2] == 1 && map[i][k + 3] == 1)
				return USERWIN;
			if (map[i][k] == 2 && map[i][k + 1] == 2 && map[i][k + 2] == 2 && map[i][k + 3] == 2)
				return AIWIN;
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (k = 0; k < 7; k++)
		{
			if (map[i][k] == 1 && map[i + 1][k] == 1 && map[i + 2][k] == 1 && map[i + 3][k] == 1)
				return USERWIN;
			if (map[i][k] == 2 && map[i + 1][k] == 2 && map[i + 2][k] == 2 && map[i + 3][k] == 2)
				return AIWIN;
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (k = 0; k < 4; k++)
		{
			if (map[i][k] == 1 && map[i + 1][k + 1] == 1 && map[i + 2][k + 2] == 1 && map[i + 3][k + 3] == 1)
				return USERWIN;
			if (map[i][k] == 2 && map[i + 1][k + 1] == 2 && map[i + 2][k + 2] == 2 && map[i + 3][k + 3] == 2)
				return AIWIN;
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (k = 0; k < 4; k++)
		{
			if (map[i + 3][k] == 1 && map[i + 2][k + 1] == 1 && map[i + 1][k + 2] == 1 && map[i][k + 3] == 1)
				return USERWIN;
			if (map[i + 3][k] == 2 && map[i + 2][k + 1] == 2 && map[i + 1][k + 2] == 2 && map[i][k + 3] == 2)
				return AIWIN;
		}
	}

	return CONTINUE;
}

void print_map(int **map)
{
	int i, k, j;
	printf("\n");
	for (i = 5; i >= 0 ; i--)
	{
		printf("%d  ", j = i + 1);
		for (k = 0; k < 7; k++)
		{
			if (map[i][k] == 1)
				printf("@  ");
			else if (map[i][k] == 2)
				printf("O  ");
			else
				printf("   ");
			
		}
		printf("\n");
	}
	printf("   -  -  -  -  -  -  -  \n");
	printf("   1  2  3  4  5  6  7  \n");
}
#include "ai_header.h"

void ai_rule_function(int **map)
{

}

int decide_win_or_lose_or_continue(int **map)
{
	int i, k;
	for (i = 0; i < 6; i++)
	{
		for (k = 0; k < 4; k++)
		{
			if (map[i][k] == 1 && map[i][k + 1] == 1 && map[i][k + 2] == 1 && map[i][k + 3] == 1)
				return 1;
			if (map[i][k] == 2 && map[i][k + 1] == 2 && map[i][k + 2] == 2 && map[i][k + 3] == 2)
				return 2;
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (k = 0; k < 7; k++)
		{
			if (map[i][k] == 1 && map[i + 1][k] == 1 && map[i + 2][k] == 1 && map[i + 3][k] == 1)
				return 1;
			if (map[i][k] == 2 && map[i + 1][k] == 2 && map[i + 2][k] == 2 && map[i + 3][k] == 2)
				return 2;
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (k = 0; k < 4; k++)
		{
			if (map[i][k] == 1 && map[i + 1][k + 1] == 1 && map[i + 2][k + 2] == 1 && map[i + 3][k + 3] == 1)
				return 1;
			if (map[i][k] == 2 && map[i + 1][k + 1] == 2 && map[i + 2][k + 2] == 2 && map[i + 3][k + 3] == 2)
				return 2;
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (k = 0; k < 4; k++)
		{
			if (map[i + 3][k] == 1 && map[i + 2][k + 1] == 1 && map[i + 1][k + 2] == 1 && map[i][k + 3] == 1)
				return 1;
			if (map[i + 3][k] == 2 && map[i + 2][k + 1] == 2 && map[i + 1][k + 2] == 2 && map[i][k + 3] == 2)
				return 2;
		}
	}

	return 0;
}

void print_map(int **map)
{
	int i, k;
	for (i = 5; i >= 0 ; i--)
	{
		for (k = 0; k < 7; k++)
		{
			printf("%3d", map[i][k]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
}
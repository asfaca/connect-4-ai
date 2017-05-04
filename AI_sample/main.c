#include "ai_header.h"

int main(void)
{
	//Uusr = 1
	//AI = 2
	//Empty = 0
	int **map = NULL;
	int i, k;
	map = (int**)malloc(sizeof(int*) * 6);
	for (i = 0; i < 6; i++)
	{
		map[i] = (int*)malloc(sizeof(int) * 7);
	}
	for (i = 0; i < 6; i++)
	{
		for (k = 0; k < 7; k++)
			map[i][k] = 0;
	}
	int decide_exit = 100;
	int first;
	int select_ai_search_or_rule;
	int user_turn_x, user_turn_y;

	printf("Who start first? 1 -> user 2 -> AI\n");
	scanf("%d", &first);
	print_map(map);

	if (first == 1)
	{
		while (1)
		{
			
			printf("inert location x y : ");
			scanf("%d%d", &user_turn_x, &user_turn_y);

			map[user_turn_y - 1][user_turn_x - 1] = 1;
			print_map(map);

			decide_exit = decide_win_or_lose_or_continue(map);

			if (decide_exit == 1)
			{
				printf("User Win!\n");
				return 0;
			}
			else if (decide_exit == 2)
			{
				printf("AI Win!\n");
				return 0;
			}

			printf("Select which ai version to use. search algorithm = 1, rule =2\n");
			scanf("%d", &select_ai_search_or_rule);

			if (select_ai_search_or_rule == 1)
				ai_search_function(map);
			else if (select_ai_search_or_rule == 2)
				ai_rule_function(map);
			print_map(map);

			decide_exit = decide_win_or_lose_or_continue(map);

			if (decide_exit == 1)
			{
				printf("User Win!\n");
				return 0;
			}
			else if (decide_exit == 2)
			{
				printf("AI Win!\n");
				return 0;
			}
		}
	}
	else if (first == 2)
	{
		while (1)
		{
			print_map(map);
			printf("Select which ai version to use. search algorithm = 1, rule =2\n");
			scanf("%d", &select_ai_search_or_rule);

			if (select_ai_search_or_rule == 1)
				ai_search_function(map);
			else if (select_ai_search_or_rule == 2)
				ai_rule_function(map);

			print_map(map);

			decide_exit = decide_win_or_lose_or_continue(map);

			if (decide_exit == 1)
			{
				printf("User Win!\n");
				return 0;
			}
			else if (decide_exit == 2)
			{
				printf("AI Win!\n");
				return 0;
			}

			printf("inert location x y : ");
			scanf("%d%d", &user_turn_x, &user_turn_y);

			map[user_turn_y - 1][user_turn_x - 1] = 1;

			print_map(map);

			decide_exit = decide_win_or_lose_or_continue(map);

			if (decide_exit == 1)
			{
				printf("User Win!\n");
				return 0;
			}
			else if (decide_exit == 2)
			{
				printf("AI Win!\n");
				return 0;
			}
		}
	}

	return 0;
}
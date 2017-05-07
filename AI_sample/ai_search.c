#include "ai_header.h"

void ai_search_function(int **map)
{
	struct tree_node *root = NULL;
	//Make full tree untill depth 3
	root = make_full_tree(map);	

	min_max_function(root);  //min_max_function internally includes evaluation_function.

	select_map(map, pick_next_map(root));

	free_tree(root);

	return 0;
}


struct tree_node* make_full_tree(int **map)
{
	//root = max
	//1 = min
	//2 = max
	//3 = min (leaf if depth3)
	//4 = max (leaf if depth4)
	int i, k, j, z, w;
	struct tree_node *temp = NULL, *temp2 = NULL, *temp3 = NULL, *temp4 = NULL, *temp5 = NULL;
	struct tree_node *root = create_node(map, TRUE, FALSE, MAX);
	insert_child(root, MIN);
	temp = root->child1;


	
	for (i = 0; i < 7; i++)
	{
		insert_child(temp, MAX);
		temp2 = temp->child1;
		for (k = 0; k < 7; k++)
		{
#ifdef DEPTH3
			insert_child(temp2, LEAF);
			temp2 = temp2->next_sibling;
#endif // DEPTH3

#ifdef DEPTH4
			insert_child(temp2, MIN);
			temp3 = temp2->child1;
			for (j = 0; j < 7; j++)
			{
				insert_child(temp3, LEAF);
				temp3 = temp3->next_sibling;
			}
			temp2 = temp2->next_sibling;
#endif // DEPTH4

#ifdef DEPTH5
			insert_child(temp2, MIN);
			temp3 = temp2->child1;
			for (j = 0; j < 7; j++)
			{
				insert_child(temp3, MAX);
				temp4 = temp3->child1;
				for (z = 0; z < 7; z++)
				{
					insert_child(temp4, LEAF);
					temp4 = temp4->next_sibling;
				}
				temp3 = temp3->next_sibling;
			}
			temp2 = temp2->next_sibling;
#endif // DEPTH5

#ifdef DEPTH6
			insert_child(temp2, MIN);
			temp3 = temp2->child1;
			for (j = 0; j < 7; j++)
			{
				insert_child(temp3, MAX);
				temp4 = temp3->child1;
				for (z = 0; z < 7; z++)
				{
					insert_child(temp4, MIN);
					temp5 = temp4->child1;
					for (w = 0; w < 7; w++)
					{
						insert_child(temp5, LEAF);
						temp5 = temp5->next_sibling;
					}
					temp4 = temp4->next_sibling;
				}
				temp3 = temp3->next_sibling;
			}
			temp2 = temp2->next_sibling;
#endif // DEPTH6
		}
		temp = temp->next_sibling;
	}
	
	return root;
}

//count most winning line
void evaluation_function_version_1(struct tree_node *node)
{
	node->evaluation_value = 0;
	int i, k;
	int **map = node->map;
	if (decide_win_or_lose_or_continue(map) == USERWIN)
	{
		node->evaluation_value = -9999;
		return;
	}
	else if (decide_win_or_lose_or_continue(map) == AIWIN)
	{
		node->evaluation_value = 9999;
		return;
	}
	else
	{
		//2 point for 2 consecutive stones
		for (i = 0; i < 6; i++)
		{
			for (k = 0; k < 5; k++)
			{
				if (map[i][k] == 0 && map[i][k + 1] == 1 && map[i][k + 2] == 1)
					node->evaluation_value -= 2;
				if (map[i][k] == 1 && map[i][k + 1] == 1 && map[i][k + 2] == 0)
					node->evaluation_value -= 2;
				if (map[i][k] == 0 && map[i][k + 1] == 2 && map[i][k + 2] == 2)
					node->evaluation_value += 2;
				if (map[i][k] == 2 && map[i][k + 1] == 2 && map[i][k + 2] == 0)
					node->evaluation_value += 2;
			}
		}
		for (i = 0; i < 4; i++)
		{
			for (k = 0; k < 7; k++)
			{
				if (map[i][k] == 1 && map[i + 1][k] == 1 && map[i + 2][k] == 0)
					node->evaluation_value -= 2;
				if (map[i][k] == 0 && map[i + 1][k] == 1 && map[i + 2][k] == 1)
					node->evaluation_value -= 2;
				if (map[i][k] == 2 && map[i + 1][k] == 2 && map[i + 2][k] == 0)
					node->evaluation_value += 2;
				if (map[i][k] == 0 && map[i + 1][k] == 2 && map[i + 2][k] == 2)
					node->evaluation_value += 2;
			}
		}
		for (i = 0; i < 4; i++)
		{
			for (k = 0; k < 5; k++)
			{
				if (map[i][k] == 1 && map[i + 1][k + 1] == 1 && map[i + 2][k + 2] == 0)
					node->evaluation_value -= 2;
				if (map[i][k] == 0 && map[i + 1][k + 1] == 1 && map[i + 2][k + 2] == 1)
					node->evaluation_value -= 2;
				if (map[i][k] == 2 && map[i + 1][k + 1] == 2 && map[i + 2][k + 2] == 0)
					node->evaluation_value += 2;
				if (map[i][k] == 0 && map[i + 1][k + 1] == 2 && map[i + 2][k + 2] == 2)
					node->evaluation_value += 2;

				if (map[i + 2][k] == 1 && map[i + 1][k + 1] == 1 && map[i][k + 2] == 0)
					node->evaluation_value -= 2;
				if (map[i + 2][k] == 0 && map[i + 1][k + 1] == 1 && map[i][k + 2] == 1)
					node->evaluation_value -= 2;
				if (map[i + 2][k] == 2 && map[i + 1][k + 1] == 2 && map[i][k + 2] == 0)
					node->evaluation_value += 2;
				if (map[i + 2][k] == 0 && map[i + 1][k + 1] == 2 && map[i][k + 2] == 2)
					node->evaluation_value += 2;
			}
		}
		//4 point for 3 consecutive stones
		for (i = 0; i < 6; i++)
		{
			for (k = 0; k < 4; k++)
			{
				if (map[i][k] == 1 && map[i][k + 1] == 1 && map[i][k + 2] == 1 && map[i][k + 3] == 0)
					node->evaluation_value -= 4;
				if (map[i][k] == 0 && map[i][k + 1] == 1 && map[i][k + 2] == 1 && map[i][k + 3] == 1)
					node->evaluation_value -= 4;
				if (map[i][k] == 2 && map[i][k + 1] == 2 && map[i][k + 2] == 2 && map[i][k + 3] == 0)
					node->evaluation_value += 4;
				if (map[i][k] == 0 && map[i][k + 1] == 2 && map[i][k + 2] == 2 && map[i][k + 3] == 2)
					node->evaluation_value += 4;
			}
		}
		for (i = 0; i < 3; i++)
		{
			for (k = 0; k < 7; k++)
			{
				if (map[i][k] == 1 && map[i + 1][k] == 1 && map[i + 2][k] == 1 && map[i + 3][k] == 0)
					node->evaluation_value -= 4;
				if (map[i][k] == 0 && map[i + 1][k] == 1 && map[i + 2][k] == 1 && map[i + 3][k] == 1)
					node->evaluation_value -= 4;
				if (map[i][k] == 2 && map[i + 1][k] == 2 && map[i + 2][k] == 2 && map[i + 3][k] == 0)
					node->evaluation_value += 4;
				if (map[i][k] == 0 && map[i + 1][k] == 2 && map[i + 2][k] == 2 && map[i + 3][k] == 2)
					node->evaluation_value += 4;
			}
		}
		for (i = 0; i < 3; i++)
		{
			for (k = 0; k < 4; k++)
			{
				if (map[i][k] == 1 && map[i + 1][k + 1] == 1 && map[i + 2][k + 1] == 1 && map[i + 3][k + 3] == 0)
					node->evaluation_value -= 4;
				if (map[i][k] == 0 && map[i + 1][k + 1] == 1 && map[i + 2][k + 1] == 1 && map[i + 3][k + 3] == 1)
					node->evaluation_value -= 4;
				if (map[i][k] == 2 && map[i + 1][k + 1] == 2 && map[i + 2][k + 1] == 2 && map[i + 3][k + 3] == 0)
					node->evaluation_value += 4;
				if (map[i][k] == 0 && map[i + 1][k + 1] == 2 && map[i + 2][k + 1] == 2 && map[i + 3][k + 3] == 2)
					node->evaluation_value += 4;

				if (map[i + 3][k] == 1 && map[i + 2][k + 1] == 1 && map[i + 1][k + 2] == 1 && map[i][k + 3] == 0)
					node->evaluation_value -= 4;
				if (map[i + 3][k] == 0 && map[i + 2][k + 1] == 1 && map[i + 1][k + 2] == 1 && map[i][k + 3] == 1)
					node->evaluation_value -= 4;
				if (map[i + 3][k] == 2 && map[i + 2][k + 1] == 2 && map[i + 1][k + 2] == 2 && map[i][k + 3] == 0)
					node->evaluation_value += 4;
				if (map[i + 3][k] == 0 && map[i + 2][k + 1] == 2 && map[i + 1][k + 2] == 2 && map[i][k + 3] == 2)
					node->evaluation_value += 4;
			}
		}
	}
}

void min_max_function(struct tree_node *node)
{
	if (node->min_or_max_or_leaf == LEAF&&node->is_in_tree == TRUE)
	{
		evaluation_function_version_1(node);
		return;
	}
	if (node->is_in_tree == FALSE)
		return;
	min_max_function(node->child1);
	min_max_function(node->child2);
	min_max_function(node->child3);
	min_max_function(node->child4);
	min_max_function(node->child5);
	min_max_function(node->child6);
	min_max_function(node->child7);

	struct tree_node *curr = node->child1;

	if (node->min_or_max_or_leaf == MAX)
	{
		int i, max = -9999;
		for (i = 0; i < 7; i++)
		{
			if (curr->is_in_tree == TRUE)
			{
				if (curr->evaluation_value > max)
					max = curr->evaluation_value;
			}
			curr = curr->next_sibling;
		}
		node->evaluation_value = max;
		return;
	}
	else if (node->min_or_max_or_leaf == MIN)
	{
		int i, min = 9999;
		for (i = 0; i < 7; i++)
		{
			if (curr->is_in_tree == TRUE)
			{
				if (curr->evaluation_value < min)
					min = curr->evaluation_value;
			}
			curr = curr->next_sibling;
		}
		node->evaluation_value = min;
		return;
	}
}

int pick_next_map(struct tree_node *root)
{
	int i;
	struct tree_node *curr = root->child1;
	for (i = 0; i < 7; i++)
	{
		if (curr->is_in_tree == TRUE)
		{
			if (root->evaluation_value == curr->evaluation_value)
				return i;
			else
				curr = curr->next_sibling;
		}
		else
			curr = curr->next_sibling;
	}
}

void select_map(int **map, int pick_next)
{
	int i, result;
	for (i = 0; i < 6; i++)
	{
		if (map[i][pick_next] == 0)
		{
			map[i][pick_next] = 2;
			return;
		}
	}
}

void free_tree(struct tree_node *root)
{
	int i;
	struct tree_node *curr = root->child1;
	struct tree_node *temp = NULL;
	for (i = 0; i < 7; i++)
	{
		temp = curr->next_sibling;
		mem_free_tree(curr);
		curr = temp;
	}
	free(root);
}
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
	//3 = leaf
	int i, k;
	struct tree_node *temp = NULL, *temp2 = NULL;
	struct tree_node *root = create_node(map, TRUE, FALSE, MAX);
	insert_child(root, MIN);
	temp = root->child1;
	for (i = 0; i < 7; i++)
	{
		insert_child(temp, MAX);
		temp2 = temp->child1;
		for (k = 0; k < 7; k++)
		{
			insert_child(temp2, LEAF);
			temp2 = temp2->next_sibling;
		}
		temp = temp->next_sibling;
	}
	return root;
}

//count most winning line
void evaluation_function_version_1(struct tree_node *node)
{
	node->evaluation_value = rand()%20;
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
	}
}

int pick_next_map(struct tree_node *root)
{
	int pick_number = 0;
	int i;
	struct tree_node *curr = root->child1;
	for (i = 0; i < 7; i++)
	{
		if (curr->is_in_tree == TRUE)
		{
			if (root->evaluation_value == curr->evaluation_value)
				return pick_number;
			else
			{
				curr = curr->next_sibling;
				pick_number++;
			}
		}
		else
		{
			curr = curr->next_sibling;
			pick_number++;
		}
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
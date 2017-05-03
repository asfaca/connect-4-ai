#include "ai_header.h"

void ai_search_function(int map[][7])
{
	struct tree_node *root = NULL;
	//Make full tree untill depth 3
	root = make_full_tree(map);	

	min_max_function(root);  //min_max_function internally includes evaluation_function.

	select_map(map);

	mem_free_tree(root);


	return 0;
}


struct tree_node* make_full_tree(int map[][7])
{
	
}

//count most winning line
void evaluation_function_version_1(struct tree_node *node)
{
	node->evaluation_value = 0;
	
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

void select_map(int map[][7])
{

}
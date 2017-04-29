#include "ai_header.h"

void ai_search_function(int map[][7])
{
	struct tree_node *root = NULL;
	//Make full tree untill depth 3
	root = make_full_tree(map);	

	int select = min_max_function(root);  //min_max_function internally includes evaluation_function.

	mem_free_tree(root);

	select_map(map, select);

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

int min_max_function(struct tree_node *node)
{

}

void select_map(int map[][7], int select)
{

}
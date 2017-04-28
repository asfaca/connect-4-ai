#include "ai_header.h"

struct tree_node* create_root_node(int map[][7])
{
	struct tree_node *root = (struct tree_node*)malloc(sizeof(struct tree_node));
	if (root = NULL)
		return NULL;

	root->map = map;
	root->evaluation_value = -1;	//default value
	root->child1 = NULL;
	root->child2 = NULL;
	root->child3 = NULL;
	root->child4 = NULL;
	root->child5 = NULL;
	root->child6 = NULL;
	root->child7 = NULL;

	return root;
}

void insert_child(struct tree_node *root, int child_map1[][7],
					 int child_map2[][7], int child_map3[][7],
					 int child_map4[][7], int child_map5[][7],
					 int child_map6[][7], int child_map7[][7])
{

}

void mem_free_tree(struct tree_node *root)
{

}
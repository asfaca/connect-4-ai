#include "ai_header.h"

struct tree_node* create_node(int map[][7])
{
	struct tree_node *node = (struct tree_node*)malloc(sizeof(struct tree_node));
	if (node = NULL)
		return NULL;

	node->map = map;
	node->evaluation_value = -1;	//default value
	node->child1 = NULL;
	node->child2 = NULL;
	node->child3 = NULL;
	node->child4 = NULL;
	node->child5 = NULL;
	node->child6 = NULL;
	node->child7 = NULL;
	
	return node;
}

/*i made tree structure function - create_node, insert_child.
In insert_child function, it automatically creates nodes, 
makes maps and inerts it into child nodes so you do not need to make child map using malloc.
you can make all 7 child nodes just uning insert_child function passing only argument as root node
But it can have child node as NULL when child can not have a place to put stone any more*/
void insert_child(struct tree_node *root)
{
	int result;

	int **child_map1 = duplicate_root_map(root->map);
	int **child_map2 = duplicate_root_map(root->map);
	int **child_map3 = duplicate_root_map(root->map);
	int **child_map4 = duplicate_root_map(root->map);
	int **child_map5 = duplicate_root_map(root->map);
	int **child_map6 = duplicate_root_map(root->map);
	int **child_map7 = duplicate_root_map(root->map);

	result = modify_child_map(child_map1, 1);
	if (result == 1)
		root->child1 = create_node(child_map1);
	else     //it can not move because vertical row is full so free memory and maintain null in child pointer of root node
		free_map(child_map1);
	
	result = modify_child_map(child_map2, 2);
	if (result == 1)
		root->child1 = create_node(child_map2);
	else
		free_map(child_map2);
	
	result = modify_child_map(child_map3, 3);
	if (result == 1)
		root->child1 = create_node(child_map3);
	else
		free_map(child_map3);
	
	result = modify_child_map(child_map4, 4);
	if (result == 1)
		root->child1 = create_node(child_map4);
	else
		free_map(child_map4);
	
	result = modify_child_map(child_map5, 5);
	if (result == 1)
		root->child1 = create_node(child_map5);
	else
		free_map(child_map5);
	
	result = modify_child_map(child_map6, 6);
	if (result == 1)
		root->child1 = create_node(child_map6);
	else
		free_map(child_map6);
	
	result = modify_child_map(child_map7, 7);
	if (result == 1)
		root->child1 = create_node(child_map7);
	else
		free_map(child_map7);
}

int** duplicate_root_map(int **root_map)
{
	int **child_map = (int**)malloc(sizeof(int*) * 6);
	int i, k;
	for (i = 0; i < 6; i++)
		child_map[i] = (int*)malloc(sizeof(int) * 7);
	
	for (i = 0; i < 6; i++)
	{
		for (k = 0; k < 7; k++)
		{
			child_map[i][k] = root_map[i][k];
		}
	}
	return child_map;
}

int modify_child_map(int **child_map, int number)
{
	number--;
	int i;
	for (i = 0; i < 6; i++)
	{
		if (child_map[i][number] == 0)
		{
			child_map[i][number] = 2;
			//it can move and retun 1 as success
			return 1;
		}
		if (i == 5)
		{
			/*it can not move because vertical row is full 
			  so return 0 as fail and do not make map 
			  (free map in upper function and maintain NULL in child pointer)*/
			return 0;
		}
	}
}

void mem_free_tree(struct tree_node *root)
{

}

void free_map(int **map)
{
	int i;
	for (i = 0; i < 6; i++)
	{
		free(map[i]);
	}
	free(map);
}
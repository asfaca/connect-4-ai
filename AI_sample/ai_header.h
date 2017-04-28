#include <stdio.h>
#include <stdlib.h>

struct tree_node{
	int **map;				//map[6][7]
	int evaluation_value;		//default value is -1

	struct node *child1;
	struct node *child2;
	struct node *child3;
	struct node *child4;
	struct node *child5;
	struct node *child6;
	struct node *child7;
};

//Search algorithm.
void ai_search_function(int map[][7]);
struct tree_node* make_full_tree(int map[][7]);
void evaluation_function(struct tree_node *node);
int min_max_function(struct tree_node *node);
void select_map(int map[][7], int select);

//Rule algorithm.
void ai_rule_function(int map[][7]);

//Decide win, lose or continue
//0 -> continue
//1 -> user win
//2 -> ai win
int decide_win_or_lose_or_continue(int map[][7]);

//Tree sturcture functions
struct tree_node* create_root_node(int map[][7]);//need to fix arguments child to int map[][]
void insert_child(struct tree_node *root, int child_map1[][7],
					 int child_map2[][7], int child_map3[][7],
					 int child_map4[][7] , int child_map5[][7],
					 int child_map6[][7], int child_map7[][7]);
void mem_free_tree(struct tree_node *root);
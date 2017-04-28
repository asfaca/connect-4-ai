#include <stdio.h>
#include <stdlib.h>

struct tree_node{
	int **map;				//map[6][7]
	int evaluation_value;		//default value is -1
	
	struct tree_node *child1;
	struct tree_node *child2;
	struct tree_node *child3;
	struct tree_node *child4;
	struct tree_node *child5;
	struct tree_node *child6;
	struct tree_node *child7;
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
struct tree_node* create_node(int map[][7]);//need to fix arguments child to int map[][]
void insert_child(struct tree_node *root);
void mem_free_tree(struct tree_node *root);
void free_map(int **map);
int** duplicate_root_map(int **root_map);
int modify_child_map(int **child_map, int number);
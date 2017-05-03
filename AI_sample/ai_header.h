#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MIN 0
#define MAX 1
#define LEAF 2
#define CONTINUE 0
#define WIN 1
#define LOSE 2

struct tree_node{
	int **map;				//map[6][7]
	int evaluation_value;		//default value is -999
	int is_in_tree;
	int is_it_winorlose;
	int min_or_max_or_leaf;			//Use in min_max_function( ) for parent node to choose either min value or max value among child nodes
									//define MIN 0 ,MAX 1, LEAF 2.  if this value is LEAF, apply eavaluation function to node
	struct tree_node *child1;
	struct tree_node *child2;
	struct tree_node *child3;
	struct tree_node *child4;
	struct tree_node *child5;
	struct tree_node *child6;
	struct tree_node *child7;
	
	struct tree_node *next_sibling;
};

//Search algorithm.
void ai_search_function(int map[][7]);
struct tree_node* make_full_tree(int map[][7]);
void evaluation_function_version_1(struct tree_node *node);
void min_max_function(struct tree_node *node);
void select_map(int map[][7]);

//Rule algorithm..
void ai_rule_function(int map[][7]);

//Decide win, lose or continue
//0 -> continue
//1 -> user win
//2 -> ai win
int decide_win_or_lose_or_continue(int map[][7]);

//Tree sturcture functions
struct tree_node* create_node(int map[][7], int intree, int winorlose, int minmax_or_leaf);
void insert_child(struct tree_node *root, int minmax_or_leaf);
void mem_free_tree(struct tree_node *root);
void free_map(int **map);
int** duplicate_root_map(int **root_map);
int modify_child_map(int **child_map, int number);
void connect_siblings(struct tree_node *root);
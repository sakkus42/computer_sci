#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>


typedef struct s_tree{
    int key;
    struct s_tree * left_child;
    struct s_tree * right_child;
}   t_data;

typedef struct s_queue{
    t_data *root;
    struct s_queue *next;
}   t_que;


t_data  *new_node(int key);
t_que   *new_que(t_data *tree);
void    insert_right(t_data *root, int key);
void    insert_left(t_data *root, int key);
int     height(t_data *t);
int     is_empty(t_que *q);
int     size(t_que *l);
void    push_que(t_que **q, t_data *t);

#endif

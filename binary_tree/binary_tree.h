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

t_data  *new_node(int key);
void     insert_right(t_data *root, int key);
void    insert_left(t_data *root, int key);
int     height(t_data *t);


#endif

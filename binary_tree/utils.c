#include "binary_tree.h"

t_data *new_node(int key)
{
    t_data *res = malloc(sizeof(t_data));
    res->key = key;
    res->left_child = NULL;
    res->right_child = NULL;
    return (res);
}

void insert_right(t_data *root, int key)
{
    root->right_child = new_node(key);
}

void insert_left(t_data *root, int key)
{
    root->left_child = new_node(key);
}

int height(t_data *t)
{
    if (!t) return (0);
    else{
        int r_height = height(t->right_child);
        int l_height = height(t->left_child);
        if (r_height > l_height) return (r_height + 1);
        else return (l_height + 1);
    }
}
    
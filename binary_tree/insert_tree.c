#include <stdio.h>
#include <stdlib.h>

typedef struct s_tree{
    int key;
    struct s_tree * left_child;
    struct s_tree * right_child;
}   t_data;

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

t_data *new_node(int key)
{
    t_data *res = malloc(sizeof(t_data));
    res->key = key;
    res->left_child = NULL;
    res->right_child = NULL;
    return (res);
}

void print_current_level(t_data *t, int level)
{
    if (!t)
        return ;
    if (level == 1)
        printf(" %d ", t->key);
    else if(level > 1){
        print_current_level(t->right_child, level - 1);
        print_current_level(t->left_child, level - 1);
    }
}

void print_level_order(t_data *t)
{
    int h = height(t);
    for (int i = 1; i <= h; i++)
    {
        print_current_level(t, i);
        printf("\n");
    }
}

t_data *insert_tree(int key, t_data *tree)
{
    if (tree == NULL)
        return (new_node(key));
    if (tree->key < key)
    {
        tree->right_child = insert_tree(key, tree->right_child);
    }
    else if (tree->key > key)
    {
        tree->left_child = insert_tree(key, tree->left_child);
    }
    return (tree);
}

int main()
{
    t_data *tree = new_node(25);
    insert_tree(52, tree);
    insert_tree(51, tree);
    insert_tree(53, tree);
    insert_tree(54, tree);
    insert_tree(55, tree);
    insert_tree(1, tree);
    insert_tree(2, tree);
    insert_tree(3, tree);
    insert_tree(4, tree);
    insert_tree(5, tree);
    print_level_order(tree);
}
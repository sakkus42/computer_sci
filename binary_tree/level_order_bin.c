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
        printf("%d", t->key);
    else if(level > 1){
        print_current_level(t->left_child, level - 1);
        print_current_level(t->right_child, level - 1);
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

int main()
{
    t_data *tree = new_node(1);
    tree->right_child = new_node(2);
    tree->left_child = new_node(3);
    tree->right_child->left_child = new_node(5);
    tree->right_child->right_child = new_node(4);
    tree->left_child->right_child = new_node(6);
    tree->left_child->left_child = new_node(7);

    printf("level order\n");
    print_level_order(tree);
}

/*
╰─➤  ./a.out
level order
1
32
7654
*/
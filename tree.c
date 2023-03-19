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
    
void print_tree(t_data *t, char *str)
{
    if (!t) return;
    print_tree(t->left_child, str);
    printf("%d %s", t->key, str);
}

int main(int ac, char *arv[])
{
    t_data *tree = new_node(1);
    insert_right(tree, 2);
    insert_left(tree, 3);
    insert_left(tree->left_child, 4);
    print_tree(tree->left_child, "<-");
    printf(" %d ->", tree->key);
    print_tree(tree->right_child, "->");
}

/*
╰─➤  ./a.out 
4 <-3 <- 1 ->2 ->
*/
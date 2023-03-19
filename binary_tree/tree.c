#include "binary_tree.h"
    
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct queue
{
    int val;
    struct queue *next;
} t_que;

t_que *new_struct(int val)
{
    t_que *res = malloc(sizeof(t_que));
    res->val = val;
    res->next = NULL;
    return (res);
}

int size(t_que *l)
{
    t_que *iter = l;
    if (!l)
        return (0);
    iter = iter->next;
    return (1 + size(iter));
}

void print_struct(t_que *l)
{
    t_que *iter = l;
    while (iter)
    {
        printf("%d\n", iter->val);
        sleep(1);
        iter = iter->next;
    }
}

void    delete(t_que **l)
{
    t_que *head = (*l)->next;
    free(*l);
    *l = head;
}

int main(int ac, char *arv[])
{
    if (ac == 1)
    {
        printf("missing argument\n");
        return (1);
    }
    t_que *stack = new_struct(atoi(arv[ac - 1]));
    t_que *que = new_struct(atoi(arv[1]));
    t_que *iter = que;
    int i = 2;
    while (i < ac)
    {
        iter->next = new_struct(atoi(arv[i]));
        iter = iter->next;
        i++;
    }
    iter = stack;
    i = 2;
    while (i < ac)
    {
        iter->next = new_struct(atoi(arv[ac - i]));
        iter = iter->next;
        i++;
    }
    printf("QUEUE\n");
    print_struct(que);
    printf("STACK\n");
    print_struct(stack);
    delete(&stack);
    delete(&que);
    printf("QUEUE-first delete\n");
    print_struct(que);
    printf("STACK-first delete\n");
    print_struct(stack);
}

/*
./a.out 2 1 3
QUEUE
2
1
3
STACK
3
1
2
QUEUE-first delete
1
3
STACK-first delete
1
2
*/ 
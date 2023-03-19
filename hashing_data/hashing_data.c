#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct hash_data{
    int val;
    int key;
    struct hash_data *next;
} t_data;

t_data *new_struct(int val, int key)
{
    t_data *res = malloc(sizeof(t_data));
    res->val = val;
    res->key = key;
    res->next = NULL;
    return (res);
}

int size_list(t_data *l)
{
    t_data *iter = l;
    if (!l)
        return (0);
    iter = iter->next;
    return (1 + size_list(iter));
}

void print_struct(t_data *l)
{
    t_data *iter = l;
    int is = 1;
    if (!iter)
        is = 0;
    while (iter)
    {
        printf("val:    %d->", iter->val);
        iter = iter->next;
    }
    is != 0 ? printf("\n") : 0;
}

int hash_func(int val)
{
    return (val % 50);
}

void hash_cntrl_insrt(t_data *dat, int key, int val)
{
    t_data *iter = dat->next;
    t_data *head = dat;
    while (iter)
    {
        head = iter;
        iter = iter->next;
    }
    iter = new_struct(val, key);
    head->next = iter;
}

t_data *find(t_data **dat, int val)
{
    int size = size_list(dat[hash_func(val)]);
    if (size == 1 || dat[hash_func(val)]->val == val)
        return(dat[hash_func(val)]);
    t_data *iter = dat[hash_func(val)]->next;
    while (iter)
    {
        if (iter->val == val)
            return (iter);
        iter = iter->next;
    }
    return (0);
}

int main(int ac, char *arv[])
{
    if (ac == 1)
        printf("missing argument\n");
    t_data **dat = calloc(sizeof(t_data *) ,50);
    for (int i = 0; i < ac - 1; i++)
    {
        int tmp_i = hash_func(atoi(arv[i + 1]));
        if (dat[tmp_i] != 0)
            hash_cntrl_insrt(dat[tmp_i], tmp_i, atoi(arv[1 + i])); 
        else
            dat[tmp_i] = new_struct(atoi(arv[i + 1]), tmp_i);
    }
    for (int i = 0; i < 50; i++)
        print_struct(dat[i]);
    t_data *tmp = find(dat, atoi(arv[2]));
    printf("found %d searched:  %d key:     %d", atoi(arv[2]), tmp->val, tmp->key);
}

/*
╭─/computer_science  ‹main*›
╰─➤  ./a.out 51 1 11 439 429 411 406 393 351 320 314 295 259 197 146 141 134 118 100 36 26 23 10
val:    100->
val:    51->val:    1->val:    351->
val:    406->
val:    259->
val:    10->
val:    11->val:    411->
val:    314->
val:    118->
val:    320->
val:    23->
val:    26->
val:    429->
val:    134->
val:    36->
val:    439->
val:    141->
val:    393->
val:    295->
val:    146->
val:    197->
found 1 searched:  1 key:     1%   
*/

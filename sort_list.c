#include <stdio.h>
#include <stdlib.h>

typedef struct s_list t_list;

struct s_list
{
	int     data;
	t_list  *next;
};

void    ft_swap(t_list *a, t_list *b)
{
    int tmp;
    tmp = a->data;
    a->data = b->data;
    b->data = tmp;
}

t_list  *sort_list(t_list* lst, int (*cmp)(int, int))
{
    t_list *cur = lst;
    int swap = 1;

    while(swap == 1)
    {
        swap = 0;
        while(cur != 0 && cur->next != 0)
        {
        if (cmp(cur->data, cur->next->data) == 0)
        {
            ft_swap(cur, cur->next);
            swap = 1;
        }
        cur = cur->next;
        
        }
        cur = lst;
    }
    return(lst);
}

int ascending(int a, int b)
{
 return (a <= b);
}
 
int  main(void)
{
 t_list *c = malloc(sizeof(t_list));
 c->next = 0;
 c->data = 45;
 
 t_list *b = malloc(sizeof(t_list));
 b->next = c;
 b->data = 73;
 
 t_list *a = malloc(sizeof(t_list));
 a->next = b;
 a->data = 108;
 
 t_list *cur = a;
 while (cur)
 {
     printf("%d, ", cur->data);
     cur = cur->next;
 }
 printf("\n");
 
 cur = sort_list(a, ascending);
 
 cur = a;
 while (cur)
 {
     printf("%d, ", cur->data);
     cur = cur->next;
 }
 printf("\n");
}

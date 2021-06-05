
#include "push_swap.h"

void    ft_clear(t_push *ps)
{
    t_stack *tmp;

    while (ps->stack_a)
    {
        tmp = ps->stack_a;
        ps->stack_a = ps->stack_a->next;
        free(tmp);
    }
    while (ps->stack_b)
    {
        tmp = ps->stack_b;
        ps->stack_b = ps->stack_b->next;
        free(tmp);
    }
}

void	free_spliter(char **spliter)
{
	int	i;

	i = 0;
	while (spliter[i])
	{
		free(spliter[i]);
		i++;
	}
	free(spliter);
}
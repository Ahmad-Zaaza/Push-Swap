#include "../../includes/push_swap.h"

long int	get_min(t_stack *stack)
{
	long int	min;
	t_stack		**top;
	t_stack		*tmp;

	top = &stack;
	tmp = *top;
	min = tmp->data;
	while (tmp)
	{
		if (tmp->data < min)
		{
			min = tmp->data;
		}
		if (tmp->next == *top)
			break ;
		tmp = tmp->next;
	}
	return (min);
}

long int	get_max(t_stack *stack)
{
	long int	max;
	t_stack		**top;
	t_stack		*tmp;

	top = &stack;
	tmp = *top;
	max = tmp->data;
	while (tmp)
	{
		if (tmp->data > max)
		{
			max = tmp->data;
		}
		if (tmp->next == *top)
			break ;
		tmp = tmp->next;
	}
	return (max);
}

int	is_rotate(t_stack *stack)
{
	t_stack **top;
	t_stack *tmp;
	int min;
	int index;
	int min_index;

	top = &stack;
	tmp = *top;
	min = tmp->data;
	index = 0;
	min_index = 0;
	while (tmp)
	{
		if (tmp->data < min)
		{
			min_index = index;
			min = tmp->data;
		}
		if (tmp->next == *top)
			break ;
		index++;
		tmp = tmp->next;
	}
	return ((min_index + 1) <= get_stack_size(stack) / 2 ? 1 : 0);
}
#include "../../includes/push_swap.h"

int	get_num_args(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// checks if the string only contains digits and optional sign
int	is_str_digit(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	cleanup_splitted(char **str, int size)
{
	while (size > 0)
	{
		free(str[size - 1]);
		size--;
	}
	free(str);
}

int	is_queue_sorted(t_args_queue *queue)
{
	t_arg_node *tmp;
	tmp = queue->head;
	while (tmp->next)
	{
		if (tmp->value < tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	cleanup_queue(queue);
	return (1);
}
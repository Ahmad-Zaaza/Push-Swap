/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 00:46:23 by ahmadzaaza        #+#    #+#             */
/*   Updated: 2023/10/22 13:24:45 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (i > 11)
		return (0);
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
	t_arg_node	*tmp;

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

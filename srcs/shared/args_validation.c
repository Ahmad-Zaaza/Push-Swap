/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 00:46:52 by ahmadzaaza        #+#    #+#             */
/*   Updated: 2023/10/18 00:47:48 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	check_duplicates(t_frame *frame)
{
	t_arg_node	*tmp;
	t_arg_node	*tmp2;

	tmp = frame->args_queue.head;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->value == tmp2->value)
				return (0);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

// checks against maximum and minimum integer values and enqueues the value
static int	validate_and_populate_str(char *str, t_frame *frame)
{
	long int	value;

	if (!is_str_digit(str))
		return (0);
	value = ft_atoi(str);
	if (value > INT_MAX || value < INT_MIN)
		return (0);
	enqueue(frame, value);
	return (1);
}

static void	check_args(int size, char **str, t_frame *frame, int cleanup)
{
	int	i;
	int	success;

	i = size - 1;
	success = 1;
	if (size < 1)
		success = 0;
	while (i >= 0)
	{
		success = validate_and_populate_str(str[i], frame);
		if (!success)
			break ;
		success = check_duplicates(frame);
		if (!success)
			break ;
		i--;
	}
	if (cleanup)
		cleanup_splitted(str, size);
	if (!success)
		push_swap_error(frame);
}

void	validate_args(int argc, char **argv, t_frame *frame)
{
	if (argc < 2)
		exit(0);
	if (argv[1][0] == '-' && argv[1][1] == 'v')
	{
		frame->print_stacks = 1;
		argv++;
		argc--;
	}
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		frame->size = get_num_args(argv);
		check_args(frame->size, argv, frame, 1);
	}
	else
	{
		frame->size = get_num_args(argv + 1);
		check_args(frame->size, argv + 1, frame, 0);
	}
}

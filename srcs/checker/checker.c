/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 01:25:42 by azaaza            #+#    #+#             */
/*   Updated: 2023/10/17 01:44:53 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static op_fun_ptr	get_op_fun_ptr(int diff)
{
	int			i;
	op_fun_ptr	ops[39];

	i = 0;
	while (i < 39)
		ops[i++] = &push_swap_error;
	ops[0] = &sa;
	ops[4] = &sb;
	ops[8] = &pa;
	ops[12] = &pb;
	ops[16] = &ra;
	ops[20] = &rb;
	ops[24] = &rr;
	ops[28] = &rra;
	ops[33] = &rrb;
	ops[38] = &rrr;
	return (ops[diff]);
}

static void	read_instructions(t_frame *frame)
{
	char	*line;
	int		diff;
	char	ops_str[42] = "sa\n sb\n pa\n pb\n ra\n rb\n rr\n rra\n rrb\n rrr\n";

	while ((line = get_next_line(0)))
	{
		diff = ft_strstr(ops_str, line) - ops_str;
		free(line);
		if (diff < 0 || diff > 38)
			return (push_swap_error(frame));
		get_op_fun_ptr(diff)(frame);
	}
}

int	main(int argc, char **argv)
{
	t_frame frame;

	create_frame(&frame);
	validate_args(argc, argv, &frame);
	if (!is_queue_sorted(&frame.args_queue))
	{
		populate_stack(&frame);
		read_instructions(&frame);
		if (is_stack_sorted(frame.a))
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
		clean_stack(&frame.a);
	}
	return (0);
}
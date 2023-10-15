/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 01:25:42 by azaaza            #+#    #+#             */
/*   Updated: 2023/10/15 19:35:31 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	read_instructions(void)
{
	char	*line;
	char	ops[20];

	while ((line = get_next_line(0)))
	{
		ft_putstr_fd(line, 2);
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
		read_instructions();
		clean_stack(&frame.a);
	}
	return (0);
}
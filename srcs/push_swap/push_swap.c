/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 00:47:25 by ahmadzaaza        #+#    #+#             */
/*   Updated: 2023/10/22 13:26:26 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_frame	frame;

	create_frame(&frame);
	validate_args(argc, argv, &frame);
	if (!is_queue_sorted(&frame.args_queue))
	{
		populate_stack(&frame);
		if (frame.size <= 3)
			sort_three(&frame);
		else
			sort(&frame);
		clean_stack(&frame.a);
	}
	return (0);
}

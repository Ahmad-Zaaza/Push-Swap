/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 00:47:06 by ahmadzaaza        #+#    #+#             */
/*   Updated: 2023/10/18 10:07:02 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	// ft_putstr_fd(CNRM, 2);
}

void	push_swap_error(t_frame *frame)
{
	print_error();
	cleanup_queue(&frame->args_queue);
	clean_stack(&frame->a);
	exit(1);
}
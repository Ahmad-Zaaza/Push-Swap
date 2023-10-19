/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 00:47:28 by ahmadzaaza        #+#    #+#             */
/*   Updated: 2023/10/18 00:47:48 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three(t_frame *frame)
{
	if (get_min(frame->a) == (frame->a)->data)
	{
		r_rotate(frame, 'a');
		swap(frame, 'a');
	}
	else if (get_max(frame->a) == (frame->a)->prev->data)
		swap(frame, 'a');
	
	else if (get_max(frame->a) == (frame->a)->data)
	{
		rotate(frame, 'a');
		if (!is_stack_sorted(frame->a))
			swap(frame, 'a');
	}
	else	
		r_rotate(frame, 'a');
	
}
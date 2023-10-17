/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 00:46:29 by ahmadzaaza        #+#    #+#             */
/*   Updated: 2023/10/18 00:46:29 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	init__args_queue(t_args_queue *queue)
{
	queue->head = NULL;
	queue->tail = NULL;
}

void	enqueue(t_frame *frame, int value)
{
	t_arg_node	*new;

	new = (t_arg_node *)malloc(sizeof(t_arg_node));
	if (!new)
		return (push_swap_error(frame));
	new->value = value;
	new->next = NULL;
	if (!frame->args_queue.head)
	{
		frame->args_queue.head = new;
		frame->args_queue.tail = new;
	}
	else
	{
		frame->args_queue.tail->next = new;
		frame->args_queue.tail = new;
	}
}

long int	dequeue(t_args_queue *queue)
{
	long int	data;
	t_arg_node	*tmp;

	tmp = queue->head;
	data = queue->head->value;
	queue->head = queue->head->next;
	free(tmp);
	return (data);
}

void	cleanup_queue(t_args_queue *args_queue)
{
	t_arg_node	*tmp;

	while (args_queue->head)
	{
		tmp = args_queue->head;
		args_queue->head = args_queue->head->next;
		free(tmp);
	}
}

int	get_queue_size(t_args_queue *queue)
{
	int			size;
	t_arg_node	*tmp;

	size = 0;
	tmp = queue->head;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

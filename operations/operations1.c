/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:20:12 by azaaza            #+#    #+#             */
/*   Updated: 2023/10/03 01:21:30 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void print_operation(char *operation, char stack) {
  ft_putstr_fd(operation, 1);
  ft_putchar_fd(stack, 1);
  ft_putchar_fd('\n', 1);
}

void swap(t_frame *frame, char name, int print) {
  t_stack **stack;
  long int tmp;

  if (name == 'b')
    stack = &frame->b;
  else
    stack = &frame->a;
  if (!*stack || *stack == (*stack)->next)
    return;
  tmp = (*stack)->data;
  (*stack)->data = (*stack)->next->data;
  (*stack)->next->data = tmp;
  if (print) {
    print_operation("s", name);
  }
}

void ss(t_frame *frame) {
  swap(frame, 'a', 0);
  swap(frame, 'b', 0);
  print_operation("s", 's');
}

void pa(t_frame *frame) {
  t_stack *to_move;

  to_move = frame->b;
  if (!to_move)
    return;
  if (to_move == to_move->next)
    frame->b = NULL;
  else {
    (frame->b)->next->prev = (frame->b)->prev;
    (frame->b)->prev->next = (frame->b)->next;
    (frame->b) = (frame->b)->next;
  }
  push_stack_node(&frame->a, to_move);
  print_operation("p", 'a');
}

void pb(t_frame *frame) {
  t_stack *to_move;

  
  to_move = frame->a;
  if (!to_move)
    return;
  if (frame->a == frame->a->next)
    frame->a = NULL;
  else {
    (frame->a)->next->prev = (frame->a)->prev;
    (frame->a)->prev->next = (frame->a)->next;
    (frame->a) = (frame->a)->next;
  }
  push_stack_node(&frame->b, to_move);
  print_operation("p", 'b');
}

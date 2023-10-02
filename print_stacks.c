/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 01:35:58 by azaaza            #+#    #+#             */
/*   Updated: 2023/10/03 01:51:10 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

static void clean_strings(char *a, char *b) {
  free(a);
  free(b);
}

static void print(t_frame *frame) {
  t_stack *stack_a;
  t_stack *stack_b;
  char *a;
  char *b;

  stack_a = frame->a;
  stack_b = frame->b;

  while (1) {
    a = stack_a ? ft_itoa(stack_a->data) : ft_strdup("");
    b = stack_b ? ft_itoa(stack_b->data) : ft_strdup("");
    if (!stack_a && !stack_b) {
      clean_strings(a, b);
      break;
    }
    printf("%15s | %-15s\n", a, b);
    clean_strings(a, b);
    stack_a = (stack_a && stack_a != frame->a->prev) ? stack_a->next : NULL;
    stack_b = (stack_b && stack_b != frame->b->prev) ? stack_b->next : NULL;
  }
}

void print_stacks(t_frame *frame) {
  usleep(100000);
  ft_putstr_fd("\E[H\E[2J", 2);
  printf("%15s   %-15s\n", "Stack A", "Stack B");
  print(frame);
}
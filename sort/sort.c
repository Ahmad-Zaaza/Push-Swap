/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:02:08 by azaaza            #+#    #+#             */
/*   Updated: 2023/09/27 00:32:10 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

static void sort_until_three_or_sorted(t_frame *frame) {
  int min;
  int size;

  size = get_stack_size(&frame->a);

  while (size > 3 && !is_stack_sorted(&frame->a)) {
    print_stack(&frame->a);
    printf("size %d \n", size);
    min = get_min(&frame->a);
    if (is_rotate(&frame->a)) {
      while (frame->a.top->data != min) {
        rotate(&frame->a, 'a', 1);
      }
      push(&frame->a, &frame->b, 'b');

    } else {
      while (frame->a.top->data != min) {
        r_rotate(&frame->a, 'a', 1);
      }
      push(&frame->a, &frame->b, 'b');
    }
    size--;
  }
}

static void re_populate_a(t_frame *frame) {

  while (frame->b.top) {
    push(&frame->b, &frame->a, 'a');
  }
}

void sort(t_frame *frame) {
  sort_until_three_or_sorted(frame);
  if (is_stack_sorted(&frame->a))
    re_populate_a(frame);
  else
    sort_three(&frame->a, 'a');
  re_populate_a(frame);
}

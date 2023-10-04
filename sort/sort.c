/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:02:08 by azaaza            #+#    #+#             */
/*   Updated: 2023/10/04 02:42:40 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

// static void sort_until_three_or_sorted(t_frame *frame) {
//   int min;
//   int size;

//   size = get_stack_size(frame->a);
//   while (size > 3 && !is_stack_sorted(frame->a)) {
//     min = get_min(frame->a);
//     if (is_rotate(frame->a)) {
//       while (frame->a->data != min) {
//         rotate(frame, 'a', 1);
//       }
//       if (!is_stack_sorted(frame->a))
//         pb(frame);
//     } else {
//       while (frame->a->data != min)
//         r_rotate(frame, 'a', 1);
//       if (!is_stack_sorted(frame->a))
//         pb(frame);
//     }
//     size--;
//   }
// }

static void move_to_b(t_frame *frame) {
  find_cheapest_move(frame);
  printf("cheapest value: %d\n", frame->cheapest_value);
  printf("cheapest moves: %d\n", frame->cheapest_moves);
  exit(1);
}

static void sort_until_three_or_sorted(t_frame *frame) {
  // int min;
  int size;

  size = get_stack_size(frame->a);
  while (size > 3 && !is_stack_sorted(frame->a)) {
    pb(frame);
    pb(frame);
    if (frame->b->data > frame->b->next->data) {
      frame->b_highest = frame->b->data;
      frame->b_lowest = frame->b->next->data;
    } else {
      rotate(frame, 'b', 1);
      frame->b_highest = frame->b->data;
      frame->b_lowest = frame->b->next->data;
    }
    move_to_b(frame);
    size--;
  }
}

static void re_populate_a(t_frame *frame) {
  long int top;

  if (!frame->b)
    return;
  top = frame->b->prev->data;
  while (frame->b) {
    pa(frame);
    if (frame->b && frame->b->data == top)
      break;
  }
}

void sort(t_frame *frame) {
  // print_stack(frame->a);
  // printf("median: %d\n", find_median(frame, 'a'));
  sort_until_three_or_sorted(frame);
  if (is_stack_sorted(frame->a))
    re_populate_a(frame);
  else
    sort_three(frame, 'a');
  re_populate_a(frame);
}

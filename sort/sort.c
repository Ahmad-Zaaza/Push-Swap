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

static int calculate_b_moves(t_stack *stack, int value) {
  int highest_value;
  int highest_index;
  int index;
  t_stack *last;

  highest_index = 0;
  index = 0;
  last = stack->prev;
  while (stack != last) {
    if (stack->data > value) {
      highest_value = stack->data;
      highest_index = index;
    }
    index++;
    stack = stack->next;
  }
  if (highest_index == 0)
    return 0;
  return (moves_to_top(stack, highest_value));
}

static void find_cheapest_move(t_frame *frame) {
  t_stack *stack;
  int moves;

  stack = frame->a;
  while (stack != frame->a->prev) {
    moves = 0;
    // if its highest or lowest. put it in top
    moves = calculate_b_moves(frame->b, stack->data);
    moves += moves_to_top(frame->a, stack->data);

    if (!frame->cheapest_moves || moves < frame->cheapest_moves) {
      frame->cheapest_moves = moves;
      frame->cheapest_value = stack->data;
    }
    stack = stack->next;
  }
}

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
    // if (frame->a->data > frame->a->next->data) {
    //   frame->b_highest = frame->a->data;
    //   frame->b_lowest = frame->a->next->data;
    // }
    pb(frame);
    pb(frame);
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

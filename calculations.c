#include "push_swap.h"

int calculate_b_moves(t_stack *stack, int value) {
  int highest_value;
  int highest_index;
  int index;
  t_stack *tmp;

  highest_index = 0;
  index = 0;
  tmp = stack;
  while (tmp) {
    if (tmp->data < value) {
      highest_value = tmp->data;
      highest_index = index;
    }
    if (tmp->next == stack)
      break;
    index++;
    tmp = tmp->next;
  }
  if (highest_index == 0)
    return 0;
  return (moves_to_top(stack, highest_value));
}

 void find_cheapest_move(t_frame *frame) {
  t_stack *stack;
  int moves;

  stack = frame->a;
  while (stack != frame->a->prev) {
    moves = 0;
    // if its highest or lowest. put it in top
    if (stack->data > frame->b_highest || stack->data < frame->b_lowest)
      // +1 is the push move
      moves = moves_to_top(frame->a, stack->data) + 1;
    else
      moves = calculate_b_moves(frame->b, stack->data) +
              moves_to_top(frame->a, stack->data) + 1;

    if (!frame->cheapest_moves || moves < frame->cheapest_moves) {
      frame->cheapest_moves = moves;
      frame->cheapest_value = stack->data;
    }
    stack = stack->next;
  }
}

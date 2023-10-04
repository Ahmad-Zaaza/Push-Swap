#include "push_swap.h"

int find_pivot_b_node(t_stack *stack, int value) {
  int pivot;
  int diff;
  t_stack *tmp;

  pivot = stack->data;
  tmp = stack;
  diff = 0;
  while (tmp) {
    if (tmp->data < value && tmp->prev->data > value) {
      if (diff == 0) {
        diff = tmp->prev->data - tmp->data;
        pivot = tmp->data;
      } else if (diff > tmp->prev->data - tmp->data) {
        diff = tmp->prev->data - tmp->data;
        pivot = tmp->data;
      }
    }
    if (tmp->next == stack)
      break;
    tmp = tmp->next;
  }
  return pivot;
}

int calculate_b_moves(t_stack *stack, int value) {
  int b_pivot;
  b_pivot = find_pivot_b_node(stack, value);
  if (b_pivot == stack->data)
    return 0;
  return (moves_to_top(stack, b_pivot));
}

static void set_number_of_rotations(t_frame *frame, int a_moves_to_top,
                                    int b_moves_to_top) {
  // b
  reset_rotations(frame);
  if (b_moves_to_top > 0) {
    if (should_rotate_to_top(
            frame->b, find_pivot_b_node(frame->b, frame->cheapest_value)))
      frame->b_rotations = b_moves_to_top;
    else
      frame->b_r_rotations = b_moves_to_top;
  }
  // a
  if (should_rotate_to_top(frame->a, frame->cheapest_value))
    frame->a_rotations = a_moves_to_top;
  else
    frame->a_r_rotations = a_moves_to_top;
}

void find_cheapest_move(t_frame *frame) {
  t_stack *stack;
  int a_moves;
  int b_moves;

  stack = frame->a;
  while (stack != frame->a->prev) {
    a_moves = 0;
    b_moves = 0;
    // if its highest or lowest. put it in top
    if (stack->data > frame->b_highest || stack->data < frame->b_lowest) {
      // +1 is the push move
      a_moves = moves_to_top(frame->a, stack->data);
    } else {
      b_moves = calculate_b_moves(frame->b, stack->data);
      a_moves = moves_to_top(frame->a, stack->data);
    }
    if (!frame->cheapest_moves ||
        (a_moves + b_moves + 1) < frame->cheapest_moves) {
      frame->cheapest_moves = a_moves + b_moves + 1;
      frame->cheapest_value = stack->data;
      set_new_highest_lowest(frame, frame->cheapest_value);
      set_number_of_rotations(frame, a_moves, b_moves);
    }
    stack = stack->next;
  }
}

void reset_rotations(t_frame *frame) {
  frame->a_rotations = 0;
  frame->a_r_rotations = 0;
  frame->b_rotations = 0;
  frame->b_r_rotations = 0;
}
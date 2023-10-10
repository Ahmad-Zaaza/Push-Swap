#include "../../includes/push_swap.h"

int find_pivot_b_node(t_frame *frame, int value) {
  int pivot;
  int diff;
  t_stack *tmp;

  if (value > frame->b_highest || value < frame->b_lowest)
    return (frame->b_highest);
  pivot = frame->b->data;
  tmp = frame->b;
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
    if (tmp->next == frame->b)
      break;
    tmp = tmp->next;
  }
  return (pivot);
}

int calculate_b_moves(t_frame *frame, int value) {
  int b_pivot;
  b_pivot = find_pivot_b_node(frame, value);
  if (b_pivot == frame->b->data)
    return 0;
  return (moves_to_top(frame->b, b_pivot));
}

static void set_rotations(t_frame *frame, int a_moves_to_top,
                                    int b_moves_to_top) {
  reset_rotations(frame);
  if (b_moves_to_top > 0) {
    if (should_rotate_to_top(frame->b,
                             find_pivot_b_node(frame, frame->cheapest_value)))
      frame->b_rotations = b_moves_to_top;
    else
      frame->b_r_rotations = b_moves_to_top;
  }
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
  while (stack) {
    a_moves = 0;
    b_moves = 0;
    a_moves = moves_to_top(frame->a, stack->data);
    b_moves = calculate_b_moves(frame, stack->data);
    if (!frame->cheapest_moves ||
        (a_moves + b_moves + 1) < frame->cheapest_moves) {
      frame->cheapest_moves = a_moves + b_moves + 1;
      frame->cheapest_value = stack->data;
      set_rotations(frame, a_moves, b_moves);
    }
    if (stack->next == frame->a)
      break;
    stack = stack->next;
  }
}

void reset_rotations(t_frame *frame) {
  frame->a_rotations = 0;
  frame->a_r_rotations = 0;
  frame->b_rotations = 0;
  frame->b_r_rotations = 0;
}
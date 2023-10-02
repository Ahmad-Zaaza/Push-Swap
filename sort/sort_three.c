#include "../push_swap.h"

void sort_three(t_frame *frame, char stack_name) {
  t_stack **stack;

  if (stack_name == 'a')
    stack = &frame->a;
  else
    stack = &frame->b;

  if (get_min(*stack) == (*stack)->data) {
    r_rotate(frame, stack_name, 1);
    swap(frame, stack_name, 1);
  } else if (get_max(*stack) == (*stack)->prev->data) {
    swap(frame, stack_name, 1);
  } else if (get_max(*stack) == (*stack)->data) {
    rotate(frame, stack_name, 1);
    if (!is_stack_sorted(*stack)) {
      swap(frame, stack_name, 1);
    }
  } else {
    r_rotate(frame, stack_name, 1);
  }
}
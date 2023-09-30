#include "../push_swap.h"

void sort_three(t_stack *stack, char stack_name) {

  if (get_min(stack) == stack->top->data) {
    r_rotate(stack, stack_name, 1);
    swap(stack, stack_name, 1);
  } else if (get_max(stack) == stack->bottom->data) {
    swap(stack, stack_name, 1);
  } else if (get_max(stack) == stack->top->data) {
    rotate(stack, stack_name, 1);
    if (!is_stack_sorted(stack)) {
      swap(stack, stack_name, 1);
    }
  } else {
    r_rotate(stack, stack_name, 1);
  }
}
#include "../push_swap.h"

void rotate(t_stack **stack, char name, int print) {
  if (stack)
    *stack = (*stack)->next;
  if (print) {
    print_operation("r", name);
  }
}

void rr(t_frame *frame) {
  rotate(&frame->a, 'a', 0);
  rotate(&frame->b, 'b', 0);
  print_operation("r", 'r');
}

void r_rotate(t_stack **stack, char name, int print) {
  if (stack)
    *stack = (*stack)->prev;
  if (print) {
    print_operation("rr", name);
  }
}

void rrr(t_frame *frame) {
  r_rotate(&frame->a, 'a', 0);
  r_rotate(&frame->b, 'b', 0);
  print_operation("rr", 'r');
}
#include "../../includes/push_swap.h"

void rotate(t_frame *frame, char name) {
  t_stack **stack;

  if (name == 'b')
    stack = &frame->b;
  else
    stack = &frame->a;
  if (*stack)
    *stack = (*stack)->next;
  if (frame->print_operations) {
    print_operation("r", name, frame);
  }
}

void r_rotate(t_frame *frame, char name) {
  t_stack **stack;

  if (name == 'b')
    stack = &frame->b;
  else
    stack = &frame->a;
  if (*stack)
    *stack = (*stack)->prev;
  if (frame->print_operations) {
    print_operation("rr", name, frame);
  }
}

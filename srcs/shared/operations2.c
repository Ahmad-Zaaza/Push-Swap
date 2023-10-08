#include "../../includes/push_swap.h"

void rotate(t_frame *frame, char name, int print) {
  t_stack **stack;

  if (name == 'b')
    stack = &frame->b;
  else
    stack = &frame->a;
  if (*stack)
    *stack = (*stack)->next;
  if (print) {
    print_operation("r", name, frame);
  }
}

void rr(t_frame *frame) {
  rotate(frame, 'a', 0);
  rotate(frame, 'b', 0);
  print_operation("r", 'r', frame);
}

void r_rotate(t_frame *frame, char name, int print) {
  t_stack **stack;

  if (name == 'b')
    stack = &frame->b;
  else
    stack = &frame->a;
  if (*stack)
    *stack = (*stack)->prev;
  if (print) {
    print_operation("rr", name, frame);
  }
}

void rrr(t_frame *frame) {
  r_rotate(frame, 'a', 0);
  r_rotate(frame, 'b', 0);
  print_operation("rr", 'r', frame);
}
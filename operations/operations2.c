#include "../push_swap.h"

void rotate(t_stack *stack, char name, int print) {
  t_stack_node *new_top;
  t_stack_node *new_bottom;

  if (!stack->top || !stack->top->next)
    return;
  new_top = stack->top->next;
  new_bottom = stack->top;
  new_top->prev = NULL;
  new_bottom->next = NULL;
  new_bottom->prev = stack->bottom;
  stack->bottom->next = new_bottom;
  stack->top = new_top;
  stack->bottom = new_bottom;

  if (print) {
    print_operation("r", name);
  }
}

void rr(t_stack *a, t_stack *b) {
  rotate(a, 'a', 0);
  rotate(b, 'b', 0);
  print_operation("r", 'r');
}
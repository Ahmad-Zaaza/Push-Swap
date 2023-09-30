#include "../push_swap.h"
#include <stdio.h>

void print_operation(char *operation, char stack) {
  ft_putstr_fd(operation, 1);
  ft_putchar_fd(stack, 1);
  ft_putchar_fd('\n', 1);
}

void swap(t_stack *stack, char name, int print) {

  t_stack **top;
  t_stack *new_top;

  top = &stack;

  if (!*top || *top == (*top)->next)
    return;

  new_top = (*top)->next;
  new_top->next = *top;
  new_top->prev = (*top)->prev;
  new_top->prev->next = new_top;

  (*top)->next = (*top)->next->next;
  (*top)->next->next->prev = *top;
  (*top)->prev = (*top)->next;

  *top = new_top;

  if (print) {
    print_operation("s", name);
  }
}

void ss(t_stack *a, t_stack *b) {
  swap(a, 'a', 0);
  swap(b, 'b', 0);
  print_operation("s", 's');
}

void push(t_stack *from, t_stack *to, char name) {

  t_stack **from_top;
  t_stack *to_move;

  from_top = &from;
  to_move = *from_top;
  if (!to_move)
    return;

  if (to_move == to_move->next) {
    from = NULL;

  } else {
    (*from_top)->next->prev = (*from_top)->prev;
    (*from_top)->prev->next = (*from_top)->next;
    (*from_top) = (*from_top)->next;
  }
  push_stack_node(to, to_move);
  print_operation("p", name);
}
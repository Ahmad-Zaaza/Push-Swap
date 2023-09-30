#include "../push_swap.h"
#include <stdio.h>

void print_operation(char *operation, char stack) {
  ft_putstr_fd(operation, 1);
  ft_putchar_fd(stack, 1);
  ft_putchar_fd('\n', 1);
}

void swap(t_stack *stack, char name, int print) {
  t_stack_node *second_node;
  t_stack_node *first_node;

  if (!stack->top || !stack->top->next)
    return;

  first_node = stack->top;
  second_node = stack->top->next;

  first_node->next = first_node->next->next;
  first_node->prev = first_node->next->prev;

  second_node->prev = NULL;
  second_node->next = first_node;

  stack->top = second_node;
  stack->top->next = first_node;
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
  t_stack_node *to_move;
  if (!from->top)
    return;
  to_move = from->top;
  if (!from->top->next) {
    from->top = NULL;
    from->bottom = NULL;
  } else {
    from->top = from->top->next ;
    from->top->prev = NULL;
  }
  push_stack_node(to, to_move);
  print_operation("p", name);
}
#include "push_swap.h"
#include <stdio.h>

static t_stack_node *create_stack_node(int value) {
  t_stack_node *new;
  new = (t_stack_node *)malloc(sizeof(t_stack_node));

  if (!new) {
    ft_putstr_fd("Error mallocing\n", 2);
    exit(1);
  }
  new->data = value;
  new->next = NULL;
  new->prev = NULL;
  return (new);
}

void push_stack_node(t_stack *stack, t_stack_node *new_node) {
  new_node->next = NULL;
  new_node->prev = NULL;
  if (!stack->top) {
    stack->top = new_node;
    stack->bottom = new_node;
  } else {
    stack->top->prev = new_node;
    new_node->next = stack->top;
    stack->top = new_node;
  }
}

void populate_stack(t_frame *frame) {

  int i;
  int value;
  t_stack_node *new;

  i = 0;
  while (i < frame->size) {
    value = dequeue(&frame->args_queue);
    new = create_stack_node(value);
    push_stack_node(&frame->a, new);
    i++;
  }
}

void print_stack(t_stack *stack) {
  t_stack_node *tmp;

  tmp = stack->top;
  while (tmp) {
    ft_putnbr_fd(tmp->data, 1);
    ft_putchar_fd(' ', 1);
    tmp = tmp->next;
  }
  ft_putchar_fd('\n', 1);
}

void clean_stack(t_stack *stack) {
  t_stack_node *tmp;

  while (stack->top) {
    tmp = stack->top;
    stack->top = stack->top->next;
    free(tmp);
  }
}
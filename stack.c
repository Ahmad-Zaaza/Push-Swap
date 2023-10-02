#include "push_swap.h"
#include <stdio.h>

static t_stack *create_stack_node(int value) {
  t_stack *new;
  new = (t_stack *)malloc(sizeof(t_stack));

  if (!new) {
    ft_putstr_fd("Error mallocing\n", 2);
    exit(1);
  }
  new->data = value;
  new->next = NULL;
  new->prev = NULL;
  return (new);
}

void push_stack_node(t_stack **stack, t_stack *new_node) {

  if (!*stack) {
    *stack = new_node;

    (*stack)->next = *stack;
    (*stack)->prev = *stack;

  } else {
    new_node->next = *stack;
    new_node->prev = (*stack)->prev;
    (*stack)->prev = new_node;
    new_node->prev->next = new_node;
    *stack = (*stack)->prev;
  }
}

void populate_stack(t_frame *frame) {

  int i;
  int value;
  t_stack *new_node;

  i = 0;
  while (i < frame->size) {
    value = dequeue(&frame->args_queue);
    // TODO: protect
    new_node = create_stack_node(value);
    push_stack_node(&frame->a, new_node);
    i++;
  }
}

void print_stack(t_stack *stack) {
  t_stack **top;
  t_stack *tmp;

  top = &stack;
  tmp = *top;
  while (tmp) {
    ft_putnbr_fd(tmp->data, 1);
    ft_putchar_fd(' ', 1);
    ft_putchar_fd('\n', 1);
    tmp = tmp->next;
    if (tmp == *top) {
      break;
    }
  }
}


void clean_stack(t_stack **stack) {
  long int last;
  t_stack *tmp;

  tmp = *stack;
  last = (*stack)->prev->data;
  while (tmp) {
    tmp = tmp->next;
    free(tmp->prev);
    if (tmp->data == last) {
      break;
    }
  }
}
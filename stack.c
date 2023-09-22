#include "push_swap.h"

static void init_stack(t_stack *stack, int size) {
  stack->size = size;
  stack->is_empty = size == 0;
  stack->top = NULL;
  stack->bottom = NULL;
}

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

static void push_stack_node(t_stack *stack, t_stack_node *new) {
  if (!stack->top) {
    stack->top = new;
    stack->bottom = new;
  } else {
    stack->top->prev = new;
    new->next = stack->top;
    stack->top = new;
  }
}

void init_and_populate_stack(t_stack *a, t_stack *b, t_args_queue *queue) {
  int size;
  int i;
  int value;
  t_stack_node *new;

  size = get_queue_size(queue);
  init_stack(a, size);
  init_stack(b, 0);
  i = 0;
  while (i < size) {
    value = dequeue(queue);
    new = create_stack_node(value);
    push_stack_node(a, new);
    i++;
  }
}

void print_stack(t_stack *stack) {
  t_stack_node *tmp;

  tmp = stack->top;
  while (tmp) {
    ft_putnbr_fd(tmp->data, 1);
    ft_putchar_fd('\n', 1);
    tmp = tmp->next;
  }
}
void clean_stack(t_stack *stack) {
  t_stack_node *tmp;

  while (stack->top) {
    tmp = stack->top;
    stack->top = stack->top->next;
    free(tmp);
  }
}
#include "libft/libft.h"
#include "push_swap.h"

int is_queue_sorted(t_args_queue *queue) {
  t_arg_node *tmp;
  tmp = queue->head;
  while (tmp->next) {
    if (tmp->value < tmp->next->value) {
      return (0);
    }
    tmp = tmp->next;
  }
  ft_putstr_fd("Already sorted!\n", 1);
  cleanup_queue(queue);
  return (1);
}

int is_stack_sorted(t_stack *stack) {
  t_stack_node *tmp;
  tmp = stack->top;
  while (tmp->next) {
    if (tmp->data > tmp->next->data) {
      return (0);
    }
    tmp = tmp->next;
  }
  return (1);
}

int get_min(t_stack *stack) {
  int min;

  t_stack_node *node;
  node = stack->top;
  min = node->data;
  while (node) {
    if (node->data < min) {
      min = node->data;
    }
    node = node->next;
  }
  return (min);
}

int get_max(t_stack *stack) {
  int max;

  t_stack_node *node;
  node = stack->top;
  max = node->data;
  while (node) {
    if (node->data > max) {
      max = node->data;
    }
    node = node->next;
  }
  return (max);
}

int is_rotate(t_stack *stack) {
  int min;
  int index;
  int min_index;

  t_stack_node *node;
  node = stack->top;
  min = node->data;
  index = 0;
  min_index = 0;
  while (node) {
    if (node->data < min) {
      min_index = index;
      min = node->data;
    }
    index++;
    node = node->next;
  }
  return min_index < stack->size / 2 ? 1 : 0;
}
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
  cleanup_queue(queue);
  return (1);
}

int is_stack_sorted(t_stack *stack) {

  t_stack **top;
  t_stack *tmp;

  top = &stack;
  tmp = *top;
  while (tmp) {
    if (tmp->data > tmp->next->data && tmp->next != *top)
      return (0);
    if (tmp->next == *top)
      break;
    tmp = tmp->next;
  }
  return (1);
}


int get_min(t_stack *stack) {
  int min;

  t_stack **top;
  t_stack *tmp;

  top = &stack;
  tmp = *top;
  min = tmp->data;
  while (tmp) {
    if (tmp->data < min) {
      min = tmp->data;
    }
    if (tmp->next == *top)
      break;
    tmp = tmp->next;
  }
  return (min);
}

int get_max(t_stack *stack) {
  int max;

  t_stack **top;
  t_stack *tmp;

  top = &stack;
  tmp = *top;
  max = tmp->data;
  while (tmp) {
    if (tmp->data > max) {
      max = tmp->data;
    }
    if (tmp->next == *top)
      break;
    tmp = tmp->next;
  }
  return (max);
}

int is_rotate(t_stack *stack) {
  t_stack **top;
  t_stack *tmp;
  int min;
  int index;
  int min_index;

  top = &stack;
  tmp = *top;
  min = tmp->data;
  index = 0;
  min_index = 0;
  while (tmp) {
    if (tmp->data < min) {
      min_index = index;
      min = tmp->data;
    }
    if (tmp->next == *top)
      break;
    index++;
    tmp = tmp->next;
  }
  return ((min_index + 1) <= get_stack_size(stack) / 2 ? 1 : 0);
}
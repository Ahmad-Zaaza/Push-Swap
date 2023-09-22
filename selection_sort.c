#include "push_swap.h"

static int get_node_index(t_stack *stack, t_stack_node *node) {
  int index;
  t_stack_node *tmp;

  index = 0;
  tmp = stack->top;
  while (tmp) {
    if (tmp == node)
      return (index);
    index++;
    tmp = tmp->next;
  }
  return (-1);
}

void selection_sort(t_stack *a, t_stack *b) {
  t_stack_node *min_node;
  t_stack_node *sort_position;
  t_stack_node *tmp2;

  sort_position = a->top;
  while (sort_position) {
    min_node = sort_position;
    tmp2 = sort_position->next;
    while (tmp2) {
      if (tmp2->data < min_node->data) {
        min_node = tmp2;
      }
      tmp2 = tmp2->next;
    }
    if (min_node != sort_position) {
       
    }
  }
}
#include "push_swap.h"
#include <stdio.h>

// void sa(t_stack_node **a) {
//   t_stack_node *tmp;

//   if (!*a || !(*a)->next)
//     return;
//   tmp = *a;

//   *a = (*a)->next;
//   tmp->prev = *a;
//   (*a)->prev = NULL;
//   tmp->next = (*a)->next;
//   (*a)->next = tmp;
// }

// void pa(t_stack_node **a, t_stack_node **b) {
//   t_stack_node *new;

//   if (!*b)
//     return;
//   new = *b;
//   if (!(*b)->next)
//     *b = NULL;
//   else {
//     *b = (*b)->next;
//     (*b)->prev = NULL;
//   }

//   if (!*a) {
//     *a = new;
//     (*a)->next = NULL;
//     (*a)->prev = NULL;
//   } else {
//     new->next = *a;
//     new->prev = NULL;
//     *a = new;
//   }
// }

// void quick_sort(t_stack_node **a) {
//   t_stack_node *pivot;
//   t_stack_node *tmp;
// }

// static void print_queue(t_args_queue *queue) {
//   t_arg_node *tmp;

//   tmp = queue->head;
//   while (tmp) {
//     ft_putnbr_fd(tmp->value, 1);
//     ft_putchar_fd('\n', 1);

//     tmp = tmp->next;
//   }
// }
int main(int argc, char **argv) {
  t_stack a;
  t_stack b;
  t_args_queue args_queue;
  validate_args(argc, argv, &args_queue);
  init_and_populate_stack(&a, &b, &args_queue);
  // print queue
  printf("Initial A:\n");
  print_stack(&a);

  printf("After swapping A\n");
  swap(&a, 'a', 1);
  print_stack(&a);

  push(&a, &b, 'a');
  push(&a, &b, 'a');
  printf("A After pushing2 items\n");
  print_stack(&a);
  printf("B After pushing 2 items\n");
  print_stack(&b);
  clean_stack(&a);
  clean_stack(&b);
  ft_putstr_fd("OK\n", 1);

  return 0;
}
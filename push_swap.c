#include "push_swap.h"

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

int main(int argc, char **argv) {
  // t_stack a;
  // t_stack b;
  t_args_queue args_queue;
  validate_args(argc, argv, &args_queue);
  // TODO: populate stack a with args_queue
  ft_putstr_fd("OK\n", 1);

  return 0;
}
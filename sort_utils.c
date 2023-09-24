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
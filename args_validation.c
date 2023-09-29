#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

static int check_duplicates(t_args_queue *queue) {
  t_arg_node *tmp;
  t_arg_node *tmp2;

  tmp = queue->head;

  while (tmp) {
    tmp2 = tmp->next;
    while (tmp2) {
      if (tmp->value == tmp2->value) {
        ft_putstr_fd("Error\n", 2);
        ft_putstr_fd("Invalid argument, duplicate found.\n", 2);
        return (0);
      }
      tmp2 = tmp2->next;
    }
    tmp = tmp->next;
  }
  return (1);
}

// checks against maximum and minimum integer values and enqueues the value
static int validate_and_populate_str(char *str, t_args_queue *queue) {
  int value;

  value = ft_atoi(str);
  if (value > INT_MAX || value <= INT_MIN) {
    ft_putstr_fd("Error\n", 2);
    ft_putstr_fd("Invalid argument, integer overflow.\n", 2);
    return (0);
  }
  enqueue(queue, value);
  return (1);
}

static void check_args(int size, char **str, t_args_queue *args_queue,
                       int cleanup) {
  int i;

  i = size - 1;
  while (i >= 0) {
    if (!is_str_digit(str[i]) ||
        !validate_and_populate_str(str[i], args_queue) ||
        !check_duplicates(args_queue)) {
      cleanup_queue(args_queue);
      if (cleanup)
        cleanup_splitted(str, size);
      exit(1);
    }
    i--;
  }
}

void validate_args(int argc, char **argv, t_frame *frame) {

  if (argc == 1 || (argc == 2 && !argv[1][0]))
    exit(0);

  if (argc == 2) {
    argv = ft_split(argv[1], ' ');
    frame->size = get_num_args(argv);
    check_args(frame->size, argv, &frame->args_queue, 1);
    cleanup_splitted(argv, frame->size);
  } else {
    frame->size = get_num_args(argv + 1);
    check_args(frame->size, argv + 1, &frame->args_queue, 0);
  }
}

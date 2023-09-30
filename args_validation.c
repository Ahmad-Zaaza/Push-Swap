#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

static int check_duplicates(t_frame *frame) {
  t_arg_node *tmp;
  t_arg_node *tmp2;

  tmp = frame->args_queue.head;

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
static int validate_and_populate_str(char *str, t_frame *frame) {
  long int value;

  if (!is_str_digit(str)) {
    print_error("Invalid argument, found non integer character");
    return (0);
  }
  value = ft_atoi(str);
  if (value > INT_MAX || value < INT_MIN) {
    print_error("Invalid argument, integer overflow");
    return (0);
  }
  enqueue(&frame->args_queue, value);
  return (1);
}

static void check_args(int size, char **str, t_frame *frame, int cleanup) {
  int i;
  int success;

  i = size - 1;
  success = 1;
  while (i >= 0) {
    success = validate_and_populate_str(str[i], frame);
    success = check_duplicates(frame);
    if (!success)
      break;
    i--;
  }
  if (cleanup)
    cleanup_splitted(str, size);
  if (!success) {
    cleanup_queue(&frame->args_queue);
    exit(1);
  }
}

void validate_args(int argc, char **argv, t_frame *frame) {

  if (argc == 1 || (argc == 2 && !argv[1][0]))
    exit(0);

  if (argc == 2) {
    argv = ft_split(argv[1], ' ');
    frame->size = get_num_args(argv);
    check_args(frame->size, argv, frame, 1);
  } else {
    frame->size = get_num_args(argv + 1);
    check_args(frame->size, argv + 1, frame, 0);
  }
}

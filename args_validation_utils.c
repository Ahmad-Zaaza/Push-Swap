#include "push_swap.h"

int get_num_args(char **str) {
  int i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

// checks if the string only contains digits and optional sign
int is_str_digit(char *str) {
  int i;

  i = 0;
  if (!str[i]) {
    ft_putstr_fd("Error\n", 2);
    return (0);
  }
  if (str[i] == '-' || str[i] == '+')
    i++;

  while (str[i]) {
    if (!ft_isdigit(str[i])) {
      ft_putstr_fd("Error\n", 2);
      ft_putstr_fd("Invalid argument, found non integer character.\n", 2);
      return 0;
    }
    i++;
  }
  return 1;
}
void cleanup_splitted(char **str, int size) {
  while (size > 0) {
    free(str[size - 1]);
    size--;
  }
  free(str);
}
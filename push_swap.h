#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "stdlib.h"
#include "unistd.h"

typedef struct s_stack_node {
  int data;
  struct s_stack_node *prev;
  struct s_stack_node *next;
} t_stack_node;

typedef struct s_stack {
  int size;
  int is_empty;
  t_stack_node *top;
  t_stack_node *bottom;
} t_stack;

// -- Utils -- //
char *ft_substr(char const *s, unsigned int start, size_t len);
size_t ft_strlen(const char *str);
char **ft_split(char const *s, char c);
int ft_atoi(const char *str);
int ft_isdigit(int c);
void ft_putstr_fd(char *s, int fd);
void ft_putchar_fd(char c, int fd);

#endif
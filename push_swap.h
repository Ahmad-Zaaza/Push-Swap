#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "stdlib.h"
#include "unistd.h"
#include "./libft/libft.h"

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


#endif
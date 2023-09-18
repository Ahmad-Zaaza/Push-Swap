#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#define INT_MAX 2147483647
#define INT_MIN -2147483648

#include "./libft/libft.h"
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

typedef struct s_arg_node {
  int value;
  struct s_arg_node *next;
} t_arg_node;

typedef struct s_args_queue {
  t_arg_node *head;
  t_arg_node *tail;
} t_args_queue;

void validate_args(int argc, char **argv, t_args_queue *args_queue);

// queue
void init_queue(t_args_queue *queue);
void enqueue(t_args_queue *queue, int value);
void cleanup_queue(t_args_queue *args_queue);
#endif
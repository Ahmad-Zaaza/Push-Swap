#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#define INT_MAX 2147483647
#define INT_MIN -2147483648

#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

// validation
void validate_args(int argc, char **argv, t_args_queue *args_queue);
int get_num_args(char **str);
int is_str_digit(char *str);
void cleanup_splitted(char **str, int size);

// queue
void init_queue(t_args_queue *queue);
void enqueue(t_args_queue *queue, int value);
int dequeue(t_args_queue *queue);
void cleanup_queue(t_args_queue *args_queue);
int get_queue_size(t_args_queue *queue);
int is_queue_sorted(t_args_queue *queue);

// stack
void init_and_populate_stack(t_stack *a, t_stack *b, t_args_queue *queue);
void print_stack(t_stack *stack);
void clean_stack(t_stack *stack);
void push_stack_node(t_stack *stack, t_stack_node *new_node);

// operations
void print_operation(char *operation, char stack);
void swap(t_stack *stack, char name, int print);
void push(t_stack *from, t_stack *to, char name);
void ss(t_stack *a, t_stack *b);
void rotate(t_stack *stack, char name, int print);
void rr(t_stack *a, t_stack *b);
void r_rotate(t_stack *stack, char name, int print);
void rrr(t_stack *a, t_stack *b);

// sort
void sort_three(t_stack *stack, char stack_name);
int get_max(t_stack *stack);
int get_min(t_stack *stack);
int is_stack_sorted(t_stack *stack);
void sort(t_stack *a, t_stack *b);
int is_rotate(t_stack *stack);
#endif
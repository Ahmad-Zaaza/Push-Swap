#include "push_swap.h"

void init_queue(t_args_queue *queue) {
  queue->head = NULL;
  queue->tail = NULL;
}

void enqueue(t_args_queue *queue, int value) {
  t_arg_node *new;

  new = (t_arg_node *)malloc(sizeof(t_arg_node));
  if (!new)
    exit(1);
  new->value = value;
  new->next = NULL;
  if (!queue->head) {
    queue->head = new;
    queue->tail = new;
  } else {
    queue->tail->next = new;
    queue->tail = new;
  }
}

int dequeue(t_args_queue *queue) {
  int data;
  t_arg_node *tmp;

  tmp = queue->head;
  data = queue->head->value;
  queue->head = queue->head->next;
  free(tmp);
  return data;
}

void cleanup_queue(t_args_queue *args_queue) {
  t_arg_node *tmp;
  while (args_queue->head) {
    tmp = args_queue->head;
    args_queue->head = args_queue->head->next;
    free(tmp);
  }
}

int get_queue_size(t_args_queue *queue) {
  int size;
  t_arg_node *tmp;

  size = 0;
  tmp = queue->head;
  while (tmp) {
    size++;
    tmp = tmp->next;
  }
  return (size);
}
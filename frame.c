#include "push_swap.h"

void create_frame(t_frame *frame) {
  frame->size = 0;
  frame->args_queue.head = NULL;
  frame->args_queue.tail = NULL;
  frame->a.top = NULL;
  frame->a.bottom = NULL;
  frame->b.top = NULL;
  frame->b.bottom = NULL;
}
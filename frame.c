#include "push_swap.h"

void	create_frame(t_frame *frame)
{
	frame->size = 0;
	frame->print_stacks = 0;
	frame->cheapest_moves = 0;
	frame->args_queue.head = NULL;
	frame->args_queue.tail = NULL;
	frame->a = NULL;
	frame->b = NULL;
}
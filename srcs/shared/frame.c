#include "../../includes/push_swap.h"

void	create_frame(t_frame *frame)
{
	frame->size = 0;
	frame->print_stacks = 0;
	frame->print_operations = 1;
	frame->cheapest_moves = 0;
	frame->a_rotations = 0;
	frame->a_r_rotations = 0;
	frame->b_rotations = 0;
	frame->b_r_rotations = 0;
	frame->args_queue.head = NULL;
	frame->args_queue.tail = NULL;
	frame->a = NULL;
	frame->b = NULL;
}
#include "../push_swap.h"
#include <stdio.h>

void	print_operation(char *operation, char stack)
{
	ft_putstr_fd(operation, 1);
	ft_putchar_fd(stack, 1);
	ft_putchar_fd('\n', 1);
}

void	swap(t_frame *frame, char name, int print)
{
	t_stack		*top;
	long int	tmp;

	if (name == 'b')
		top = frame->b;
	else
		top = frame->a;
	if (!top || top == (top)->next)
		return ;
	tmp = (top)->data;
	(top)->data = (top)->next->data;
	(top)->next->data = tmp;
	if (print)
	{
		print_operation("s", name);
	}
}

void	ss(t_frame *frame)
{
	swap(frame, 'a', 0);
	swap(frame, 'b', 0);
	print_operation("s", 's');
}

void	push(t_stack **from, t_stack **to, char name)
{
	t_stack **from_top;
	t_stack *to_move;

	from_top = from;
	to_move = *from_top;
	if (!to_move)
		return ;

	if (to_move == to_move->next)
	{
		from = NULL;
	}
	else
	{
		(*from_top)->next->prev = (*from_top)->prev;
		(*from_top)->prev->next = (*from_top)->next;
		(*from_top) = (*from_top)->next;
	}
	push_stack_node(to, to_move);
	print_operation("p", name);
}
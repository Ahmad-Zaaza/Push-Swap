#include "../../includes/push_swap.h"

void	print_error(char *message)
{
	ft_putstr_fd(CRED, 2);
	ft_putstr_fd("Error\n", 2);
	if (message)
	{
		ft_putstr_fd(message, 2);
		ft_putstr_fd("\n", 2);
	}
	ft_putstr_fd(CNRM, 2);
}

void	push_swap_error(t_frame *frame)
{
	cleanup_queue(&frame->args_queue);
	clean_stack(&frame->a);
	exit(1);
}
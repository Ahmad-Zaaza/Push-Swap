/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:46:39 by azaaza            #+#    #+#             */
/*   Updated: 2023/10/13 23:10:05 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void rra(t_frame *frame) { r_rotate(frame, 'a'); }
void rrb(t_frame *frame) { r_rotate(frame, 'b'); }
void rrr(t_frame *frame) {
  frame->print_operations = 0;
  rra(frame);
  rrb(frame);
  frame->print_operations = 1;
  if (frame->print_operations)
    print_operation("rr", 'r', frame);
}
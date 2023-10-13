/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 01:25:42 by azaaza            #+#    #+#             */
/*   Updated: 2023/10/13 22:45:54 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void read_instructions(t_frame) {}

int main(int argc, char **argv) {
  t_frame frame;

  create_frame(&frame);
  validate_args(argc, argv, &frame);
  if (!is_queue_sorted(&frame.args_queue)) {
    populate_stack(&frame);
    read_instructions(frame);
    clean_stack(&frame.a);
  }
  return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 01:25:42 by azaaza            #+#    #+#             */
/*   Updated: 2023/10/12 02:06:25 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int main(int argc, char **argv) {
  t_frame frame;

  create_frame(&frame);
  validate_args(argc, argv, &frame);
  if (!is_queue_sorted(&frame.args_queue)) {
    populate_stack(&frame);
    if (frame.size <= 3) {
      sort_three(&frame, 'a');
    } else {
      sort(&frame);
    }
    clean_stack(&frame.a);
  }
  return (0);
}
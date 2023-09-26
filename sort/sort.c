/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:02:08 by azaaza            #+#    #+#             */
/*   Updated: 2023/09/27 00:32:10 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void sort_until_three_or_sorted(t_stack *a, t_stack *b) {
  int min;

  while (a->size > 3 && !is_stack_sorted(a)) {
    min = get_min(a);
    if (is_rotate(a)) {
      while (a->top->data != min) {
        rotate(a, 'a', 1);
      }
      push(a, b, 'b');
      b->size++;
    } else {
      while (a->top->data != min) {
        r_rotate(a, 'a', 1);
      }
      push(a, b, 'b');
      b->size++;
    }
    a->size--;
  }
}

static void re_populate_a(t_stack *a, t_stack *b) {
  while (b->size > 0) {
    push(b, a, 'a');
    b->size--;
  }
}

void sort(t_stack *a, t_stack *b) {
  sort_until_three_or_sorted(a, b);
  if (is_stack_sorted(a))
    re_populate_a(a, b);
  else
    sort_three(a, 'a');
  re_populate_a(a, b);
}

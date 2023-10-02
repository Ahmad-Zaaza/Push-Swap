/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 01:53:14 by azaaza            #+#    #+#             */
/*   Updated: 2023/10/03 02:12:13 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sort_array(long *arr, int size) {
  int i;
  long tmp;

  i = 0;
  while (i < (size - 1)) {
    if (arr[i] <= arr[i + 1]) {
      i++;
    } else {
      tmp = arr[i];
      arr[i] = arr[i + 1];
      arr[i + 1] = tmp;
      i = 0;
    }
  }
}

static int get_median(t_stack *stack) {
  long *array;
  int size;
  int i;
  int median;

  size = get_stack_size(stack);
  array = (long *)malloc(sizeof(long) * size);
  i = 0;
  while (i < size) {
    array[i] = stack->data;
    stack = stack->next;
    i++;
  }
  sort_array(array, size);
  median = array[size / 2];
  free(array);
  return (median);
}

int find_median(t_frame *frame, char stack_name) {
  t_stack *stack;

  if (stack_name == 'a')
    stack = frame->a;
  else
    stack = frame->b;

  return get_median(stack);
}
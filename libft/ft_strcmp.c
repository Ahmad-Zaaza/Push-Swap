/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 01:29:16 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/20 01:54:52 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strcmp(const char *s1, const char *s2) {
  int i;

  i = 0;
  while (s1[i] && s2[i] && s1[i] == s2[i])
    i++;
  return (s1[i] - s2[i]);
}
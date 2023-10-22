/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 21:08:43 by ahmadzaaza        #+#    #+#             */
/*   Updated: 2023/10/22 18:18:46 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "./get_next_line/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>

int			ft_isdigit(int c);

size_t		ft_strlen(const char *str);

long int	ft_atoi(const char *str);

char		*ft_strstr(const char *haystack, const char *needle);

char		*ft_strdup(const char *s1);

char		*ft_substr(char const *s, unsigned int start, size_t len);

char		**ft_split(char const *s, char c);

char		*ft_itoa(int n);

void		ft_putchar_fd(char c, int fd);

void		ft_putstr_fd(char *s, int fd);

void		ft_putnbr_fd(int n, int fd);

#endif
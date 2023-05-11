/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:56:33 by sojung            #+#    #+#             */
/*   Updated: 2021/12/10 17:42:53 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(long long int n);
int		ft_putptr(unsigned long ptr, int flag);
int		ft_puthex(unsigned int n, int index);
char	ft_detect_format(char c);
void	ft_print_arg(char type, int *i, int *count, va_list ap);
int		ft_printf(const char *s, ...);

#endif

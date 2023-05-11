/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:08:33 by sojung            #+#    #+#             */
/*   Updated: 2021/12/16 13:19:37 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_detect_format(char c)
{
	char	*formats;
	int		i;

	formats = "cspdiuxX%";
	i = 0;
	while (i < 9)
	{
		if (c == formats[i])
			return (c);
		i++;
	}
	return ('n');
}

void	ft_print_arg(char type, int *i, int *count, va_list ap)
{
	if (type == 'c')
		(*count) += ft_putchar((char)va_arg(ap, int));
	else if (type == 's')
		(*count) += ft_putstr(va_arg(ap, char *));
	else if (type == 'p')
		(*count) += ft_putptr((unsigned long)va_arg(ap, void *), 0);
	else if (type == 'd' || type == 'i')
		(*count) += ft_putnbr(va_arg(ap, int));
	else if (type == 'u')
		(*count) += ft_putnbr(va_arg(ap, unsigned int));
	else if (type == 'x')
		(*count) += ft_puthex(va_arg(ap, unsigned int), 0);
	else if (type == 'X')
		(*count) += ft_puthex(va_arg(ap, unsigned int), 1);
	else
		(*count) += ft_putchar('%');
	(*i)++;
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	char	type;
	int		count;

	va_start(ap, s);
	count = 0;
	i = 0;
	while (s && s[i])
	{
		if (s[i] == '%')
		{
			type = ft_detect_format(s[i + 1]);
			if (type != 'n')
				ft_print_arg(type, &i, &count, ap);
			else
				i++;
		}
		else
			count += ft_putchar(s[i]);
		i++;
	}
	va_end(ap);
	return (count);
}

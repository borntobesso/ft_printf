/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:56:37 by sojung            #+#    #+#             */
/*   Updated: 2021/12/16 13:19:49 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	i;

	i = 0;
	i += write(1, &c, 1);
	return (i);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		i += write(1, "(null)", 6);
	while (s != NULL && *s)
		i += write(1, s++, 1);
	return (i);
}

int	ft_putnbr(long long int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i += write(1, "-", 1);
		n *= -1;
	}
	if (n > 9)
		i += ft_putnbr(n / 10);
	i += ft_putchar(n % 10 + '0');
	return (i);
}

int	ft_putptr(unsigned long ptr, int flag)
{
	char	*base;
	int		i;

	base = "0123456789abcdef";
	i = 0;
	if (ptr == 0)
		return (write(1, "0x0", 3));
	if (flag == 0)
		i += write(1, "0x", 2);
	if (ptr > 15)
		i += ft_putptr(ptr / 16, 1);
	i += ft_putchar(base[ptr % 16]);
	return (i);
}

int	ft_puthex(unsigned int n, int index)
{
	char	*base_lower;
	char	*base_upper;
	char	*base;
	int		i;

	base_lower = "0123456789abcdef";
	base_upper = "0123456789ABCDEFG";
	i = 0;
	if (index == 0)
		base = base_lower;
	else
		base = base_upper;
	if (n > 15)
		i += ft_puthex(n / 16, index);
	i += ft_putchar(base[n % 16]);
	return (i);
}

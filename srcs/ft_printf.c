/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsedat <vsedat@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:15:18 by vsedat            #+#    #+#             */
/*   Updated: 2022/02/05 15:44:46 by vsedat           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	printspecial(va_list args, const char type)
{
	int	length;

	length = 0;
	if (type == 'c')
		length += ft_putchar(va_arg(args, int));
	if (type == 's')
		length += ft_printstr(va_arg(args, char *));
	if (type == 'p')
		length += ft_print_ptr(va_arg(args, unsigned long long));
	if (type == 'd' || type == 'i')
		length += ft_printnbr(va_arg(args, int));
	if (type == 'u')
		length += ft_print_unsigned(va_arg(args, unsigned int));
	if (type == 'x' || type == 'X')
		length += ft_print_hex(va_arg(args, unsigned int), type);
	if (type == '%')
		length += ft_printpercent();
	return (length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		length;

	i = 0;
	length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			length += printspecial(args, str[i + 1]);
			i++;
		}
		else
			length += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (length);
}

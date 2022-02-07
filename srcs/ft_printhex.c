/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsedat <vsedat@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 12:34:42 by vsedat            #+#    #+#             */
/*   Updated: 2022/02/05 13:11:21 by vsedat           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

int	ft_hex_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_hex(unsigned int num, const char type)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, type);
		ft_put_hex(num % 16, type);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (type == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (type == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hex(unsigned int num, const char type)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(num, type);
	return (ft_hex_len(num));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsedat <vsedat@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:15:18 by vsedat            #+#    #+#             */
/*   Updated: 2021/11/16 14:43:05 by vsedat           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	skip_spaces(const char *p, int i)
{
	while (p[i] == ' ')
		i++;
	return (i);
}

int	is_principal(char flag)
{
	if (flag == 's' || flag == 'd' || flag == 'b' || flag == 'S' || flag == 'o'
		|| flag == 'X' || flag == 'x' || flag == 'u' || flag == 'c'
		|| flag == 'p' || flag == '%')
		return (1);
	return (0);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	multipleflags(char *chain)
{
	int	i;
	int	nbflags;

	i = 0;
	nbflags = 0;
	while (chain[i])
	{
		if (chain[i] == '-')
			nbflags++;
		i++;
	}
}

int	isvalid(char *chain)
{
	int	i;

	i = ft_strlen(chain) - 1;
	while (i > 0)
	{
		if (is_principal(chain[i]) == 1)
			i--;
		while (chain[i] >= '0' && chain[i] <= '9')
			i--;
		if (chain[i] == '-')
			return (0);
		while (chain[i] == '-' || chain[i] == '0' || chain[i] == '.'
			|| chain[i] == '#' || chain[i] == ' ' || chain[i] == '+')
			i--;
		if (chain[i] == '%')
			return (1);
		else
			return (0);
	}
}

char	*expression(const char *p, int start, int end)
{
	char	*chain;
	int		i;

	*chain = malloc((end - start + 1) * sizeof(char));
	i = 0;
	while (start + i < end)
	{
		chain[i] = p[start + i];
		i++;
	}
	chain[i] = 0;
	if (isvalid(chain) == 1)
		return (chain);
	else
		return (0);
}

int	ft_printf(const char *p, ...)
{
	va_list	va;
	int		nbprint;
	int		i;
	int		start;
	int		end;

	va_start(va, p);
	i = 0;
	nbprint = 0;
	while (p[i])
	{
		if (p[i] == '%')
		{
			start = i;
			while (is_principal(p[i]) == 0)
				i++;
			end = i;
			if (expression(p, start, end) == 0)
			{
				i = start;
				ft_putchar_fd(p[i], 1);
				i++;
			}
			else
			{
				fonciton_de_valentin(expression(p, start, end));
				i++;
			}
		}
		else
		{
			ft_putchar_fd(p[i++], 1);
			nbprint++;
		}
	}
	return (nbprint);
}

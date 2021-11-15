/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsedat <vsedat@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:15:18 by vsedat            #+#    #+#             */
/*   Updated: 2021/11/15 18:30:51 by vsedat           ###   ########lyon.fr   */
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
	int	nbflag;
	
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
		if (chain[i] == 's' || chain[i] == 'd' || chain[i] == 'b' || chain[i] == 'S' || chain[i] == 'o' || chain[i] == 'X' 
			|| chain[i] == 'x' || chain[i] == 'u' || chain[i] == 'c' || chain[i] == 'p' || chain[i] == '%')
			i--;
		while (chain[i] >= '0' && chain[i] <= '9')
			i--;
		while (chain[i] == '-' || chain[i] == '0' || chain[i] == '.' || chain[i] == '#' || chain[i] == ' ' || chain[i] == '+')
			i--;
		
		
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
	return (chain);
}

int	ft_printf(const char *p, ...)
{
	int	nbprint;
	int	i;
	int	start;
	int	end;

	i = 0;
	nbprint = 0;
	while (p[i])
	{
		if (p[i] == '%')
		{
			start = i;
			while (p[i] != 's' && p[i] != 'd' && p[i] != 'b' && p[i] != 'S' && p[i] != 'o'
				&& p[i] != 'x' && p[i] != 'u' && p[i] != 'c' && p[i] != 'p' && p[i] != '%' && p[i] != 0)
				i++;
			end = i;
			expression(p, start, end);
		}
		else
		{
			ft_putchar_fd(p[i++], 1);
			nbprint++;
		}
	}
	return (nbprint);
}

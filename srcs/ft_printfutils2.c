/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsedat <vsedat@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 13:13:21 by vsedat            #+#    #+#             */
/*   Updated: 2022/02/05 13:15:50 by vsedat           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

int	size(int long ln)
{
	int	s;

	s = 1;
	if (ln < 0)
	{
		s++;
		ln *= -1;
	}
	while (ln >= 10)
	{
		ln /= 10;
		s++;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char		*a;
	int			i;
	int long	ln;

	ln = n;
	i = 0;
	a = malloc((size(ln) + 1) * sizeof(char));
	if (!a)
		return (0);
	if (ln < 0)
	{
		a[0] = '-' + (0 * i++);
		ln *= -1;
	}
	i += size(ln) - 1;
	while (ln >= 10)
	{
		a[i] = (ln % 10) + '0';
		ln /= 10;
		i--;
	}
	a[i] = ln + '0';
	ln = n;
	a[size(ln)] = 0;
	return (a);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}


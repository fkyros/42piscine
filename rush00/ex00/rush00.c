/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:23:39 by gade-oli          #+#    #+#             */
/*   Updated: 2022/07/10 21:19:16 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	nx;
	int	ny;

	nx = 1;
	ny = 1;
	while (ny <= y)
	{
		while (nx <= x)
		{
			if ((nx == 1 && ny == 1) || (nx == 1 && ny == y))
				ft_putchar('o');
			else if ((nx == x && ny == 1) || (nx == x && ny == y))
				ft_putchar('o');
			else if ((ny == 1 || ny == y) && (nx != 1 || nx != x))
				ft_putchar('-');
			else if ((ny != 1 || ny != y) && (nx == 1 || nx == x))
				ft_putchar('|');
			else
				ft_putchar(' ');
			nx++;
		}
		nx = 1;
		ny++;
		ft_putchar('\n');
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:08:22 by gade-oli          #+#    #+#             */
/*   Updated: 2022/07/28 18:27:34 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_numbers(void)
{
	int		a;
	char	c;

	a = 0;
	while (a < 10)
	{
		c = a + '0';
		write(1, &c, 1);
		a++;
	}
}

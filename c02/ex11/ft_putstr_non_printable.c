/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:26:54 by gade-oli          #+#    #+#             */
/*   Updated: 2022/07/21 13:01:36 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int		n;
	char	a;

	n = 0;
	while (str[n] != '\0')
	{
		if (!(str[n] >= 32 && str[n] <= 126))
		{
			write(1, "\\", 1);
			a = "0123456789abcdef"[str[n] / 16];
			write(1, &a, 1);
			a = "0123456789abcdef"[str[n] % 16];
			write(1, &a, 1);
		}
		else
			write(1, &str[n], 1);
		n++;
	}
}
/*
#include <stdio.h>
int main()
{
	char b[2];
	b[0] = 127;
	b[1] = '\0';
	char a[] = "Coucou\etu vas bien ?";
	ft_putstr_non_printable(b);
}
*/

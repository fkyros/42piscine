/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:14:46 by gade-oli          #+#    #+#             */
/*   Updated: 2022/07/19 22:06:59 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	n;
	int	b;

	n = 0;
	b = 1;
	if (*str == '\0')
		return (1);
	while (b == 1 && str[n] != '\0')
	{
		if (!(str[n] >= 'a' && str[n] <= 'z'))
			b = 0;
		n++;
	}
	return (b);
}
/*
#include <stdio.h>
int	main(void)
{
	char a[10] = "HOLA eLor";
	printf("%d\n", ft_is_lowercase(a));
}*/

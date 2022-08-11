/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:18:44 by gade-oli          #+#    #+#             */
/*   Updated: 2022/07/23 18:36:19 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n'
		|| c == '\v' || c == '\f'
		|| c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	n;
	int	sign;
	int	num;

	num = 0;
	sign = 0;
	n = 0;
	while (ft_isspace(str[n]))
		n++;
	while (str[n] == '-' || str[n] == '+')
	{
		if (str[n] == '-')
			sign++;
		n++;
	}
	while (str[n] >= '0' && str[n] <= '9')
	{
		num *= 10;
		num = num + (str[n] - '0');
		n++;
	}
	if (sign % 2 != 0)
		num *= -1;
	return (num);
}
/*
#include <stdio.h>
int	main(void)
{
	char *a = "   	 --+-12";
	printf("%d\n", ft_atoi(a));
}*/

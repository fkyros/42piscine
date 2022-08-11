/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:11:11 by gade-oli          #+#    #+#             */
/*   Updated: 2022/07/25 11:46:55 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				ok;

	ok = 0;
	i = 0;
	while (i < n && ok == 0 && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] > s2[i])
			ok = 1;
		else if (s1[i] < s2[i])
			ok = -1;
		i++;
	}
	return (ok);
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char pepe[] = "pepe";
	char paco[] = "pepa";
	printf("%d\n%d\n", strncmp(pepe, paco, 4), ft_strncmp(pepe, paco, 4));
}*/

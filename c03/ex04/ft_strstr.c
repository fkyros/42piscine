/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:38:33 by gade-oli          #+#    #+#             */
/*   Updated: 2022/07/24 16:32:46 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	find(char *str, char *to_find, int j, int n)
{
	int	i;

	i = 0;
	while (str[j] == to_find[i] && to_find[i] != '\0')
	{
		i++;
		j++;
	}
	if (n == i)
		return (1);
	else
		return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	j;
	int	nailed;
	int	n;

	nailed = 0;
	j = 0;
	n = 0;
	if (*to_find == '\0')
		return (str);
	while (to_find[n] != '\0')
		n++;
	while (nailed == 0 && str[j] != '\0')
	{
		if (str[j] == *to_find)
			nailed = find(str, to_find, j, n);
		j++;
	}
	if (nailed == 0)
		return (0);
	else
		return (str + j - 1);
}
/*
#include <stdio.h>
int	main(void)
{
	char foo[40] = "mira mi anodado, excitante anol";
	char bar[4] = "dad";
	printf("%s\n", ft_strstr(foo, bar));
}*/

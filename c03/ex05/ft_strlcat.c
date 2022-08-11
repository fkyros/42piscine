/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:59:16 by gade-oli          #+#    #+#             */
/*   Updated: 2022/07/24 16:57:43 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dlen;

	dlen = ft_strlen(dest);
	j = dlen;
	i = 0;
	if (size <= dlen || size == 0)
		return (ft_strlen(src) + size);
	while (i < (size - dlen - 1) && src[i] != '\0')
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dlen + ft_strlen(src));
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char dest[11] = "holiwi";
	char src[4] = "uwu";
	//printf("%lu\n", strlcat(dest, src, 10));
	printf("%u\n", ft_strlcat(dest, src, 10));
	printf("dest: %s\n", dest);
}*/

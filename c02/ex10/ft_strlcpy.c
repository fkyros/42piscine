/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:39:15 by gade-oli          #+#    #+#             */
/*   Updated: 2022/07/19 11:40:37 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	n;

	n = 0;
	if (size > 0)
	{
		while (src[n] != '\0' && n < size - 1)
		{
			dest[n] = src[n];
			n++;
		}
		dest[n] = '\0';
	}
	while (src[n] != '\0')
		n++;
	return (n);
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
	char a[] = "hola pepe";
	char b[10];
	printf("%u\n%lu\n", ft_strlcpy(b, a, 5), strlcpy(b,a,5));

} */

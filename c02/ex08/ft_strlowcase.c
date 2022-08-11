/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:04:45 by gade-oli          #+#    #+#             */
/*   Updated: 2022/07/19 11:12:13 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
	{
		if (str[n] >= 'A' && str[n] <= 'Z')
			str[n] += 32;
		n++;
	}
	return (str);
}

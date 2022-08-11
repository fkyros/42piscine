/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:07:13 by gade-oli          #+#    #+#             */
/*   Updated: 2022/07/15 12:38:44 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	upcase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

char	lowcase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int	letter(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	n;

	n = 1;
	str[0] = upcase(str[0]);
	while (str[n] != '\0')
	{
		if (!letter(str[n - 1]) && !number(str[n - 1]))
			str[n] = upcase(str[n]);
		else
			str[n] = lowcase(str[n]);
		n++;
	}
	return (str);
}

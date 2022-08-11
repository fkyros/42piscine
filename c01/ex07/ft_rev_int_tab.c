/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:57:45 by gade-oli          #+#    #+#             */
/*   Updated: 2022/07/12 16:17:57 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	n;

	n = 0;
	while ((tab + n) < (tab + size))
	{
		ft_swap(tab + n, tab + size - 1);
		n++;
		size--;
	}
}

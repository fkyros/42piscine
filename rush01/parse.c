/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 18:00:47 by guisanch          #+#    #+#             */
/*   Updated: 2022/07/17 18:00:53 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	parse(char *a, int **rows, int **col)
{
	int	i;
	int	max;
	int valr;
	int valc;

	i = 0;
	max = ft_check (a);
	valr = check_row_col(rows);
	valc = check_row_col(col);

	if (max == 16)
	{
		rellenar(a, col, i);
		rellenar(a, rows, i);
	}
	else if (max != 16 || valc != 1 || valr != 1)
		write(2, "Error: No se puede resolver.", 28);
}

int	ft_check(char *a)
{
	int	i;

	i = 0;
	while (a[i] != '\0')
	{
		if (a[i] < 5 && a[i] > 0)
			cont++;
		else
			return (0);
		i += 2;
	}
	return (cont);
}

void	rellenar(char *a, int **src, int i)
{
	int	j;
	int	x;

	j = 0;
	while (j < 2)
	{
		x = 0;
		while (x < 4)
		{
			src[j][x] = a[i];
			x++;
			i += 2;
		}
		j++;
	}
}

int	check_row_col(**src)
{
	int i;
	int sum;

	i = 0;

	while (i < 4)
	{
		sum = src[0][i] + src[1][i];
		if (sum > 5  || sum < 3)
			return (0);
	}
	return (1);
}
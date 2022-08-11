/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 13:11:30 by gade-oli          #+#    #+#             */
/*   Updated: 2022/07/17 18:48:31 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	min_number(int *row)
{
	int num;
	int i;

	i = 0;
	num = 1;
	while (i < 4)
	{
		if (row[i] != 0)
		{
			if (row[i] == num)
				num++;
		}
		i++;
	}
	if (num > 4)
		return (1);
	return (num);
}

void init_matrix(int **matrix)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
			matrix[i][j] = 0;
		j++;
	}
	i++;
}

int	check_columns(int *line_matrix, int *columns)
{
	int ok;
	int i;

	i = 3;
	ok = 0;
	while (ok == 0 && i > 0)
	{
		if (!(line_matrix[i] < line_matrix[i - 1]))
			ok = 1;
	}
	return (ok);
}

void	populate(int **matrix, int **columns, int **rows)
{
	int	row;
	int	column;
	int	guess;
	int	ok;

	ok = 0;
	row = 0;
	matrix = (int **) malloc(sizeof(int *) * 4 * 4);
	while (ok != 1 && row < 4)
	{
		column = 0;
		while (ok != -1 && column < 4)
		{
			if (rows[row][column] == 4)
			{
				matrix[row][0] = 1;
				matrix[row][1] = 2;
				matrix[row][2] = 3;
				matrix[row][3] = 4;
				column = 4;
			}
			else if (row[row][column] == 1)
			{
				matrix[row][column] = 4;
			}
			else if (matrix[row][column] == 0)
			{
				guess = min_number(matrix[row]);
				ok = min_number(matrix[row]);
			}
			else
			{
				populate(matrix, rows, columns);
			}
			column++;
		}
		if (!check_column(matrix[row], columns))
			ok = 1;
		row++;
	}
}

void	print(int **matrix)
{
	int i;
	int j;
	char temp;

	
	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{	
			temp = matrix[i][j] + '0';
			write(1, &temp, 1);
		}
		write(1, "\n", 1); 
		i++;
	}
}

int	main(int argc, char **argv)
{
	int (*matrix)[4];
	matrix = (int (*)[4]) malloc(4 * 4 * 4);

	int	**columns;
	int **rows;

	// parse(argv[1], columns, rows);
	int columns[2][4] = {{4, 3, 2, 1}, {1, 2, 2, 2}};
	int rows[2][4] = {{4, 3, 2, 1}, {1, 2, 2, 2}};
	init_matrix(matrix);
	populate(matrix, columns, rows);
	if ()
	print(matrix);
	//free(matrix, columns, rows);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:39:22 by gade-oli          #+#    #+#             */
/*   Updated: 2022/07/27 17:54:59 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(char *str);
/*dada una dimension y un mapa visual, ver si está rellena de ceros*/
int	is_sol(t_map map, int row, int col, int n)
{
	int	sol;
	int	old_row;
	int	old_col;

	old_row = row;
	old_col = col;
	sol = 1;
	while (sol == 1 && row < old_row + n)
	{
		while (sol == 1 && col < old_col + n)
		{
			if (map.vmap[row][col] != map.gap)
				sol = 0;
			col++;
		}
		row++;
	}
	return (sol);
}

int	move_map(int dim, int n, int *row, int *col)
{
	if (*row + n >= dim && *col + n >= dim)
		return (0);
	if (*col + n == dim)
	{
		*col = 0;
		*row+=1;
	}
	else
		*col+=1;
	return (1);
}

char **get_file(char *path, int *ncols, int *nline)
{
	int	fd;
	char	c;
	int	nlines;
	int	ncol;
	char	**map;
	int	i;

	fd = open(path, O_RDONLY);
	c = 'a';
	ncol = 0;
	while (read(fd, &c, 1) && c != '\n')
		;
	while (read(fd, &c, 1) > 0 && c != '\n')
		ncol++;
	*ncols = ncol;
	close(fd);
	fd = open(path, O_RDONLY);
	while (read(fd, &c, 1) && c != '\n')
		;
	nlines = 0;
	while (read(fd, &c, 1))
		if(c == '\n')
			nlines++;
	*nline = nlines;
	close(fd);
	i = 0;
	map = (char **) malloc (nlines * sizeof(char *));
	while (i < nlines)
	{
		map[i] = (char *) malloc(ncol * sizeof(char));
		i++;
	}
	return (map);
}

void	fill_vmap(char **mat, char *path)
{
	int		fd;
	int		i;
	int		j;
	char	c;

	fd = open(path, O_RDONLY);
	while (read(fd, &c, 1) > 0 && c != '\n')
		;
	i = 0;
	j = 0;
	while (read(fd, &c, 1) > 0)
	{
		mat[i][j] = c;
		if (c == '\n')
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	close(fd);
}
/*
//dado un FD, devolvemos el nº de lineas y columnas
char	**get_file(char *path)
{
	char	character;
	int		bytes_read;
	int		n;
	char	**buffer;
	int		fd;
	int		nlines;
	int		ncols;

	fd = open(path, O_RDONLY);
	bytes_read = 1;
	n = 0;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, &character, 1);
		if (character == '\n')
		{
			 nlines++;
		}
		ncols++;
		n++;
	}
	printf("n: %d\n", n);
	if (bytes_read < 0)
		return (0); // ERROR AL LEER EL FICHERO
	buffer = (char **) malloc(n * sizeof(char));
	close(fd);
	fd = open(path, O_RDONLY);
	bytes_read = 1;
	while (bytes_read > 0)
		bytes_read = read(fd, &*buffer, n);
	close(fd);
	buffer[n] = '\0';
	printf("%d\n", bytes_read);
	printf("%s\n", buffer);
	if (bytes_read < 0)
		return (0); // ERROR AL LEER EL FICHERO
	printf("SOCORRO");
	return (&*buffer);
}*/

char	*get_first_line(char *path)
{
	int	i;
	int	fd;
	char	c;
	char	*chars;
	char	*info;

	chars = (char *) malloc(13 * sizeof(char));
	info = (char *) malloc(3 * sizeof(char));
	fd =open(path, O_RDONLY);
	i = 0;
	while(read(fd, &c, 1) && c != '\n')
	{
		chars[i] = c;
		i++;
	}
	info[2] = chars[--i];
	info[1] = chars[--i];
	info[0] = chars[--i];
	free(chars);
	return (info);
}
/*
char	**get_vmap(char *buffer, int nlines, int ncols)
{
	char	**vmap;
	int		i;
	int		j;

	i = 0;
	j = 0;
	vmap = (char **) malloc(nlines * sizeof(char *));
	while (i < nlines)
	{
		vmap[i] = (char *) malloc(ncols * sizeof(char));
		i++;
	}
	i = 0;
	while (*buffer != '\0')
	{
		if (*buffer == '\n')
		{
			i++;
			j = 0;
		}
		else
		{
			vmap[i][j] = *buffer;
			j++;
		}
		buffer++;
	}
	return (vmap);
}*/

t_map	create_map(char *path)
{
	t_map	map;
	char	*chars;

	map.vmap = get_file(path, &map.ncols, &map.nlines); //poner el error
	fill_vmap(map.vmap, path);
	chars = get_first_line(path);
	map.gap = chars[2];
	map.obs = chars[1];
	map.sq = chars[0];
	return (map);
}

void	print_map(char **vmap)
{
	int	i;
	int	j;

	i = 0;
	while (vmap[i] != '\0')
	{
		j = 0;
		while (vmap[i][j] != '\0')
		{
			write(1, &vmap[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	fill_sq(t_map map, int row, int col, int n)
{
	int old_col;
	int	old_row;

	old_row = row;
	old_col = col;
	while (row < n + old_row)
	{
		while (col < n + old_col)
		{
			map.vmap[row][col] = map.sq;
			col++;
		}
		col = old_col;
		row++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	(void)argc;
	t_map map = create_map(argv[1]);
	print_map(map.vmap);
	while(map.vmap)
		free(map.vmap[i++]);
}

/*
int	main(int argc, char **argv)
{
	t_map	map;
	int		*row;
	int		*col;
	int		n;
	int		res;

	(void)argc;
	res = 0;
	row = 0;
	col = 0;
	map = create_map(argv[1]);
	if (map.vmap[0] == '\0')
		write(1, "map error\n", 10);
	n = map.nlines;
	while (n > 1 && res == 0)
	{
		res = is_sol(map, *row, *col, n);
		if (res == 0)
		{
			if (move_map(map.nlines, n, row, col) == 0)
			{
				n--;
				*row = 0;
				*col = 0;
			}
		}
		n--;
	}
	if (res == 1)
	{
		fill_sq(map, *row, *col, n);
		print_map(map.vmap);
	}
	else
		write(1,"Error\n", 6);
}*/

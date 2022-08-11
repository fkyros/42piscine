/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albenite <albenite@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 11:22:30 by albenite          #+#    #+#             */
/*   Updated: 2022/07/24 13:53:45 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER_SIZE 1024

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

// ------------------------ESTRUCTURA DEL NODO-----------------------------
typedef struct	s_nodo
{
	struct s_nodo	*ptrPrev;
	int		nofb;
	char	*number;
	char	*desc;
	struct s_nodo	*ptrNext;
} t_nodo;

int	file_len(char *buffer)
{
	int	i;

	i = -1;
	while (buffer[i])
		i++;
	return(i);
}

int		ft_atoi(char *str);
char	*ft_strstr(char *str, char *to_find);
struct s_nodo	*ft_create_dictionary(char *arr);

void	print_list(t_nodo *nodes_list)
{
	int	 i;

	i = -1;
	while (nodes_list[++i].ptrNext)
		printf("n: %s, %s\n", nodes_list[i].number, nodes_list[i].desc);
}	

struct	node ft_create_nodes(char *arr);
//-----------------------------MAIN------------------------------------------
int	main(int argc, char *argv[])
{
	int		fd;
	mode_t	lecture;
	char	*buffer;
	int		bytes_read;
	int		i;
	int		number;
	t_nodo	*nodes_list;
	char	*path;

	if (argc < 2 || argc > 3 || number < 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	lecture = O_RDONLY;
	i = 0;
	number = 0;
	path = "./numbers.dict";
	if (argc == 2)
	{
		fd = open(path, lecture);
		number = ft_atoi(argv[1]);
	}
	if (argc == 3)
	{
		path = argv[1];
		fd = open(path, lecture);
		number = ft_atoi(argv[2]);
	}

	buffer_size = file_len(buffer);

	printf("%d\n", number);
	// para saber que estamos recogiendo bien la info
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
		write(1, buffer, bytes_read);
/*
	while (buffer[i] != '\n')
	{
		printf("%c", buffer[i]);
		i ++;
	}
*/
	nodes_list = ft_create_dictionary(buffer_size);
	print_list(nodes_list);
	return (0);
}
//------------CONTADOR DE LÍNEAS DEL DICCIONARIO = CANTIDAD DE STRUCTS QUE VAMOS A NECESITAR-----
int count_lines(char *file)
{
	int		fd;
	char	buffer;
	int		i;
	int		bytes_read;

	i = 1;
	if ((fd = open(file, O_RDONLY)) < 0)
		return (-1);
	while ((bytes_read = read(fd, &buffer, 1)) > 0)
	{
		if (buffer == '\n')
			i++;
	}
	return (i);
}
//--------------COGER CADA LÍNEA Y METER SUS DATOS EN UN STRUCT----ERRORES--------
struct s_nodo ft_create_node(char *line, t_nodo nodo)
{
	int		i;

	i = 0;
	while (line[i] >= '0' && line[i] <= '9')
	{
		number[i] = line[i];
		i++;
	}
	while (line[i] == ' ' && line[i] )
		i++;
	i = 0;
	while (*line != '\n' && *line != '\0')
	{
		description[i] = *line;
		i++;
		line++;
	}
	node.number = number;
	node.nofb = i;
	node.desc = description;
	return (node);
}

//---------------------------COGEMOS LA ARRAY Y EMPEZAMOS A LEER A PARTIR DE AHÍ----------------
t_nodo *ft_create_dictionary(int buffer_size)
{
	// ALLOCATE SUMMATION OF (SIZE OF STRUCT (take into account size of lines)*(NUMBER OF LINES)
	t_nodo	*nodo;
	int		i;
	int		j;
	char	buffer[buffer_size];
	int		bytes_read;
	int		fd;
	char	*line;
	
	fd = open("./numbers.dict", O_RDONLY);
	//?
	if ((bytes_read = read(fd, buffer, BUFFER_SIZE)) < 0)
		return (0);
	i = 0;
	while (buffer[i] && buffer[j])
	{
		if (buffer[j] == '\n')
		{
			//copia desde el numero hasta \n
			line = (char *) malloc (sizeof(char) * (j - i - 1))
			*line = ft_strncpy(line, buffer, j - i - 1);
			nodo = (t_nodo *) malloc (sizeof(nodo));
			nodo = ft_create_node(nodo, line);
			i = j;
		}
		j++;
	}
	return (nodes);
}

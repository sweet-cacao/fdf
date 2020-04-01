/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 20:58:26 by gstarvin          #+#    #+#             */
/*   Updated: 2020/03/08 20:09:47 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_hight(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	if ((fd = open(file_name, O_RDONLY, 0)) == -1)
		exit(ft_printf("Incorrect file\n"));
	height = 0;
	while (get_next_line(fd, &line) == 1)
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int		get_width(char *file_name)
{
	int		width;
	int		fd;
	char	*line;
	char	**line2;

	width = 0;
	if ((fd = open(file_name, O_RDONLY, 0)) == -1)
		exit(ft_printf("Incorrect file\n"));
	if (get_next_line(fd, &line) != 1)
		exit(ft_printf("Incorrect file\n"));
	if (!(line2 = ft_strsplit(line, ' ')))
		exit(ft_printf("Malloc error, no memory\n"));
	fd = 0;
	while (line2[fd])
	{
		width++;
		free(line2[fd]);
		fd++;
	}
	free(line2);
	line2 = NULL;
	free(line);
	return (width);
}

void	fill_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

	if (!(nums = ft_strsplit(line, ' ')))
		exit(ft_printf("Malloc error, no memory\n"));
	check_map(nums);
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
	nums = NULL;
}

void	memory_z_matrix(t_fdf *data)
{
	int i;

	i = 0;
	if (!(data->z_matrix = (int **)malloc(sizeof(int*) * (data->height + 1))))
		exit(ft_printf("Malloc error, no memory\n"));
	while (i < data->height)
	{
		if (!(data->z_matrix[i++] = (int*)malloc(sizeof(int)
		* (data->width + 1))))
			exit(ft_printf("Malloc error, no memory\n"));
	}
}

void	read_file(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	data->height = get_hight(file_name);
	data->width = get_width(file_name);
	memory_z_matrix(data);
	if ((fd = open(file_name, O_RDONLY, 0)) == -1)
		exit(ft_printf("Incorrect file\n"));
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	if (!(line))
		exit(ft_printf("Usage: ./fdf [map]\n"));
	close(fd);
	data->z_matrix[i] = NULL;
}

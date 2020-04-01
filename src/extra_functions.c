/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 20:44:43 by gstarvin          #+#    #+#             */
/*   Updated: 2020/03/08 20:07:27 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_matrix(t_fdf *data)
{
	int i;

	i = 0;
	if (data->z_matrix)
	{
		while (i < data->height)
			free(data->z_matrix[i++]);
		free(data->z_matrix);
	}
}

void	change_shift(int key, t_fdf *data)
{
	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 123)
		data->shift_x -= 10;
	if (key == 124)
		data->shift_x += 10;
}

int		deal_key(int key, t_fdf *data)
{
	change_shift(key, data);
	if (key == 53)
	{
		if (data)
		{
			free(data);
			data = NULL;
			exit(0);
		}
	}
	if (key == 6)
	{
		if (data->z == 0)
			data->z = 1;
		else
			data->z = 0;
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

float	max_f(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	mod_f(float a)
{
	if (a < 0)
		return (a * -1);
	else
		return (a);
}

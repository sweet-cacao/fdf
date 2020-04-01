/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 20:43:23 by gstarvin          #+#    #+#             */
/*   Updated: 2020/03/08 20:11:10 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.7);
	*y = (*x + *y) * sin(0.7) - z;
}

void	make_zoom_shift(t_coord *coord, t_fdf *data, int key)
{
	if (key == 0)
	{
		coord->x *= data->zoom;
		coord->y *= data->zoom;
		coord->x1 *= data->zoom;
		coord->y1 *= data->zoom;
	}
	else
	{
		coord->x += data->shift_x;
		coord->y += data->shift_y;
		coord->x1 += data->shift_x;
		coord->y1 += data->shift_y;
		coord->x_step = coord->x1 - coord->x;
		coord->y_step = coord->y1 - coord->y;
	}
}

void	bresenham(t_coord *coord, t_fdf *data)
{
	float	max;
	int		z;
	int		z1;

	z = data->z_matrix[(int)coord->y][(int)coord->x];
	z1 = data->z_matrix[(int)coord->y1][(int)coord->x1];
	make_zoom_shift(coord, data, 0);
	data->color = (z || z1) ? 0xADD8E6 : 0xffffff;
	if (data->z != 0)
	{
		isometric(&coord->x, &coord->y, z);
		isometric(&coord->x1, &coord->y1, z1);
	}
	make_zoom_shift(coord, data, 1);
	max = max_f(mod_f(coord->x_step), mod_f(coord->y_step));
	coord->x_step /= max;
	coord->y_step /= max;
	while ((int)(coord->x - coord->x1) || (int)(coord->y - coord->y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr,
			coord->x, coord->y, data->color);
		coord->x += coord->x_step;
		coord->y += coord->y_step;
	}
}

void	get_x_y(t_coord *coord, int x, int y, int key)
{
	if (key == 0)
	{
		coord->x = x;
		coord->y = y;
		coord->x1 = coord->x + 1;
		coord->y1 = coord->y;
	}
	else
	{
		coord->x = x;
		coord->y = y;
		coord->x1 = coord->x;
		coord->y1 = coord->y + 1;
	}
}

void	draw(t_fdf *data)
{
	t_coord coord;
	int		x;
	int		y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
			{
				get_x_y(&coord, x, y, 0);
				bresenham(&coord, data);
			}
			if (y < data->height - 1)
			{
				get_x_y(&coord, x, y, 1);
				bresenham(&coord, data);
			}
			x++;
		}
		y++;
	}
}

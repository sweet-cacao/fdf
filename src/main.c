/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 20:58:05 by gstarvin          #+#    #+#             */
/*   Updated: 2020/03/08 20:03:12 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_fdf *data;

	if (argc != 2)
		return (ft_printf("Usage: ./fdf [map]\n"));
	if (!(data = (t_fdf *)malloc(sizeof(t_fdf))))
		return (ft_printf("Malloc error, no memory\n"));
	read_file(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->zoom = 20;
	data->z = 1;
	data->shift_x = 150;
	data->shift_y = 150;
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

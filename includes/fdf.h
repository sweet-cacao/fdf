/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 20:58:21 by gstarvin          #+#    #+#             */
/*   Updated: 2020/03/08 19:54:38 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_TUTORIAL_FDF_H
# define FDF_TUTORIAL_FDF_H

# include "../libft/includes/ft_printf.h"
# include <stdio.h>
# include "../minilibx_macos/mlx.h"
# include <math.h>

typedef struct		s_fdf
{
	int				z;
	int				width;
	int				height;
	int				**z_matrix;
	int				zoom;
	int				color;
	int				shift_x;
	int				shift_y;

	void			*mlx_ptr;
	void			*win_ptr;
}					t_fdf;

typedef struct		s_coord
{
	float			x;
	float			y;
	float			x1;
	float			y1;
	float			x_step;
	float			y_step;

}					t_coord;

void				read_file(char *file_name, t_fdf *data);
void				bresenham(t_coord *coord, t_fdf *data);
void				draw(t_fdf *data);
int					deal_key(int key, t_fdf *data);
float				mod_f(float a);
float				max_f(float a, float b);
void				check_map(char **nums);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:12:56 by gstarvin          #+#    #+#             */
/*   Updated: 2020/02/29 20:09:45 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		count_len_massiv(char **nums)
{
	int i;

	i = 0;
	while (nums[i])
		i++;
	return (i);
}

int		ft_is_number(char *str)
{
	int i;

	i = 0;
	if (str[0] == '0' && str[1] == '0')
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (i == 1 && (str[0] == '-' || str[0] == '+'))
		return (0);
	return (1);
}

void	check_map(char **nums)
{
	char	**tmp;
	int		map_len;
	int		i;

	i = 0;
	map_len = count_len_massiv(nums);
	while (i < map_len)
	{
		tmp = ft_strsplit(nums[i], ',');
		if (!ft_is_number(tmp[0]))
		{
			i = 0;
			while (nums[i])
			{
				free(nums[i]);
				i++;
			}
			free(nums);
			massiv_del(tmp);
			exit(ft_printf("Incorrect map\n"));
		}
		i++;
		massiv_del(tmp);
	}
}

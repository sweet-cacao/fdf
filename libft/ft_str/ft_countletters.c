/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countletters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 10:20:10 by gstarvin          #+#    #+#             */
/*   Updated: 2020/03/09 17:38:31 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countletters(char const *s, char c, size_t i)
{
	size_t letters;

	letters = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i] && s[i] != c)
	{
		letters++;
		i++;
	}
	return (letters);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:39:52 by gstarvin          #+#    #+#             */
/*   Updated: 2020/03/09 17:37:48 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_free(char **str, int w)
{
	while (w >= 0)
	{
		free(str[w]);
		w--;
	}
	free(str);
	return (-1);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**mainarr;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = -1;
	if (!s || !c)
		return (NULL);
	if (!(mainarr = (char **)malloc(sizeof(char *) * (ft_countwds(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		if (ft_countletters(s, c, i) > 0)
			if (!(mainarr[++j] = ft_strnew(ft_countletters(s, c, i))))
				if (ft_free(mainarr, j) == -1)
					return (NULL);
		while (s[i] && s[i] == c)
			i++;
		k = 0;
		while (s[i] && s[i] != c)
			mainarr[j][k++] = s[i++];
	}
	mainarr[++j] = 0;
	return (mainarr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:13:18 by dpeyrat           #+#    #+#             */
/*   Updated: 2020/11/18 12:13:24 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*join;

	i = 0;
	j = -1;
	if (s1 == 0 || s2 == 0)
		return (0);
	while (s1[i])
		i++;
	while (s2[++j])
		i++;
	if (!(join = malloc(i + 1)))
		return (0);
	i = 0;
	j = -1;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[++j])
		join[i + j] = s2[j];
	join[i + j] = 0;
	return (join);
}

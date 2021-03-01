/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:17:56 by dpeyrat           #+#    #+#             */
/*   Updated: 2020/11/18 12:17:58 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_result(char *trim, const char *str, int k, int limit)
{
	int i;

	i = 0;
	while (k <= limit)
	{
		trim[i] = str[k];
		i++;
		k++;
	}
	trim[i] = 0;
	return (trim);
}

static	int		ft_found(char const *str, char const *set, int k)
{
	int j;

	j = 0;
	while (set[j])
	{
		if (str[k] == set[j])
			return (1);
		j++;
	}
	return (0);
}

char			*ft_strtrim(char const *str, char const *set)
{
	int		k;
	char	*trim;
	int		limit;

	k = 0;
	if (str == 0 || set == 0)
		return (0);
	limit = ft_strlen(str);
	while (ft_found(str, set, k))
		k++;
	limit--;
	while (ft_found(str, set, limit) && limit >= 0)
		limit--;
	if (limit == -1)
	{
		if (!(trim = malloc(sizeof(*str))))
			return (0);
	}
	else if (!(trim = malloc((sizeof(*str) * (limit - k + 2)))))
		return (0);
	return (ft_result(trim, str, k, limit));
}

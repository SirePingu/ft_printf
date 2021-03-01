/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:50:11 by dpeyrat           #+#    #+#             */
/*   Updated: 2020/11/18 15:50:13 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*rst;

	if (str == 0 || f == 0)
		return (0);
	i = 0;
	while (str[i])
		i++;
	if (!(rst = malloc(i + 1)))
		return (0);
	i = 0;
	while (str[i])
	{
		rst[i] = (*f)(i, str[i]);
		i++;
	}
	rst[i] = 0;
	return (rst);
}

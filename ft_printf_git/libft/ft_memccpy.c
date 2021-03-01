/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 10:55:07 by dpeyrat           #+#    #+#             */
/*   Updated: 2020/11/17 10:55:08 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int a, size_t n)
{
	unsigned char	c;
	size_t			i;
	unsigned char	*dst2;
	unsigned char	*src2;

	if (dst == 0 || src == 0)
		return (0);
	c = a;
	i = 0;
	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	while (i < n && src2[i] != c)
	{
		dst2[i] = src2[i];
		i++;
	}
	if (i == n)
		return (0);
	dst2[i] = src2[i];
	i++;
	dst = (void *)dst2;
	return (&dst[i]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:25:37 by dpeyrat           #+#    #+#             */
/*   Updated: 2020/12/03 18:25:38 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

int		ft_unsignedintlenbase(unsigned long long nb, int base, int m, char *s)
{
	if (base < 2)
		return (0);
	if (nb == 0 && m == 0 && ft_contains(s, '.'))
		return (0);
	if (nb >= (unsigned int)base)
		return (1 + ft_unsignedintlenbase(nb / base, base, m, s));
	else
		return (1);
}

void	ft_unsignedinthub(unsigned long long n, char *flags)
{
	if (ft_strnstr(flags, "ll", 100))
		ft_unsignedlonglongbase(n, "0123456789", 10);
	else if (ft_strnstr(flags, "l", 100))
		ft_unsignedlongbase((unsigned long)n, "0123456789", 10);
	else if (ft_strnstr(flags, "hh", 100))
		ft_unsignedshortshortbase((unsigned char)n, "0123456789", 10);
	else if (ft_strnstr(flags, "h", 100))
		ft_unsignedshortbase((unsigned short)n, "0123456789", 10);
	else
		ft_unsignedbase((unsigned int)n, "0123456789", 10);
}

int		ft_uint(unsigned long long nb, char *str, int min, int max)
{
	int	size;
	int	tern;

	size = ft_unsignedintlenbase(nb, 10, max, str);
	tern = size;
	if (max > size)
		tern = max;
	if (ft_contains(str, '0') && min > 0 && !ft_contains(str, '.'))
		ft_writexchar(min - tern, '0');
	else if (min > 0)
		ft_writexchar(min - tern, ' ');
	if (max > size)
		ft_writexchar((max - size), '0');
	if (nb != 0 || max != 0 || !ft_contains(str, '.'))
		ft_unsignedinthub(nb, str);
	if (min < 0)
		ft_writexchar(-min - tern, ' ');
	free(str);
	if (min >= tern && min > 0)
		return (min);
	else if (min < 0 && -min >= tern)
		return (-min);
	return (tern);
}

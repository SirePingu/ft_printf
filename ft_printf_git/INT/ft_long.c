/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:00:05 by dpeyrat           #+#    #+#             */
/*   Updated: 2020/12/02 18:00:07 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

void	ft_putlongint(long int nb, char *str, int max, int size)
{
	if (nb == LLONG_MIN && !(max > size))
	{
		write(1, "-9223372036854775808", 20);
		return ;
	}
	else if (nb == LLONG_MIN)
	{
		write(1, "9223372036854775808", 19);
		return ;
	}
	if (nb < 0)
	{
		if (!ft_contains(str, '0') && !(max > size))
			write(1, "-", 1);
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		ft_putlongint(nb / 10, str, max, size);
		ft_putlongint(nb % 10, str, max, size);
	}
	else
		ft_putchar(nb + '0');
}

int		ft_longlenbase(long int nb, int base)
{
	if (base < 2)
		return (0);
	if (nb == LLONG_MIN)
		nb++;
	if (nb < 0)
		return (1 + ft_longlenbase(-nb, base));
	else if (nb >= base)
		return (1 + ft_longlenbase(nb / base, base));
	else
		return (1);
}

void	ft_writelong(long int nb, char *str, int max, int size)
{
	if (nb >= 0 && ft_contains(str, '+'))
		write(1, "+", 1);
	else if (nb >= 0 && ft_contains(str, ' '))
		write(1, " ", 1);
	if (max > size && nb < 0)
	{
		write(1, "-", 1);
		ft_writexchar((max + 1 - size), '0');
	}
	else if (max > size)
		ft_writexchar((max - size), '0');
	ft_putlongint(nb, str, max, size);
}

int		ft_long(long int nb, char *str, int min, int max)
{
	int		size;
	int		tern;

	if (nb >= 0 && (ft_contains(str, '+') || ft_contains(str, ' ')))
		min--;
	size = ft_longlenbase(nb, 10);
	if (min > (tern = (size >= max ? size : max)))
	{
		if (ft_contains(str, '0') && !ft_contains(str, '-')
			&& !ft_contains(str, '.'))
		{
			if (nb < 0)
				write(1, "-", 1);
			ft_writexchar(min - tern, '0');
		}
		else if (!ft_contains(str, '-'))
			ft_writexchar(min - tern, ' ');
	}
	ft_writelong(nb, str, max, size);
	if (min > tern && ft_contains(str, '-'))
		ft_writexchar(min - tern, ' ');
	return (ft_intwritten(tern, min, str));
}

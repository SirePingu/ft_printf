/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:00:16 by dpeyrat           #+#    #+#             */
/*   Updated: 2020/12/02 18:30:39 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

int		ft_intlen(int nb, int max, char *str)
{
	if (nb == 0 && max == 0 && ft_contains(str, '.'))
		return (0);
	if (nb == -2147483648)
		nb++;
	if (nb < 0)
		return (ft_intlen(-nb, max, str));
	else if (nb >= 10)
		return (1 + ft_intlen(nb / 10, max, str));
	else
		return (1);
}

void	ft_putint(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "2147483648", 10);
		return ;
	}
	if (nb < 0)
		nb = nb * -1;
	if (nb >= 10)
	{
		ft_putint(nb / 10);
		ft_putint(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

void	ft_writeint(int nb, char *str, int max, int size)
{
	if (nb >= 0 && ft_contains(str, '+'))
		write(1, "+", 1);
	else if (nb >= 0 && ft_contains(str, ' '))
		write(1, " ", 1);
	if (nb == 0 && max == 0 && ft_contains(str, '.'))
		return ;
	if (max > size)
		ft_writexchar((max - size), '0');
	ft_putint(nb);
}

int		ft_intwritten(int tern, int min, char *flags)
{
	if (min < 0)
		min = -min;
	if (tern > min)
		min = tern;
	free(flags);
	return (min);
}

int		ft_int(int nb, char *str, int min, int max)
{
	int		size;
	int		tern;

	size = ft_intlen(nb, max, str);
	if (max > size)
		tern = max;
	else
		tern = size;
	if ((nb >= 0 && (ft_contains(str, '+') || ft_contains(str, ' '))) || nb < 0)
		tern++;
	if (ft_contains(str, '0') && min > 0 && !ft_contains(str, '.') && nb < 0)
		write(1, "-", 1);
	if (ft_contains(str, '0') && min > tern && !ft_contains(str, '.'))
		ft_writexchar(min - tern, '0');
	else if (min > tern)
		ft_writexchar(min - tern, ' ');
	if (nb < 0 && (!ft_contains(str, '0') || min < 0 || ft_contains(str, '.')))
		write(1, "-", 1);
	ft_writeint(nb, str, max, size);
	if (min < 0)
		ft_writexchar((min * -1) - tern, ' ');
	return (ft_intwritten(tern, min, str));
}

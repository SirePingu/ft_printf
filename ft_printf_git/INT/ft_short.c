/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_short.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:59:52 by dpeyrat           #+#    #+#             */
/*   Updated: 2020/12/02 17:59:53 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

int		ft_shortlenbase(short int nb, int base)
{
	if (base < 2)
		return (0);
	if (nb == -32768)
		nb++;
	if (nb < 0)
		return (1 + ft_shortlenbase(-nb, base));
	else if (nb >= base)
		return (1 + ft_shortlenbase(nb / base, base));
	else
		return (1);
}

void	ft_putshortint(short int nb, char *str, int max, int size)
{
	if (nb == -32768 && !(max > size))
	{
		write(1, "-32768", 6);
		return ;
	}
	else if (nb == -32768)
	{
		write(1, "32768", 5);
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
		ft_putshortint(nb / 10, str, max, size);
		ft_putshortint(nb % 10, str, max, size);
	}
	else
		ft_putchar(nb + '0');
}

void	ft_writeshort(short int nb, char *str, int max, int size)
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
	ft_putshortint(nb, str, max, size);
}

int		ft_short(short int nb, char *str, int min, int max)
{
	int		size;
	int		tern;

	if (nb >= 0 && (ft_contains(str, '+') || ft_contains(str, ' ')))
		min--;
	size = ft_shortlenbase(nb, 10);
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
	ft_writeshort(nb, str, max, size);
	if (min > tern && ft_contains(str, '-'))
		ft_writexchar(min - tern, ' ');
	return (ft_intwritten(tern, min, str));
}

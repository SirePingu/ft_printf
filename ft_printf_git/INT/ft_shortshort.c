/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shortshort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:59:42 by dpeyrat           #+#    #+#             */
/*   Updated: 2020/12/02 17:59:43 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

int		ft_shortshortlenbase(char nb, int base)
{
	if (base < 2)
		return (0);
	if (nb == -128)
		nb++;
	if (nb < 0)
		return (1 + ft_shortshortlenbase(-nb, base));
	else if (nb >= base)
		return (1 + ft_shortshortlenbase(nb / base, base));
	else
		return (1);
}

void	ft_putshortshortint(char nb, char *str, int max, int size)
{
	if (nb == -128 && !(max > size))
	{
		write(1, "-128", 4);
		return ;
	}
	if (nb == -128)
	{
		write(1, "128", 3);
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
		ft_putshortshortint(nb / 10, str, max, size);
		ft_putshortshortint(nb % 10, str, max, size);
	}
	else
		ft_putchar(nb + '0');
}

void	ft_writeshortshort(char nb, char *str, int max, int size)
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
	ft_putshortshortint(nb, str, max, size);
}

int		ft_shortshort(char nb, char *str, int min, int max)
{
	int		size;
	int		tern;

	if (nb >= 0 && (ft_contains(str, '+') || ft_contains(str, ' ')))
		min--;
	size = ft_shortshortlenbase(nb, 10);
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
	ft_writeshortshort(nb, str, max, size);
	if (min > tern && ft_contains(str, '-'))
		ft_writexchar(min - tern, ' ');
	return (ft_intwritten(tern, min, str));
}

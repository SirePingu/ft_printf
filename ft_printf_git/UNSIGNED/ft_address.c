/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 09:30:12 by dpeyrat           #+#    #+#             */
/*   Updated: 2020/12/04 09:30:13 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

int		ft_addresslen(unsigned long n, int max, char *str)
{
	if (n == 0 && max == 0 && ft_contains(str, '.'))
		return (0);
	if (n >= 16)
		return (1 + ft_addresslen(n / 16, max, str));
	else
		return (1);
}

void	ft_putaddress(unsigned long nb, char *base)
{
	if (nb >= 16)
	{
		ft_putaddress(nb / 16, base);
		ft_putaddress(nb % 16, base);
	}
	else
		ft_putchar(base[nb]);
}

int		ft_address(unsigned long n, char *str, int min, int max)
{
	int	size;
	int tern;

	size = ft_addresslen(n, max, str);
	tern = size;
	if (max > size)
		tern = max;
	tern = tern + 2;
	if (ft_contains(str, '0') && min > 0)
		ft_writexchar(min - tern, '0');
	else if (min > 0)
		ft_writexchar(min - tern, ' ');
	write(1, "0x", 2);
	ft_writexchar(max - size, '0');
	if (n != 0 || max != 0 || !ft_contains(str, '.'))
		ft_putaddress(n, "0123456789abcdef");
	if (min < 0)
		ft_writexchar(-min - tern, ' ');
	free(str);
	if (min >= tern && min > 0)
		return (min);
	else if (min < 0 && -min >= tern)
		return (-min);
	return (tern);
}

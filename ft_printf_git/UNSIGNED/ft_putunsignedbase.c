/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignedbase.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 08:49:46 by dpeyrat           #+#    #+#             */
/*   Updated: 2020/12/04 08:49:48 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

void	ft_unsignedbase(unsigned int nb, char *base, int size)
{
	if (nb >= (unsigned int)size)
	{
		ft_unsignedbase(nb / size, base, size);
		ft_unsignedbase(nb % size, base, size);
	}
	else
		ft_putchar(base[nb]);
}

void	ft_unsignedlonglongbase(unsigned long long nb, char *base, int size)
{
	if (nb >= (unsigned long long)size)
	{
		ft_unsignedlonglongbase(nb / size, base, size);
		ft_unsignedlonglongbase(nb % size, base, size);
	}
	else
		ft_putchar(base[nb]);
}

void	ft_unsignedlongbase(unsigned long nb, char *base, int size)
{
	if (nb >= (unsigned long)size)
	{
		ft_unsignedlongbase(nb / size, base, size);
		ft_unsignedlongbase(nb % size, base, size);
	}
	else
		ft_putchar(base[nb]);
}

void	ft_unsignedshortshortbase(unsigned char nb, char *base, int size)
{
	if (nb >= (unsigned char)size)
	{
		ft_unsignedshortshortbase(nb / size, base, size);
		ft_unsignedshortshortbase(nb % size, base, size);
	}
	else
		ft_putchar(base[nb]);
}

void	ft_unsignedshortbase(unsigned short nb, char *base, int size)
{
	if (nb >= (unsigned short)size)
	{
		ft_unsignedshortbase(nb / size, base, size);
		ft_unsignedshortbase(nb % size, base, size);
	}
	else
		ft_putchar(base[nb]);
}

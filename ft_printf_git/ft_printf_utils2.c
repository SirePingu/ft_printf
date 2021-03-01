/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:05:19 by dpeyrat           #+#    #+#             */
/*   Updated: 2020/12/02 18:05:20 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*find_start_conversion(char *str, int *i)
{
	if (str == 0)
		return (0);
	if (*str == '%')
	{
		*i = (*i) + 1;
		str--;
	}
	while (*str != '%')
	{
		*i = (*i) + 1;
		str--;
	}
	return (str);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

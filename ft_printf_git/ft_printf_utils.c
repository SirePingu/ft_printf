/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 09:20:59 by dpeyrat           #+#    #+#             */
/*   Updated: 2020/12/01 09:21:04 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int		ft_isdigit0(int c)
{
	if (c <= 57 && c >= 49)
		return (1);
	return (0);
}

int		ft_contains(const char *check, char c)
{
	int i;

	if (check == 0)
		return (0);
	i = 0;
	while (check[i])
	{
		if (check[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_removemaxfield(char *str)
{
	int i;
	int j;

	if (str == 0)
		return ;
	i = 0;
	while (str[i] != '.' && str[i] != 0)
		i++;
	if (str[i] == 0)
		return ;
	i++;
	while (ft_isdigit(str[i]))
	{
		j = i;
		while (str[j])
		{
			str[j] = str[j + 1];
			j++;
		}
	}
}

void	ft_removefield(char *str)
{
	int i;
	int j;

	if (str == 0)
		return ;
	i = 0;
	while (!ft_isdigit0(str[i]) && str[i] != 0 && str[i] != '.')
		i++;
	while (ft_isdigit(str[i]))
	{
		j = i;
		while (str[j])
		{
			str[j] = str[j + 1];
			j++;
		}
	}
	ft_removemaxfield(str);
}

void	ft_writexchar(int n, char c)
{
	int i;

	i = 0;
	while (i < n)
	{
		write(1, &c, 1);
		i++;
	}
}

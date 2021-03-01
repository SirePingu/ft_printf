/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displaystring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 15:02:43 by dpeyrat           #+#    #+#             */
/*   Updated: 2020/12/03 15:02:45 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

void	ft_putstrx(char *str, int max)
{
	int i;

	i = 0;
	while (str[i] && i < max)
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		ft_displaystr(char *str, char *flags, int min, int max)
{
	int	size;
	int tern;

	size = ft_strlen(str);
	if (max < 0)
		max = size;
	if (max < size && ft_contains(flags, '.'))
		tern = max;
	else
		tern = size;
	if (ft_contains(flags, '0') && min > 0)
		ft_writexchar(min - tern, '0');
	else if (min > 0)
		ft_writexchar(min - tern, ' ');
	ft_putstrx(str, tern);
	if (min < 0)
		ft_writexchar(-min - tern, ' ');
	free(flags);
	if (min >= tern && min > 0)
		return (min);
	else if (min < 0 && -min >= tern)
		return (-min);
	return (tern);
}

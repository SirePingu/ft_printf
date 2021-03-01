/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:00:14 by dpeyrat           #+#    #+#             */
/*   Updated: 2020/12/03 14:00:16 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

void	ft_setminmaxchar(int *min, int *max, char *flags)
{
	int i;

	i = 0;
	if (!(*min))
	{
		while (!ft_isdigit0(flags[i]) && flags[i] != '.' && flags[i] != 0)
			i++;
		if (flags[i] != '.' && flags[i] != 0)
			*min = ft_atoi(&flags[i]);
	}
	while (flags[i] != '.' && flags[i] != 0)
		i++;
	if (!(*max) && flags[i] == '.')
		*max = ft_atoi(&flags[i + 1]);
	if (ft_contains(flags, '-') && *min > 0 && flags[i + 1] != '*')
		*min = *min * -1;
}

void	ft_va_argchar(int *m, int *a, va_list *ap, char *f)
{
	int i;

	i = 0;
	while (f[i] && f[i] != '.' && f[i] != '*')
		i++;
	if (f[i] == '*')
		*m = va_arg(*ap, int);
	while (f[i] != '.' && f[i])
		i++;
	if (f[i] == '.')
	{
		i++;
		if (f[i] == '*')
			*a = va_arg(*ap, int);
	}
}

int		ft_display_char(char c, char *flags, int min, int max)
{
	int	tern;

	tern = 1;
	if (max != 0)
		tern = max;
	if (ft_contains(flags, '0') && min > 0)
		ft_writexchar(min - tern, '0');
	else if (min > 0)
		ft_writexchar(min - tern, ' ');
	ft_writexchar(max - 1, '0');
	ft_putchar(c);
	if (min < 0)
		ft_writexchar(-min - tern, ' ');
	free(flags);
	if (min > 0 && min >= tern)
		return (min);
	else if (min < 0 && -min >= tern)
		return (-min);
	return (tern);
}

int		ft_char(int c, char *str, va_list *ap)
{
	int		i;
	char	*flags;
	int		min;
	int		max;

	i = 0;
	min = 0;
	max = 0;
	str = find_start_conversion(str, &i);
	if (!(flags = ft_substr(str, 1, i)))
		return (-1);
	ft_va_argchar(&min, &max, ap, flags);
	c = va_arg(*ap, int);
	ft_setminmaxchar(&min, &max, flags);
	ft_removefield(flags);
	return (ft_display_char((char)c, flags, min, max));
}

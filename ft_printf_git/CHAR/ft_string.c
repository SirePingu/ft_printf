/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:29:51 by dpeyrat           #+#    #+#             */
/*   Updated: 2020/12/03 15:23:06 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

void	ft_setminmaxstr(int *min, int *max, char *flags)
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
	if (!(*max) && flags[i] == '.' && flags[i + 1] != '*')
		*max = ft_atoi(&flags[i + 1]);
	if (ft_contains(flags, '-') && *min > 0)
		*min = *min * -1;
}

void	ft_va_argstr(int *m, int *a, va_list *ap, char *f)
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

int		ft_string(char *s, char *str, va_list *ap)
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
	ft_va_argstr(&min, &max, ap, flags);
	s = va_arg(*ap, char *);
	if (s == 0)
		s = "(null)";
	ft_setminmaxstr(&min, &max, flags);
	ft_removefield(flags);
	return (ft_displaystr(s, flags, min, max));
}

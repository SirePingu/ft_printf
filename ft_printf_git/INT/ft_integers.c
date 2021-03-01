/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:32:51 by dpeyrat           #+#    #+#             */
/*   Updated: 2020/12/02 16:32:53 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

void	ft_setminmaxint(long long int *min, long long int *max, char *flags)
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

void	ft_va_argint(long long int *m, long long int *a, va_list *ap, char *f)
{
	int i;

	i = 0;
	while (f[i] && f[i] != '.' && f[i] != '*')
		i++;
	if (f[i] == '*')
		*m = va_arg(*ap, long long int);
	while (f[i] != '.' && f[i])
		i++;
	if (f[i] == '.')
	{
		i++;
		if (f[i] == '*')
			*a = va_arg(*ap, long long int);
	}
}

int		ft_integers(long long int n, char *str, va_list *ap)
{
	int				i;
	char			*flags;
	long long int	min;
	long long int	max;

	i = 0;
	min = 0;
	max = 0;
	str = find_start_conversion(str, &i);
	if (!(flags = ft_substr(str, 1, i)))
		return (-1);
	ft_va_argint(&min, &max, ap, flags);
	n = va_arg(*ap, long long int);
	ft_setminmaxint(&min, &max, flags);
	ft_removefield(flags);
	if (ft_strnstr(flags, "ll", 100))
		return (ft_longlong(n, flags, (int)min, (int)max));
	else if (ft_strnstr(flags, "l", 100))
		return (ft_long((long)n, flags, (int)min, (int)max));
	else if (ft_strnstr(flags, "hh", 100))
		return (ft_shortshort((char)n, flags, (int)min, (int)max));
	else if (ft_strnstr(flags, "h", 100))
		return (ft_short((short int)n, flags, (int)min, (int)max));
	else
		return (ft_int((int)n, flags, (int)min, (int)max));
}

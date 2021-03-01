/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:02:40 by dpeyrat           #+#    #+#             */
/*   Updated: 2020/12/04 12:03:24 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

void	ft_setminmaxu(int *min, int *max, char *flags)
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

void	ft_va_argu(int *m, int *a, va_list *ap, char *f)
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

int		ft_unsigned(unsigned long long n, char *str, va_list *ap)
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
	ft_va_argu(&min, &max, ap, flags);
	n = va_arg(*ap, unsigned long long);
	ft_setminmaxu(&min, &max, flags);
	ft_removefield(flags);
	if (ft_contains(flags, 'u'))
		return (ft_uint(n, flags, min, max));
	else if (ft_contains(flags, 'x'))
		return (ft_hexlower(n, flags, min, max));
	else if (ft_contains(flags, 'X'))
		return (ft_hexupper(n, flags, min, max));
	else if (ft_contains(flags, 'p'))
		return (ft_address((unsigned long)n, flags, min, max));
	return (-1);
}

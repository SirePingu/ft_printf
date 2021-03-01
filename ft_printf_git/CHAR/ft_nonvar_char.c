/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nonvar_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:06:21 by dpeyrat           #+#    #+#             */
/*   Updated: 2021/01/06 14:06:23 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

int		ft_nonvar_char(char c, char *str, va_list *ap)
{
	int		i;
	char	*flags;
	int		min;
	int		max;

	c = *str;
	i = 0;
	min = 0;
	max = 0;
	str = find_start_conversion(str, &i);
	if (!(flags = ft_substr(str, 1, i)))
		return (-1);
	ft_va_argchar(&min, &max, ap, flags);
	ft_setminmaxchar(&min, &max, flags);
	ft_removefield(flags);
	return (ft_display_char((char)c, flags, min, max));
}

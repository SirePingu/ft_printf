/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:50:55 by dpeyrat           #+#    #+#             */
/*   Updated: 2020/11/26 10:50:58 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*ft_find_conversion_type(char *str)
{
	int		i;

	i = 1;
	while (ft_isdigit((int)str[i]))
		i++;
	while (ft_contains("-0 +lh#*", str[i]))
		i++;
	while (ft_isdigit((int)str[i]))
		i++;
	while (ft_contains("-0 +lh#*", str[i]))
		i++;
	if (str[i] == '.')
	{
		i++;
		while (ft_isdigit((int)str[i]) || str[i] == '*')
			i++;
	}
	if (ft_isprint(str[i]))
		return (&str[i]);
	else
		return (0);
}

char	*ft_find_next_conversion(char *str, char *c, int *count)
{
	int		i;
	char	*conversion;

	i = 0;
	if (c != 0)
		str = &c[1];
	while (str[i])
	{
		if (str[i] == '%' && (conversion = ft_find_conversion_type(&str[i])))
			return (conversion);
		else if (str[i] == '%')
			i++;
		else if (str[i])
		{
			*count = *count + 1;
			ft_putchar(str[i]);
		}
		if (str[i])
			i++;
	}
	return (0);
}

int		ft_referal(va_list *ap, char *c, int count)
{
	if (ft_contains("di", *c))
		return (ft_integers(0, c, ap));
	else if (*c == 's')
		return (ft_string(0, c, ap));
	else if (ft_contains("uxXp", *c))
		return (ft_unsigned(0, c, ap));
	else if (*c == 'n')
		return (ft_ptrint(va_arg(*ap, long long *), count));
	else if (*c == 'c')
		return (ft_char(0, c, ap));
	else if (ft_isprint(*c))
		return (ft_nonvar_char(0, c, ap));
	return (-1);
}

int		ft_printf(char *str, ...)
{
	va_list	ap;
	char	*c;
	int		temp;
	int		count;

	count = 0;
	va_start(ap, str);
	c = 0;
	while (1)
	{
		c = ft_find_next_conversion(str, c, &count);
		if (c == 0)
			break ;
		if ((temp = ft_referal(&ap, c, count)) == -1)
			return (-1);
		else
			count += temp;
	}
	va_end(ap);
	return (count);
}

int main()
{
	int i = 134986;
	ft_printf("%-30x\n", i);
	printf("%-30x\n", i);
}

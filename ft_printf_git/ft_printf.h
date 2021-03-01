/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 08:31:32 by dpeyrat           #+#    #+#             */
/*   Updated: 2020/12/03 08:31:33 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include <float.h>

int		ft_printf(char *str, ...);
int		ft_contains(const char *check, char c);
void	ft_removemaxfieldwidth(char *str);
void	ft_writexchar(int n, char c);
int		ft_isdigit0(int c);
int		ft_integers(long long int n, char *str, va_list *ap);
int		ft_intlenbase(int nb, int base);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_removefield(char *str);
int		ft_shortshort(char nb, char *str, int min, int max);
int		ft_short(short int nb, char *str, int min, int max);
int		ft_longlong(long long int nb, char *str, int min, int max);
int		ft_long(long int nb, char *str, int min, int max);
int		ft_int(int nb, char *str, int min, int max);
char	*find_start_conversion(char *str, int *i);
int		ft_char(int c, char *str, va_list *ap);
int		ft_string(char *s, char *str, va_list *ap);
int		ft_displaystr(char *str, char *flags, int min, int max);
int		ft_unsigned(unsigned long long n, char *str, va_list *ap);
int		ft_uint(unsigned long long nb, char *str, int min, int max);
void	ft_unsignedbase(unsigned int nb, char *base, int size);
void	ft_unsignedlonglongbase(unsigned long long nb, char *base, int size);
void	ft_unsignedlongbase(unsigned long nb, char *base, int size);
void	ft_unsignedshortshortbase(unsigned char nb, char *base, int size);
void	ft_unsignedshortbase(unsigned short nb, char *base, int size);
int		ft_address(unsigned long n, char *str, int min, int max);
int		ft_unsignedintlenbase(unsigned long long nb, int base, int m, char *s);
int		ft_hexlower(unsigned long long nb, char *str, int min, int max);
int		ft_hexupper(unsigned long long nb, char *str, int min, int max);
int		ft_float(double n, char *str, va_list *ap);
int		ft_decimalfloat(double nb, char *str, int min, int max);
void	ft_putdecifloat(double nb, int max, char *str);
double	ft_roundfloat(double nb);
void	ft_putdecifloat2(double nb);
void	ft_roundexpfloat(double nb, int max, char *str);
int		ft_expfloat(double nb, char *str, int min, int max);
void	ft_rounddecipres(double nb, int max, char *str);
void	ft_putdecimalpart(double nb, int max);
int		ft_finddecisize(double nb, char *str, int *max);
int		ft_intwritten(int tern, int min, char *flags);
int		ft_writtenhex(int min, int tern, char *str);
int		ft_ptrint(long long *n, int nb);
int		ft_findroundbig(double nb, char *str, int *max, int *mag);
int		ft_findroundsmall(double nb, char *str, int *max, int *mag);
int		ft_nonvar_char(char c, char *str, va_list *ap);
void	ft_setminmaxchar(int *min, int *max, char *flags);
void	ft_va_argchar(int *m, int *a, va_list *ap, char *f);
int		ft_display_char(char c, char *flags, int min, int max);

#endif

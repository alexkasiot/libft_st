/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_type.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akasiota <akasiota@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 17:26:45 by akasiota      #+#    #+#                 */
/*   Updated: 2023/03/15 18:08:22 by akasiota      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	print_type(va_list *ptr, char c, int *len, int *index)
{
	if (c == 'c')
		return (ft_printf_putchar(va_arg(*ptr, int), len, index));
	else if (c == 's')
		return (ft_printf_putstr(va_arg(*ptr, char *), len, index));
	else if (c == 'p')
		return (ft_printf_putptr(va_arg(*ptr, void *), len, index));
	else if (c == 'd' || c == 'i')
		return (ft_printf_putint(va_arg(*ptr, int), len, index));
	else if (c == 'u')
		return (ft_printf_putuns(va_arg(*ptr, unsigned int), len, index));
	else if (c == 'x')
		return (ft_printf_puthex_low(va_arg(*ptr, unsigned int), len, index));
	else if (c == 'X')
		return (ft_printf_puthex_upp(va_arg(*ptr, unsigned int), len, index));
	else if (c == '%')
		return (ft_printf_putpercent(c, len, index));
	else if (c == 0)
		return (*len);
	return (*len);
}

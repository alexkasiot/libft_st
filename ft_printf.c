/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akasiota <akasiota@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/11 21:03:34 by akasiota      #+#    #+#                 */
/*   Updated: 2023/03/15 18:10:33 by akasiota      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_printf(const char *s, ...)
{
	va_list			ptr;
	int				len;
	int				index;

	len = 0;
	index = 0;
	va_start(ptr, s);
	while (s[index] != 0)
	{
		while (s[index] == '%')
		{
			index++;
			if (print_type(&ptr, s[index], &len, &index) < 0)
				return (va_end(ptr), -1);
		}
		if (s[index] == 0)
			return (va_end(ptr), len);
		if (write(1, &s[index], 1) < 0)
			return (va_end(ptr), -1);
		index++;
		len++;
	}
	return (va_end(ptr), len);
}

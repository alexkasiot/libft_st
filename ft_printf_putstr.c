/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_putstr.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: akasiota <akasiota@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/11 21:26:35 by akasiota      #+#    #+#                 */
/*   Updated: 2023/03/15 18:10:59 by akasiota      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_printf_putstr(char *s, int *len, int *index)
{
	if (s == NULL)
	{
		if (write(1, "(null)", 6) < 0)
			return (-1);
		*len = *len + 6;
		*index = *index + 1;
		return (*len);
	}
	if (*s != 0)
	{
		if (write(1, s, ft_strlen(s)) < 0)
			return (-1);
		*len = *len + ft_strlen(s);
		*index = *index + 1;
		return (*len);
	}
	*index = *index + 1;
	return (*len);
}

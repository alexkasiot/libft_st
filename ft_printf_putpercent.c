/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_putpercent.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akasiota <akasiota@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/12 00:42:31 by akasiota      #+#    #+#                 */
/*   Updated: 2023/03/15 18:11:53 by akasiota      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_printf_putpercent(char percent, int *len, int *index)
{
	if (percent == '%')
	{
		if (write(1, &percent, 1) < 0)
			return (-1);
		*len = *len + 1;
		*index = *index + 1;
	}
	return (*len);
}

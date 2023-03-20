/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_putchar.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: akasiota <akasiota@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/11 21:03:10 by akasiota      #+#    #+#                 */
/*   Updated: 2023/03/15 18:12:37 by akasiota      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_printf_putchar(int c, int *len, int *index)
{
	if (write(1, &c, 1) < 0)
		return (-1);
	*len = *len + 1;
	*index = *index + 1;
	return (*len);
}

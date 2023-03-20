/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_puthex_low.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akasiota <akasiota@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/12 00:22:09 by akasiota      #+#    #+#                 */
/*   Updated: 2023/03/15 18:12:33 by akasiota      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	hexlen(unsigned int u)
{
	int	i;

	i = 1;
	while (u >= 16)
	{
		u = u / 16;
		i++;
	}
	return (i);
}

static void	fill_hexadecimal(char *hexadecimal, unsigned int u, int length)
{
	while (length > 0)
	{
		if (u >= 16)
		{
			if ((u % 16) > 9)
				hexadecimal[length - 1] = (u % 16) + 87;
			else
				hexadecimal[length - 1] = (u % 16) + 48;
			u = u / 16;
		}
		else if (u > 9)
			hexadecimal[length - 1] = (u % 16) + 87;
		else
			hexadecimal[length - 1] = (u % 16) + 48;
		length--;
	}
}

int	ft_printf_puthex_low(unsigned int u, int *len, int *index)
{
	char		*hexadecimal;
	int			length;

	length = hexlen(u);
	hexadecimal = ft_calloc(length + 1, sizeof(char));
	if (hexadecimal == NULL)
		return (-1);
	fill_hexadecimal(hexadecimal, u, length);
	if (write(1, hexadecimal, ft_strlen(hexadecimal)) < 0)
		return (free(hexadecimal), -1);
	*len = *len + ft_strlen(hexadecimal);
	*index = *index + 1;
	return (free(hexadecimal), *len);
}

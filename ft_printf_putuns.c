/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_putuns.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: akasiota <akasiota@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/11 23:59:58 by akasiota      #+#    #+#                 */
/*   Updated: 2023/03/15 18:10:49 by akasiota      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	intlen(unsigned int u)
{
	int	length;

	length = 1;
	while (u >= 10)
	{
		u = u / 10;
		length++;
	}
	return (length);
}

int	ft_printf_putuns(unsigned int u, int *len, int *index)
{
	int		length;
	char	*char_number;

	length = intlen(u);
	char_number = ft_calloc(length + 1, sizeof(char *));
	if (char_number == NULL)
		return (-1);
	while (u >= 10)
	{
		char_number[length - 1] = (u % 10) + 48;
		u = u / 10;
		length--;
	}
	char_number[length - 1] = (u % 10) + 48;
	if (write(1, char_number, ft_strlen(char_number)) < 0)
		return (free(char_number), -1);
	*len = *len + ft_strlen(char_number);
	*index = *index + 1;
	free(char_number);
	return (*len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_putint.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: akasiota <akasiota@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/11 23:25:04 by akasiota      #+#    #+#                 */
/*   Updated: 2023/03/15 18:12:24 by akasiota      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	longlen(long n)
{
	int	length;

	length = 1;
	while (n >= 10)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

static long	check_sign(int i, int *len)
{
	long	n;

	n = i;
	if (n < 0)
	{
		n = n * (-1);
		if (write(1, "-", 1) < 0)
			return (-1);
		*len = *len + 1;
	}
	return (n);
}

int	ft_printf_putint(int i, int *len, int *index)
{
	int		length;
	long	n;
	char	*char_number;

	n = check_sign(i, len);
	if (n == -1)
		return (-1);
	length = longlen(n);
	char_number = ft_calloc(length + 1, sizeof(char *));
	if (char_number == NULL)
		return (-1);
	while (n >= 10)
	{
		char_number[length - 1] = (n % 10) + 48;
		n = n / 10;
		length--;
	}
	char_number[length - 1] = (n % 10) + 48;
	if (write(1, char_number, ft_strlen(char_number)) < 0)
		return (free(char_number), -1);
	*len = *len + ft_strlen(char_number);
	*index = *index + 1;
	free(char_number);
	return (*len);
}

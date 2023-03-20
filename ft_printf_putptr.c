/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_putptr.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: akasiota <akasiota@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/11 21:35:33 by akasiota      #+#    #+#                 */
/*   Updated: 2023/03/15 18:11:35 by akasiota      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ptrlen(uintptr_t p)
{
	int	i;

	i = 1;
	while (p >= 16)
	{
		p = p / 16;
		i++;
	}
	return (i);
}

static int	ft_putptr(uintptr_t p, int length, int *len)
{
	char		*address;

	address = ft_calloc(length + 1, sizeof(char));
	if (address == NULL)
		return (-1);
	while (length > 0)
	{
		if (p >= 16)
		{
			if ((p % 16) > 9)
				address[length - 1] = (p % 16) + 87;
			else
				address[length - 1] = (p % 16) + 48;
			p = p / 16;
		}
		else if (p > 9)
			address[length - 1] = (p % 16) + 87;
		else
			address[length - 1] = (p % 16) + 48;
		length--;
	}
	if (write(1, address, ft_strlen(address)) < 0)
		return (free(address), -1);
	*len = *len + ft_strlen(address);
	return (free (address), *len);
}

int	ft_printf_putptr(void *pointer, int *len, int *index)
{
	int	length;

	length = ptrlen((uintptr_t)pointer);
	if (write(1, "0x", 2) < 0)
		return (-1);
	*len = *len + 2;
	*len = ft_putptr((uintptr_t)pointer, length, len);
	*index = *index + 1;
	return (*len);
}

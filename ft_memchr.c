/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akasiota <akasiota@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 17:35:28 by akasiota      #+#    #+#                 */
/*   Updated: 2023/01/08 17:42:12 by akasiota      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*sub;

	sub = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (sub[i] == (unsigned char)c)
			return ((void *)sub + i);
		else
			i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akasiota <akasiota@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 18:28:46 by akasiota      #+#    #+#                 */
/*   Updated: 2023/01/08 17:42:24 by akasiota      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*s;

	i = 0;
	s = b;
	while (i < len)
	{
		s[i] = (unsigned char) c;
		i++;
	}
	return (b);
}

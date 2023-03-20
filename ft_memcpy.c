/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akasiota <akasiota@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 14:26:49 by akasiota      #+#    #+#                 */
/*   Updated: 2023/01/08 17:42:19 by akasiota      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*cp_d;
	const char		*cp_s;
	size_t			i;

	cp_d = dst;
	cp_s = src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		cp_d[i] = cp_s[i];
		i++;
	}
	return (dst);
}

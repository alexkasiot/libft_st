/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akasiota <akasiota@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 15:59:12 by akasiota      #+#    #+#                 */
/*   Updated: 2023/01/08 17:42:21 by akasiota      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*cp_d;
	const char		*cp_s;
	size_t			i;

	i = -1;
	cp_d = dst;
	cp_s = src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst <= src)
	{
		while (++i < len)
			cp_d[i] = cp_s[i];
	}
	else
	{
		while (++i < len)
			cp_d[len - 1 - i] = cp_s[len - 1 - i];
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akasiota <akasiota@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 20:10:35 by akasiota      #+#    #+#                 */
/*   Updated: 2023/01/08 17:42:46 by akasiota      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i_dst;
	size_t	i_src;
	size_t	i;

	i_dst = ft_strlen(dst);
	i_src = ft_strlen(src);
	i = 0;
	if (dstsize > i_dst)
	{
		while ((src[i] != 0) && (i < (dstsize - i_dst - 1)))
		{
			dst[i + i_dst] = src[i];
			i++;
		}
		dst[i + i_dst] = 0;
		return (i_dst + i_src);
	}
	return (i_src + dstsize);
}

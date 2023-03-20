/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akasiota <akasiota@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 21:03:50 by akasiota      #+#    #+#                 */
/*   Updated: 2023/01/08 17:42:58 by akasiota      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	h;

	i = 0;
	h = 0;
	if (needle[h] == 0)
		return ((char *)haystack);
	while (i < len)
	{
		while ((haystack[i + h] == needle[h]) && (needle[h] != 0) \
				&& ((i + h) < len))
		{
			h++;
			if (needle[h] == 0)
				return ((char *)haystack + i);
		}
		if (haystack[i + h] == 0)
			return (NULL);
		h = 0;
		i++;
	}
	return (NULL);
}

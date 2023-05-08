/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akasiota <akasiota@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 16:34:02 by akasiota      #+#    #+#                 */
/*   Updated: 2023/05/09 01:39:59 by lotse         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	while (i <= len)
	{
		if (s[len - i] == (unsigned char)c)
			return ((char *)s + len - i);
		else
			i++;
	}
	return (NULL);
}

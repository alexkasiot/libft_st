/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akasiota <akasiota@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 15:36:20 by akasiota      #+#    #+#                 */
/*   Updated: 2023/01/08 17:43:05 by akasiota      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	i;
	char	*sub;

	s_len = ft_strlen(s);
	if (len > s_len - start)
		len = s_len - start;
	if (start >= s_len)
	{
		len = 0;
		start = 0;
	}
	sub = ft_calloc((len + 1), sizeof(char));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (s[i + start] != 0 && i < len)
	{
		sub[i] = s[i + start];
		i++;
	}
	return (sub);
}

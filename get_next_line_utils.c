/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: akasiota <akasiota@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/30 13:46:12 by akasiota      #+#    #+#                 */
/*   Updated: 2023/03/15 18:09:49 by akasiota      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_bzero_gnl(void *s, size_t n)
{
	unsigned char	*sub;
	size_t			i;

	i = 0;
	sub = s;
	while (i < n)
	{
		sub[i] = 0;
		i++;
	}
}

void	*ft_calloc_gnl(size_t count, size_t size)
{
	void	*mem;

	mem = malloc(count * size);
	if (mem == NULL)
		return (NULL);
	ft_bzero_gnl(mem, count * size);
	return (mem);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*s_j;
	size_t	i;
	size_t	k;

	if (s1 == NULL || s2 == NULL || (*s1 == 0 && *s2 == 0))
		return (free(s1), free(s2), NULL);
	s_j = ft_calloc_gnl((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (s_j == NULL)
		return (free(s1), free(s2), NULL);
	i = 0;
	k = 0;
	while (s1[i] != 0)
	{
		s_j[i] = s1[i];
		i++;
	}
	while (s2[k] != 0)
	{
		s_j[i] = s2[k];
		k++;
		i++;
	}
	return (free(s1), free(s2), s_j);
}

char	*ft_strchr_gnl(char *s, int c)
{
	size_t	i;
	size_t	len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	while (i <= len)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		else
			i++;
	}
	return (NULL);
}

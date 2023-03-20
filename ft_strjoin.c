/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akasiota <akasiota@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 17:44:24 by akasiota      #+#    #+#                 */
/*   Updated: 2023/01/08 17:42:44 by akasiota      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_1;
	size_t	len_2;
	char	*s_j;
	size_t	i;

	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	s_j = malloc((len_1 + len_2 + 1) * sizeof(char));
	if (s_j == NULL)
		return (NULL);
	i = 0;
	while (*s1 != 0)
	{
		s_j[i] = *s1;
		s1++;
		i++;
	}
	while (*s2 != 0)
	{
		s_j[i] = *s2;
		s2++;
		i++;
	}
	s_j[i] = 0;
	return (s_j);
}

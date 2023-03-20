/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akasiota <akasiota@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 16:47:50 by akasiota      #+#    #+#                 */
/*   Updated: 2023/01/08 17:42:55 by akasiota      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_sub;
	unsigned char	*s2_sub;

	s1_sub = (unsigned char *)s1;
	s2_sub = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((i < (n - 1)) && (s1_sub[i] != 0) && (s2_sub[i] != 0))
	{
		if (s1_sub[i] == s2_sub[i])
			i++;
		else
			break ;
	}
	return (s1_sub[i] - s2_sub[i]);
}

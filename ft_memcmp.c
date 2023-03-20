/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akasiota <akasiota@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 18:13:25 by akasiota      #+#    #+#                 */
/*   Updated: 2023/01/08 17:42:17 by akasiota      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s1_sub;
	const unsigned char	*s2_sub;

	s1_sub = s1;
	s2_sub = s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < (n - 1))
	{
		if (s1_sub[i] == s2_sub[i])
			i++;
		else
			break ;
	}
	return (s1_sub[i] - s2_sub[i]);
}

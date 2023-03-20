/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: akasiota <akasiota@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 13:57:33 by akasiota      #+#    #+#                 */
/*   Updated: 2023/01/08 17:39:34 by akasiota      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_bzero(void *s, size_t n)
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

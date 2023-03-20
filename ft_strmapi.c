/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akasiota <akasiota@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 20:58:01 by akasiota      #+#    #+#                 */
/*   Updated: 2023/01/08 17:42:53 by akasiota      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*sub;
	size_t			len;
	unsigned int	i;

	i = 0;
	len = ft_strlen(s);
	sub = malloc((len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	while (i < len)
	{
		sub[i] = f(i, s[i]);
		i++;
	}
	sub[i] = 0;
	return (sub);
}

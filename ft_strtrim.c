/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akasiota <akasiota@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 18:18:00 by akasiota      #+#    #+#                 */
/*   Updated: 2023/01/08 17:43:02 by akasiota      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/* Check for the characters to trim */
static int	set_chk(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != 0)
	{
		if (set[i] == c)
			return (1);
		else
			i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*sub;
	size_t	i;
	size_t	start;
	size_t	n;

	i = 0;
	n = 0;
	while ((s1[i] != 0) && set_chk(s1[i], set) != 0)
		i++;
	start = i;
	while (s1[i] != 0)
		i++;
	while (i > start && set_chk(s1[i - 1], set) != 0)
		i--;
	sub = malloc((i - start + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	while (n < (i - start))
	{
		sub[n] = s1[start + n];
		n++;
	}
	sub[n] = 0;
	return (sub);
}

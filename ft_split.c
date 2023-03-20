/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: akasiota <akasiota@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 16:08:20 by akasiota      #+#    #+#                 */
/*   Updated: 2023/01/08 17:42:34 by akasiota      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/* Check for failed allocation and free memory of char and pointer arrays */
static int	chk_null(char **points, char *sub, size_t n)
{
	if (sub == NULL)
	{
		while ((long)n >= 0)
		{
			free(points[n]);
			n--;
		}
		free(points);
		return (0);
	}
	else
		return (1);
}

/* Calculate the number of words in string "s" */
static size_t	find_words(char const *s, char c, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (s[n] != 0)
	{
		if (n == 0 && s[n] != c)
		{
			i++;
			n++;
		}
		else if ((n == (len - 1)) && s[n] == c)
			return (i);
		else if (s[n] == c && s[n + 1] != c && s[n + 1] != 0)
		{
			i++;
			n++;
		}
		else
			n++;
	}
	return (i);
}

/* Calculate the length of each word */
static size_t	sub_len(char const *s, char c, size_t *i)
{
	size_t	len;
	size_t	j;

	len = 0;
	j = *i;
	while (s[j] != 0)
	{
		while (s[j] == c && len == 0)
			j++;
		if (s[j] != c && s[j] != 0)
		{
			j++;
			len++;
		}
		else if (s[j] == c)
			return (len);
	}
	return (len);
}

/* Fill the char arrays with the words */
static char	*fill_sub(char *sub, char const *s, char c, size_t *i)
{
	size_t	len;
	size_t	n;

	len = sub_len(s, c, i);
	sub = ft_calloc((len + 1), sizeof(char));
	if (sub == NULL)
		return (NULL);
	n = 0;
	while (s[*i] != 0)
	{
		while (s[*i] == c && n == 0)
			*i = *i + 1;
		if (s[*i] != c && s[*i] != 0)
		{
			sub[n] = s[*i];
			n++;
			*i = *i + 1;
		}
		else if (s[*i] == c)
			break ;
	}
	return (sub);
}

char	**ft_split(char const *s, char c)
{
	char	**points;
	size_t	splits;
	size_t	len;
	size_t	n;
	size_t	i;

	len = ft_strlen(s);
	splits = find_words(s, c, len);
	points = ft_calloc((splits + 1), sizeof(char *));
	if (points == NULL)
		return (NULL);
	n = 0;
	i = 0;
	while (n < splits && i < len)
	{
		points[n] = fill_sub(points[n], s, c, &i);
		if (chk_null(points, points[n], n) == 0)
			return (NULL);
		i++;
		n++;
	}
	return (points);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: akasiota <akasiota@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 21:49:18 by akasiota      #+#    #+#                 */
/*   Updated: 2023/01/08 17:39:07 by akasiota      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/* A helper function similar to isspace(3) */
static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v'\
	|| c == '\f')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *s)
{
	int	i;
	int	n;

	i = 0;
	n = 1;
	while (ft_isspace(*s) == 1)
		s++;
	if (*s == '+' && ft_isdigit(*(s + 1)) == 1)
		s++;
	if (*s == '-')
	{
		n = n * (-1);
		s++;
	}
	if (*s >= 48 && *s <= 57)
	{
		i = *s - 48;
		s++;
		while (*s >= 48 && *s <= 57)
		{
			i = (i * 10) + (*s - 48);
			s++;
		}
	}
	return (i * n);
}

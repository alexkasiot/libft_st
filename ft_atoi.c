/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: akasiota <akasiota@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 21:49:18 by akasiota      #+#    #+#                 */
/*   Updated: 2023/05/30 15:42:01 by akasiota      ########   odam.nl         */
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

static int	ft_atoi_calc(char *s, long long *i, long long *n)
{
	while (ft_isspace(*s) == 1)
		s++;
	if (*s == '+' && ft_isdigit(*(s + 1)) == 1)
		s++;
	if (*s == '-')
	{
		*n = *n * (-1);
		s++;
	}
	if (*s >= 48 && *s <= 57)
	{
		*i = *s - 48;
		s++;
		while (*s >= 48 && *s <= 57)
		{
			*i = (*i * 10) + (*s - 48);
			s++;
		}
	}
}

int	ft_atoi(const char *s)
{
	long long	i;
	long long	n;
	long long	res;
	char		*sub;

	i = 0;
	n = 1;
	sub = s;
	ft_atoi_calc(s, &i, &n);
	s = sub;
	res = i * n;
	if (res < INT_MIN || res > INT_MAX)
	{
		write(STDERR_FILENO, "Number outside of int limits\n", 30);
		exit(errno);
	}
	return ((int)res);
}

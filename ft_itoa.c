/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: akasiota <akasiota@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 12:05:11 by akasiota      #+#    #+#                 */
/*   Updated: 2023/07/03 15:26:38 by akasiota      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/* Get the number of characters of the integer */
static unsigned int	get_int_len(long n)
{
	unsigned int	i;

	i = 0;
	if (n == INT_MIN)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * (-1);
		i++;
	}
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

/* Check negative input */
static void	chk_neg(char *s, long *n)
{
	if (*n < 0)
	{
		s[0] = '-';
		*n = *n * (-1);
	}
}

char	*ft_itoa(int n)
{
	unsigned int	len;
	char			*s;
	unsigned int	i;
	long			n2;

	n2 = n;
	i = 1;
	len = get_int_len(n2);
	s = malloc((len + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	chk_neg(s, &n2);
	while (n2 >= 10 && i < len)
	{
		s[len - i] = (n2 % 10) + 48;
		n2 = n2 / 10;
		i++;
	}
	if (n2 < 10)
		s[len - i] = (n2 % 10) + 48;
	s[len] = 0;
	return (s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: akasiota <akasiota@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 15:17:41 by akasiota      #+#    #+#                 */
/*   Updated: 2023/01/08 17:42:30 by akasiota      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbr_fd(int n, int fd)
{
	int	i;

	if (n < 0)
	{
		if (n == INT_MIN)
		{
			write(fd, "-2147483648", 11);
			return ;
		}
		write(fd, "-", 1);
		n = n * (-1);
	}
	if (n >= 10)
	{
		i = n / 10;
		ft_putnbr_fd(i, fd);
	}
	i = (n % 10) + 48;
	write(fd, &i, 1);
}

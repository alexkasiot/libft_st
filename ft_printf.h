/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akasiota <akasiota@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/11 21:03:41 by akasiota      #+#    #+#                 */
/*   Updated: 2023/03/15 18:10:24 by akasiota      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// Headers
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

// Function prototypes

int		ft_printf(const char *s, ...);

int		print_type(va_list *ptr, char c, int *len, int *index);

int		ft_printf_putchar(int c, int *len, int *index);

int		ft_printf_putstr(char *s, int *len, int *index);

int		ft_printf_putptr(void *pointer, int *len, int *index);

int		ft_printf_putint(int i, int *len, int *index);

int		ft_printf_putuns(unsigned int u, int *len, int *index);

int		ft_printf_puthex_low(unsigned int u, int *len, int *index);

int		ft_printf_puthex_upp(unsigned int u, int *len, int *index);

int		ft_printf_putpercent(char percent, int *len, int *index);

#endif
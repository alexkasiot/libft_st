/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: akasiota <akasiota@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/08 20:28:11 by akasiota      #+#    #+#                 */
/*   Updated: 2023/05/29 21:55:42 by akasiota      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

// Headers
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

// Function prototypes

char	*get_next_line(int fd);

char	*ft_strchr_gnl(char *s, int c);

char	*ft_strjoin_gnl(char *s1, char *s2);

void	ft_bzero_gnl(void *s, size_t n);

void	*ft_calloc_gnl(size_t count, size_t size);

#endif
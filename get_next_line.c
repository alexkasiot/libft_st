/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: akasiota <akasiota@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/30 00:41:47 by akasiota      #+#    #+#                 */
/*   Updated: 2023/03/25 19:17:28 by akasiota      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_new_buffer(char *line)
{
	char	*sub;
	size_t	i;
	size_t	k;

	i = 0;
	while (line[i] != 0 && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	sub = ft_calloc((ft_strlen(line) - i + 1), sizeof(char));
	if (sub == NULL)
		return (free(line), NULL);
	k = 0;
	while (line[i] != 0)
	{
		sub[k] = line[i];
		i++;
		k++;
	}
	free(line);
	return (sub);
}

static char	*get_return_line(char *line, size_t i)
{
	char	*return_line;
	size_t	k;

	while (i < ft_strlen(line))
	{
		if (line[i] == '\n')
		{
			i = i + 1;
			break ;
		}	
		i = i + 1;
	}
	return_line = ft_calloc((i + 1), sizeof(char));
	if (return_line == NULL)
		return (free(line), NULL);
	k = 0;
	while (k < i)
	{
		return_line[k] = line[k];
		k++;
	}
	if (*return_line == 0)
		return (free(line), free(return_line), NULL);
	return (return_line);
}

static char	*get_the_line(char *line, int fd)
{
	char	*line_buffer;
	ssize_t	read_bytes;

	read_bytes = 1;
	while (!ft_strchr(line, '\n') && read_bytes != 0)
	{
		line_buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		if (line_buffer == NULL)
			return (free(line), NULL);
		read_bytes = read(fd, line_buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			return (free(line), free(line_buffer), NULL);
		line = ft_strjoin(line, line_buffer);
		if (line == NULL || *line == 0)
			return (free(line), NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line[OPEN_MAX + 1];
	char		*return_line;
	size_t		i;

	i = 0;
	if (BUFFER_SIZE <= 0 || fd < 0 || fd > OPEN_MAX)
		return (NULL);
	if (line[fd] == NULL)
	{
		line[fd] = malloc(1 * sizeof(char));
		if (line[fd] == NULL)
			return (NULL);
		line[fd][0] = 0;
	}
	line[fd] = get_the_line(line[fd], fd);
	if (line[fd] == NULL)
		return (NULL);
	return_line = get_return_line(line[fd], i);
	if (return_line == NULL)
		return (line[fd] = NULL, NULL);
	line[fd] = ft_new_buffer(line[fd]);
	if (line[fd] == NULL)
		return (free(return_line), NULL);
	return (return_line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabusitt <kabusitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:16:14 by kabusitt          #+#    #+#             */
/*   Updated: 2021/12/28 16:22:01 by kabusitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_remain(char *saved_line)
{
	int		i;
	int		z;
	char	*line;

	i = 0;
	while (saved_line[i] && saved_line[i] != '\n')
		++i;
	if (!saved_line[i] || (saved_line[i] == '\n' && !saved_line[i + 1]))
	{
		free(saved_line);
		return (NULL);
	}
	++i;
	line = malloc(sizeof(char) * (ft_strlen(saved_line) - i + 1));
	if (!line)
		return (NULL);
	z = 0;
	while (saved_line[i])
		line[z++] = saved_line[i++];
	line[z] = '\0';
	free(saved_line);
	return (line);
}

char	*ft_find_line(char	*saved_line)
{
	int		i;
	char	*line;

	i = 0;
	if (!saved_line[i])
		return (NULL);
	while (saved_line[i] && saved_line[i] != '\n')
		++i;
	if (!saved_line[i])
		line = malloc(sizeof(char) * (i + 1));
	else
		line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (saved_line[i] && saved_line[i] != '\n')
	{
		line[i] = saved_line[i];
		++i;
	}
	if (saved_line[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_read_first(int fd, char *saved_line)
{
	char	*buffer;
	int		bytes;

	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(saved_line, '\n') && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		saved_line = ft_strjoin(saved_line, buffer);
	}
	free(buffer);
	return (saved_line);
}

char	*get_next_line(int fd)
{
	static char	*saved_line;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved_line = ft_read_first(fd, saved_line);
	if (!saved_line)
		return (NULL);
	line = ft_find_line(saved_line);
	saved_line = ft_remain(saved_line);
	return (line);
}

void	ft_freemem(int fd)
{
	char	*str;

	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
	}
}

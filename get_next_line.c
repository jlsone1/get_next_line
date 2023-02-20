/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javsanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:30:31 by javsanch          #+#    #+#             */
/*   Updated: 2022/12/30 15:22:16 by javsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include    "get_next_line.h"

char	*ft_freebis(char *final)
{
	free (final);
	return (NULL);
}

char	*ft_read(int fd, char *final)
{
	char	*text;
	ssize_t	z;

	while (1)
	{
		text = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		z = read(fd, text, BUFFER_SIZE);
		if (z <= 0)
		{
			free (text);
			if (z == -1)
				return (ft_freebis(final));
			break ;
		}
		text[z] = '\0';
		if (!final)
			final = ft_memcopy(text);
		else
			final = ft_strjoin(final, text);
		if (ft_isline(final) == 1)
			break ;
	}
	return (final);
}

char	*ft_copyline(char *final)
{
	size_t		i;
	char		*c;

	i = 0;
	while (final[i] != '\n' && final[i] != '\0')
		i++;
	if (final[i] == '\n')
		i++;
	c = malloc(sizeof(char) * (i + 1));
	if (!c)
		return (NULL);
	i = 0;
	while (final[i] != '\0')
	{
		c[i] = final[i];
		if (c[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	c[i] = '\0';
	return (c);
}

char	*ft_newline(char *final, char *line)
{
	size_t	i;
	size_t	j;
	char	*c;

	i = ft_strlen(final);
	j = ft_strlen(line);
	if (i - j == 0)
	{
		free (final);
		return (NULL);
	}
	c = malloc(sizeof(char) * (i - j + 1));
	if (!c)
	{
		free (final);
		return (NULL);
	}
	i = 0;
	while (final[j] != '\0')
		c[i++] = final[j++];
	c[i] = '\0';
	free(final);
	return (c);
}

char	*get_next_line(int fd)
{
	static char	*final;
	static char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	final = ft_read(fd, final);
	if (!final)
		return (NULL);
	line = ft_copyline(final);
	final = ft_newline(final, line);
	return (line);
}

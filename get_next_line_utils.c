/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javsanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:30:47 by javsanch          #+#    #+#             */
/*   Updated: 2022/12/22 17:19:37 by javsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_free(char *s1, char *s2)
{
	free (s1);
	free (s2);
	return (NULL);
}

size_t	ft_strlen(char *c)
{
	size_t	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i] != '\0')
		i++;
	return (i);
}

char	*ft_memcopy(char *text)
{
	char	*c;
	int		i;

	i = ft_strlen(text);
	c = malloc(sizeof(char) * (i + 1));
	if (!c)
	{
		free (text);
		return (NULL);
	}
	i = 0;
	while (text[i] != '\0')
	{
		c[i] = text[i];
		i++;
	}
	c[i] = '\0';
	free (text);
	return (c);
}

size_t	ft_isline(char *final)
{
	size_t	i;

	i = 0;
	while (final[i] != '\0')
	{
		if (final[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*c;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	c = malloc(sizeof(char) * ((i + j) + 1));
	i = 0;
	if (!c)
		return (ft_free(s1, s2));
	while (s1[i] != '\0')
	{
		c[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		c[i++] = s2[j++];
	c[i] = '\0';
	free (s1);
	free (s2);
	return (c);
}

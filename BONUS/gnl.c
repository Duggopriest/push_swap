/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <jgobbett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:44:19 by jgobbett          #+#    #+#             */
/*   Updated: 2022/05/12 17:02:38 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <unistd.h>
#include <stdlib.h>
#include "checker.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	charfind(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (++i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *str, char *str2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = malloc(ft_strlen(str) + ft_strlen(str2) + 1);
	if (str)
		while (str[j])
			new[i++] = str[j++];
	j = 0;
	if (str2)
		while (str2[j])
			new[i++] = str2[j++];
	new[i] = '\0';
	if (str)
		free(str);
	return (new);
}

char	*assignline(char **str)
{
	int		i;
	int		j;
	char	*line;
	char	*store;

	i = charfind(*str);
	if (i == 0)
		i = ft_strlen(*str);
	line = malloc(i + 1);
	line[i] = '\0';
	while (i-- > 0)
		line[i] = (*str)[i];
	store = NULL;
	i = ft_strlen(*str) - charfind(*str);
	if (i != ft_strlen(*str) && i > 0)
	{
		store = malloc(i + 1);
		store[i++] = '\0';
		j = ft_strlen(*str);
		while (i-- > 0)
			store[i] = (*str)[j--];
	}
	free(*str);
	*str = store;
	return (line);
}

char	*get_next_line(int fd)
{
	char			*buff;
	int				n;
	static char		*stored[4096];

	if (3 < 1 || fd < 0)
		return (NULL);
	buff = malloc(3 + 1);
	while (!charfind(&stored[fd][0]))
	{
		n = read(fd, buff, 3);
		if (n == 0)
			break ;
		buff[n] = '\0';
		stored[fd] = ft_strjoin(stored[fd], buff);
	}
	free(buff);
	if (stored[fd])
		return (assignline(&stored[fd]));
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:59:24 by aseptimu          #+#    #+#             */
/*   Updated: 2021/10/22 18:37:21 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	check(char **bufcpy, char **p, char **ret, char *tmp)
{
	*p = NULL;
	if (*bufcpy)
	{
		*p = ft_strchr(*bufcpy, '\n');
		if (*p)
		{
			*ret = ft_strdup(*bufcpy);
			*ret = ft_trim(*ret);
			tmp = *bufcpy;
			*bufcpy = ft_strdup(++(*p));
			if (!*bufcpy)
				ret = NULL;
			free(tmp);
		}
		else
		{
			*ret = ft_strdup(*bufcpy);
			free(*bufcpy);
			*bufcpy = NULL;
		}
	}
	else
		*ret = ft_strdup("\0");
}

char	*ft_read(ssize_t *i, int fd, char *ret, char **p)
{
	char	*buf;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	*i = read(fd, buf, BUFFER_SIZE);
	if (*i == -1)
	{
		free(ret);
		free(buf);
		return (NULL);
	}
	buf[*i] = '\0';
	*p = ft_strchr(buf, '\n');
	return (buf);
}

char	*ft_join(char **p, char **bufcpy, char *ret, char *buf)
{
	char	*tmp;

	if (*p != NULL)
	{
		*bufcpy = ft_strdup(++(*p));
		if (!*bufcpy)
			return (NULL);
	}
	tmp = ret;
	ret = ft_strjoin(ret, ft_trim(buf));
	if (!ret)
		return (NULL);
	free(tmp);
	free(buf);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*bufcpy[10240];
	char		*buf;
	char		*ret;
	char		*p;
	ssize_t		i;

	buf = NULL;
	if (fd < 0)
		return (NULL);
	ret = NULL;
	check(&bufcpy[fd], &p, &ret, buf);
	if (!ret)
		return (NULL);
	i = BUFFER_SIZE;
	while (!p && i && i == BUFFER_SIZE)
	{
		buf = ft_read(&i, fd, ret, &p);
		if (!buf)
			return (NULL);
		ret = ft_join(&p, &bufcpy[fd], ret, buf);
	}
	if (i || ft_strlen(ret))
		return (ret);
	free(ret);
	return (NULL);
}

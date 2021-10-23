/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:23:25 by aseptimu          #+#    #+#             */
/*   Updated: 2021/10/22 15:14:10 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_trim(char *str);
void	check(char **bufcpy, char **p, char **ret, char *tmp);
char	*ft_read(ssize_t *i, int fd, char *ret, char **p);
char	*ft_join(char **p, char **bufcpy, char *ret, char *buf);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strcpy(char *dst, const char *src);
char	*ft_strchr(const char *s, int c);
#endif

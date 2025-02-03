/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:51:04 by lkhye-ya          #+#    #+#             */
/*   Updated: 2024/08/22 13:24:47 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <fcntl.h>

/*Get Next Line Utils*/
size_t	ft_strlen(const char *str);
char	*ft_strjoin(const char *s1, const char *s2);
void	*ft_memset(void *ptr, int value, size_t number);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strchr(const char *str, int c);

/*Get Next Line File Functions*/
char	*free_lines(char *buffer, char *count);
char	*next_line(char *buffer);
char	*get_line(char *buffer);
char	*read_file(int fd, char *result);
char	*get_next_line(int fd);

#endif
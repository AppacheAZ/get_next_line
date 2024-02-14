/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcoalv <marcoalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:23:26 by marcoalv          #+#    #+#             */
/*   Updated: 2024/02/14 18:34:24 by marcoalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char			*get_next_line(int fd);
char			*ft_strchr(const char *str, int c);
void			*ft_calloc(size_t count, size_t size);
void			ft_bzero(void *s, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
unsigned long	ft_strlen(const char *s);
#endif
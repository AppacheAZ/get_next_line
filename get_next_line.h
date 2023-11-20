/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcoalv <marcoalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:23:26 by marcoalv          #+#    #+#             */
/*   Updated: 2023/11/20 18:23:29 by marcoalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE
#include <stdio.h>
#include <stdlib.h>

char            *get_next_line(int fd);
char	        *ft_strchr(const char *str, int c);
void            *ft_calloc(size_t count, size_t size);
char	        *ft_strdup(const char *s);
char	        *ft_strjoin(char const *s1, char const *s2);
unsigned long   ft_strlen(const char *s);

#endif
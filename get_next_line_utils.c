/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:32:46 by ohamadou          #+#    #+#             */
/*   Updated: 2023/03/30 08:30:18 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int	ft_strlen(char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
		a++;
	return (a);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)(s + ft_strlen(s)));
	while (*s)
	{
		if ((char)c == *s)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*newstring;
// 	int		i;
// 	int		n;

// 	i = 0;
// 	n = 0;
// 	if (s1 == NULL)
// 		return (s2);
// 	newstring = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (newstring == NULL)
// 		return (NULL);
// 	while (s1[i])
// 	{
// 		newstring[i] = s1[i];
// 		i++;
// 	}
// 	while (s2[n])
// 	{
// 		newstring[i + n] = s2[n];
// 		n++;
// 	}
// 	newstring[i + n] = '\0';
// 	free(s1);
// 	free(s2);
// 	return (newstring);
// }

char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	left_str = str;
	return (str);
}

// char	*ft_strjoin(char **left_str, char *buff)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*str;

// 	if (!(*left_str))
// 	{
// 		*left_str = (char *)malloc(1 * sizeof(char));
// 		*left_str[0] = '\0';
// 	}
// 	if (!(*left_str) || !buff)
// 		return (NULL);
// 	str = malloc(sizeof(char) * ((ft_strlen(*left_str) + ft_strlen(buff)) + 1));
// 	if (str == NULL)
// 		return (NULL);
// 	i = -1;
// 	j = 0;
// 	if (*left_str)
// 		while ((*left_str)[++i] != '\0')
// 			str[i] = (*left_str)[i];
// 	while (buff[j] != '\0')
// 		str[i++] = buff[j++];
// 	str[ft_strlen(*left_str) + ft_strlen(buff)] = '\0';
// 	free(*left_str);
// 	*left_str = str;
// 	return (str);
// }


char	*get_the_line(char *left_str)
{
	char	*str;
	int		i;

	i = 0;
	if (!left_str[i])
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*des;
	char	*sr;
	size_t	i;

	des = (char *)dest;
	sr = (char *)src;
	i = 0;
	if (!des && !sr)
		return (NULL);
	while (i < n)
	{
		des[i] = sr[i];
		i++;
	}
	return (dest);
}

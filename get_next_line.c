/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:32:41 by ohamadou          #+#    #+#             */
/*   Updated: 2023/03/30 16:48:26 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_str(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}
// left_str = ft_strjoin(&left_str, buff);

char	*remained_str_new(char *left_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	j = ft_strlen(left_str) - i;
	str = malloc(sizeof(char) * (j + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, &left_str[i + 1], j);
	str[j] = '\0';
	free(left_str);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str = read_str(fd, left_str);
	if (!left_str)
		return (NULL);
	line = get_the_line(left_str);
	left_str = remained_str_new(left_str);
	if (!left_str && !line)
	{
		free(line);
		free(left_str);
		return (NULL);
	}
	return (line);
}

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	// int		fd2;
	// int		fd3;
	fd1 = open("read_error.txt", O_RDONLY);
	// fd2 = open("tests/test2.txt", O_RDONLY);
	// fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		// line = get_next_line(fd2);
		// printf("line [%02d]: %s", i, line);
		// free(line);
		// line = get_next_line(fd3);
		// printf("line [%02d]: %s", i, line);
		// free(line);
		i++;
	}
	close(fd1);
	system("leaks a.out");
	// close(fd2);
	// close(fd3);
	return (0);
}

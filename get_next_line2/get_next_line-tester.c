/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line-tester.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:22:42 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/11/11 13:23:56 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	ft_free_gnl(char *tmp)
{
	ft_strdel(&tmp);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*c[127];
	char		buffer[BUFF_SIZE + 1];
	char		*tmp;
	ssize_t		b;
	int			endl;

	if (fd < 0 || (!c[fd] && !(c[fd] = ft_strnew(1))) || !line)
		return (-1);
	while (!ft_strchr(c[fd], '\n') && (b = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[b] = '\0';
		tmp = c[fd];
		c[fd] = ft_strjoin(c[fd], buffer);
		ft_strdel(&tmp);
	}
	if ((b == -1 || !*(tmp = c[fd])) && ft_free_gnl(tmp))
		return (b == -1 ? -1 : 0);
	if ((endl = (ft_strchr(c[fd], '\n') > 0)))
		*line = ft_strsub(c[fd], 0, ft_strchr(c[fd], '\n') - c[fd]);
	else
		*line = ft_strdup(c[fd]);
	c[fd] = ft_strsub(c[fd], (unsigned int)(ft_strlen(*line) + endl),
			(size_t)(ft_strlen(c[fd]) - (ft_strlen(*line) + endl)));
	ft_strdel(&tmp);
	return (!(!c[fd] && !ft_strlen(*line)));
}

int main(int ac, char **av)
{
	int fd;
	char *line;

	if (ac > 0)
		ft_putstr("Hello\n");
	fd = open(av[1], O_RDONLY);
	get_next_line(fd, &line);
	if (line == NULL)
		printf("NULL\n");
	else
		printf("%s", line);
	get_next_line(fd, &line);
	if (line == NULL)
		printf("NULL\n");
	else
		printf("%s", line);
	get_next_line(fd, &line);
	if (line == NULL)
			printf("NULL\n");
	else
		printf("%s", line);
	get_next_line(fd, &line);
	if (line == NULL)
			printf("NULL\n");
	else
		printf("%s", line);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 10:27:53 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/11/12 17:06:15 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		stack_to_heap(char **stack, char **line)
{
	char	*temp;
	int		i;

	i = 0;
	while ((*stack)[i] != '\0' && (*stack)[i] != '\n')
		i++;
	if ((*stack)[i] == '\0')
	{
		*line = ft_strdup(*stack);
		ft_strdel(stack);
	}
	else
	{
		*line = ft_strsub(*stack, 0, i);
		temp = ft_strdup(&(*stack)[i + 1]);
		free(*stack);
		*stack = temp;
		if ((*stack)[0] == '\0')
			ft_strdel(stack);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*stack[MAX_FD];
	char		buff[BUFF_SIZE + 1];
	int			ret;
	char		*temp;

	*line = ft_strnew(1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret < 0 || fd < 0 || !line)
			return (-1);
		buff[ret] = '\0';
		if (!stack[fd])
			stack[fd] = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(stack[fd], buff);
			free(stack[fd]);
			stack[fd] = temp;
		}
		if (ft_strchr(stack[fd], '\n') != NULL)
			break ;
	}
	if (ret == 0 && stack[fd] == NULL)
		return (0);
	return (stack_to_heap(&stack[fd], line));
}

int main(int ac, char **av)
{
	int fd;
	int fd2;
	int fd3;
	char *line;

	line = NULL;
	if (ac > 0)
		ft_putstr("Ignore this \n");
	fd = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	fd3 = open(av[3], O_RDONLY);
	printf("fd1 is = %d fd2 is = %d fd3 is = %d ", fd, fd2, fd3);
	printf("Number is  =  %d\n", get_next_line(fd, &line));
	if (line == NULL)
		printf("NULL\n");
	else
		printf("%s\n", line);
	printf("Number is  =  %d\n", get_next_line(fd, &line));
	if (line == NULL)
		printf("NULL\n");
	else
		printf("%s\n", line);
	printf("Number is  =  %d\n", get_next_line(fd, &line));
	if (line == NULL)
			printf("NULL\n");
	else
		printf("%s\n", line);
	printf("Number is  =  %d\n", get_next_line(fd, &line));
	if (line == NULL)
			printf("NULL\n");
	else
		printf("%s\n", line);
	printf("------SECOND CALL-------\n");
	printf("Number is  =  %d\n", get_next_line(fd2, &line));
	if (line == NULL)
		printf("NULL\n");
	else
		printf("%s\n", line);
	printf("Number is  =  %d\n", get_next_line(fd2, &line));
	if (line == NULL)
		printf("NULL\n");
	else
		printf("%s\n", line);
	printf("Number is  =  %d\n", get_next_line(fd2, &line));
	if (line == NULL)
			printf("NULL\n");
	else
		printf("%s\n", line);
	printf("Number is  =  %d\n", get_next_line(fd2, &line));
	if (line == NULL)
			printf("NULL\n");
	else
		printf("%s\n", line);
	printf("------THIRD CALL-------\n");
	printf("Number is  =  %d\n", get_next_line(fd3, &line));
	if (line == NULL)
		printf("NULL\n");
	else
		printf("%s\n", line);
	printf("Number is  =  %d\n", get_next_line(fd3, &line));
	if (line == NULL)
		printf("NULL\n");
	else
		printf("%s\n", line);
	printf("Number is  =  %d\n", get_next_line(fd3, &line));
	if (line == NULL)
			printf("NULL\n");
	else
		printf("%s\n", line);
	printf("Number is  =  %d\n", get_next_line(fd3, &line));
	if (line == NULL)
			printf("NULL\n");
	else
		printf("%s\n", line);
	return (0);
}

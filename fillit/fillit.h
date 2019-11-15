/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 20:55:06 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/11/15 15:01:09 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 32
# include <fcntl.h>
# include "libft/libft.h"

typedef struct	s_data
{
	size_t		n_hashes;
	size_t		n_tetris;
	size_t		len;
	size_t		i;
	char		*str;
}				t_data;

int		check_shapes(char *str, t_data *tetris);

char	*please_read(int fd);

int		errno(void);

int		validate_square(t_data *tetris);

#endif

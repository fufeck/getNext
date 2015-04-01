/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 13:27:30 by ftaffore          #+#    #+#             */
/*   Updated: 2015/04/01 13:27:33 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"

int			main(void)
{
	int		fd1;
	int		fd2;
	char	*line;

	fd1 = open("main.c", O_RDONLY);
	while (get_next_line(fd1, &line) > 0)
	{
		ft_putstr(line);
		ft_putstr("\n");
		free((void*)(line));
		line = NULL;
	}
	close(fd1);
	fd2 = open("get_next_line.c", O_RDONLY);
	while (get_next_line(fd2, &line) > 0)
	{
		ft_putstr(line);
		ft_putstr("\n");
		free((void*)(line));
		line = NULL;
	}
	close(fd2);
	return (0);
}

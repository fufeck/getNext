/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 16:00:39 by ftaffore          #+#    #+#             */
/*   Updated: 2015/03/31 16:00:40 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int						main() {
	int fd = open("main.c", O_RDONLY);
	char			*line;

	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
	}
}
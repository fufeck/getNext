/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 12:49:33 by ftaffore          #+#    #+#             */
/*   Updated: 2013/12/04 17:19:35 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE	256

typedef struct		s_chain
{
	int				i;
	int				n;
	int				fd;
	int				len;
	char			buff[BUFF_SIZE];
	struct s_chain	*next;
}					t_chain;

int					get_next_line(int fd, char **line);

#endif

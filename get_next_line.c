/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 11:38:05 by ftaffore          #+#    #+#             */
/*   Updated: 2015/03/31 11:38:06 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"

static t_chain				*create_chain(t_chain *all_chains, int fd)
{
	t_chain					*new_elem;

	if ((new_elem = ft_memalloc(sizeof(*new_elem))) == NULL)
		return (NULL);
	new_elem->i = 0;
	new_elem->n = 0;
	new_elem->len = 0;
	ft_bzero(new_elem->buff, BUFF_SIZE);
	new_elem->fd = fd;
	new_elem->next = all_chains;
	return (new_elem);
}

static t_chain				*get_chain(int fd)
{
	static t_chain			*all_chains = NULL;
	t_chain					*ptr;

	ptr = all_chains;
	while (ptr != NULL && ptr->fd != fd)
		ptr = ptr->next;
	if (ptr == NULL)
	{
		all_chains = create_chain(all_chains, fd);
		return (all_chains);
	}
	return (ptr);
}

static int					read_next(t_chain *chain)
{
	if (chain->i > 0 && chain->i < chain->len)
		return (1);
	chain->i = 0;
	chain->n = 0;
	ft_bzero(chain->buff, BUFF_SIZE);
	chain->len = read(chain->fd, chain->buff, BUFF_SIZE);
	if (chain->len < 0)
		return (-1);
	else if (chain->len == 0)
		return (0);
	return (1);
}

static int					my_strconcat(char **line, t_chain *chain)
{
	char					*res;

	res = ft_memalloc(ft_strlen(*line) + chain->n - chain->i + 1);
	if (res == NULL)
		return (-1);
	if (*line != NULL)
	{
		res = ft_strcat(res, *line);
		free(*line);
		*line = NULL;
	}
	res = ft_strncat(res, &(chain->buff[chain->i]), chain->n - chain->i);
	*line = res;
	chain->n += 1;
	chain->i = chain->n;
	return (0);
}

int							get_next_line(int fd, char **line)
{
	t_chain					*c;

	*line = NULL;
	if ((c = get_chain(fd)) == NULL)
		return (-1);
	while (read_next(c) > 0)
	{
		c->n = ft_strchr_index((char *)&(c->buff[c->i]), (int)'\n');
		c->n += c->i;
		if (my_strconcat(line, c) < 0)
			return (-1);
		if (c->n < c->len || \
			(c->n == c->len && c->buff[c->n - 1] == '\n'))
			return (1);
	}
	if (*line != NULL)
		return (1);
	return (c->len);
}

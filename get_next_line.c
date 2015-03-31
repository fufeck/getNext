/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 13:54:04 by ftaffore          #+#    #+#             */
/*   Updated: 2013/12/04 15:42:28 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include				<stdlib.h>
#include				"get_next_line.h"
#include				"libft.h"

static int				get_next_read(int fd, char *buff, unsigned int *i)
{
	int					len;

	len = 0;
	if (*i > 0 && *i <= ft_strlen(buff))
		return (1);
	if ((len = read(fd, buff, BUFF_SIZE + 1)) < 0)
		return (len);
	*i = 0;
	buff[len] = '\0';
	return (len);
}

static char				*my_strconcat(char *dst, char *src, int n)
{
	char				*res;

	res = NULL;
	res = ft_strnew((int)(ft_strlen(dst) + n));
	if (res == NULL)
		return (NULL);
	if (dst != NULL)
	{
		res = ft_strcat(res, dst);
		free(dst);
		dst = NULL;
	}
	res = ft_strncat(res, src, n);
	return (res);
}

int							get_next_line(int fd, char **line)
{
	static unsigned int		i = 0;
	static char 			buff[BUFF_SIZE + 1];
	char					*end;
	int						n;

	n = 0;
	(*line) = NULL;
	end = NULL;
	while ((n = get_next_read(fd, buff, &i)) > 0)
	{
		end = ft_strchr((char *)&buff[i], (int)'\n');
		n = ft_strchr_index((char *)&buff[i], (int)'\n');
		if (((*line) = my_strconcat(*line, &buff[i], n)) == NULL)
			return (-1);
		i += n + 1;
		if (end != NULL)
			return (1);
	}
	if ((*line) != NULL)
		return (1);
	return (n);
}

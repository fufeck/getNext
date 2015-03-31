/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:45:53 by ftaffore          #+#    #+#             */
/*   Updated: 2013/11/20 16:51:57 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_memalloc(size_t size)
{
	char	*ret;
	if (size <= 0)
		return (NULL);
	if ((ret = (char *)malloc(size)) == NULL)
	{
		write(2, "ERROR : malloc fail.\n", 21);
		return (NULL);
	}
	ft_bzero(ret, ft_strlen(ret));
	return ((void*)ret);
}

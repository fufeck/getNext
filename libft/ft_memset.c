/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:47:07 by ftaffore          #+#    #+#             */
/*   Updated: 2013/11/28 11:17:05 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void				*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	if (s == NULL)
		return (s);
	i = 0;
	str = (unsigned char *)(s);
	while (i < n)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

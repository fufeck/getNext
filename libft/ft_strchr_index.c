/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 12:06:14 by ftaffore          #+#    #+#             */
/*   Updated: 2013/12/03 12:30:02 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strchr_index(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	if (s != NULL)
	{
		while (i <= ft_strlen(s) && s[i] != (char)c)
			i++;
	}
	return (i);
}

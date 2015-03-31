/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:18:48 by ftaffore          #+#    #+#             */
/*   Updated: 2013/11/28 11:20:04 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strcat(char *s1, const char *s2)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = ft_strlen(s1);
	while (s2[a] != '\0')
	{
		s1[b] = s2[a];
		a++;
		b++;
	}
	s1[b] = '\0';
	return (s1);
}


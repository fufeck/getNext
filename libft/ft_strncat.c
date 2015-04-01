/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftaffore <ftaffore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:16:36 by ftaffore          #+#    #+#             */
/*   Updated: 2013/11/28 11:19:46 by ftaffore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = ft_strlen(s1);
	while (s2[a] != '\0' && a < n)
	{
		s1[b] = s2[a];
		b++;
		a++;
	}
	s1[b] = '\0';
	return (s1);
}

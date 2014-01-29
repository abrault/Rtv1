/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 10:56:47 by abrault           #+#    #+#             */
/*   Updated: 2013/11/29 16:09:25 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t		lenght_dest;
	size_t		lenght_src;
	long long int	result;

	lenght_src = ft_strlen(src);
	lenght_dest = ft_strlen(dest);
	result = (long long int) n - lenght_dest - 1;
	ft_strncat(dest + lenght_dest, src, result * (result > 0));
	return (lenght_src + MIN(n, lenght_dest));
}

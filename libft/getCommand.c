/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getCommand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 13:33:59 by abrault           #+#    #+#             */
/*   Updated: 2013/12/22 13:34:21 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	getCommand(int argc, char **argv, char **option)
{
	if (argc == 1)
		return (1);
	if (argc > 1)
	{
		if (verifstr(argc, argv, &option) == 0)
			return (0);
	}
	return (1);
}

int	verifstr(int argc, char **argv, char ***option)
{
	int	y;
	int	j;
	char	*str;

	str = malloc(sizeof(char) * ft_strlen(**option));
	ft_strcpy(str, **option);
	j = 1;
	y = 1;
	while (y < argc)
	{
		j = 1;
		if (argv[y][0] != '-' || ft_strlen(argv[y]) == 1)
			return (0);
		while (argv[y][j] != '\0')
		{
			if (ft_strchr(str, argv[y][j]) == NULL)
				return (0);
			**option[ft_strlen(str) - ft_strlen(
					ft_strchr(str, argv[y][j]))] = '_';
			j++;
		}
		y++;
	}
	return (1);
}

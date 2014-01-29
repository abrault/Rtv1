/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 08:56:51 by abrault           #+#    #+#             */
/*   Updated: 2013/12/22 13:41:43 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*extract_line(char **str)
{
	char			*ptr;
	char			*ptr2;
	int			i;
	char			*s;

	s = *str;
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	ptr = malloc(sizeof(char) * i);
	ft_strncpy(ptr, *str, i);
	if (ft_strlen(*str) - i != 0)
	{
		ptr2 = malloc(sizeof(char) * (ft_strlen(*str) - i));
		ft_strncpy(ptr2, *str + i + 1, ft_strlen(*str) - i);
		*str = ptr2;
	}
	else
		*str = '\0';
	return (ptr);
}

char		*re_malloc(char *buff, char *str)
{
	char			*stock = NULL;

	stock = malloc(sizeof(char) * (ft_strlen(buff) + ft_strlen(str)));
	if (str == NULL)
		ft_strcpy(stock, "");
	else
		ft_strcpy(stock, str);
	ft_strcat(stock, buff);
	return (stock);
}

int		traitement(char **stock, char **line)
{
	if (ft_strchr(*stock, '\n') != NULL)
	{
		*line = extract_line(stock);
		return (1);
	}
		return (2);
}

int		readF(char *buff, int *ret, int *end)
{
	if (ft_strchr(buff, '\n'))
		*end = 1;
	else if (*ret == -1)
		return (-1);
	else if (*ret == 0)
		*end = 0;
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	static char		*stock = NULL;
	int			end;
	int			ret;
	char			buff[BUFF_SIZE + 1];

	end = 2;
	ret = BUFF_SIZE;
	if (stock != NULL)
		end = traitement(&stock, line);
	if (end == 2)
	{
		while (end == 2)
		{
			ret = read(fd, buff, BUFF_SIZE);
			buff[ret] = '\0';
			readF(buff, &ret, &end);
			stock = re_malloc(buff, stock);
		}
		*line = (char *) malloc(sizeof(char) * (ft_strlen(stock)));
		ft_strcpy(*line, extract_line(&stock));
	}
	if (stock == NULL && ret < BUFF_SIZE)
		end = 0;
	stock = (end == 0) ? NULL : stock;
	return (end);
}

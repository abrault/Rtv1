/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:17:35 by abrault           #+#    #+#             */
/*   Updated: 2014/01/12 15:50:49 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		LIBFT_H
# define	LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

# define BUFF_SIZE 100
# define MIN(a, b) (a < b ? a : b)

/* Fonction Generale */
int		ft_atoi(const char *str);
int		ft_strlen(const char *str);
int		ft_isalnum(int n);
int		ft_isalpha(int n);
int		ft_isascii(int n);
int		ft_isdigit(int n);
int 		ft_isprint(int n);
int		ft_strcmp(const char *str1, const char *str2);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		ft_tolower(int n);
int		ft_toupper(int n);
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t num);

void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *ptr, int charac, int num);
void		*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void		*ft_memcpy(void *destination, const void *source, size_t num);
void		*ft_memmove(void *destination, void *source, size_t num);
void		*ft_memchr(void *ptr, int value, size_t num);
void		*ft_strdup(const char *str);
void		ft_putchar(char c);
void		ft_putstr(const char *str);
void		ft_putendl(const char *s);
void		ft_getTab2(int ***tab, int height, int width);

char		*ft_strchr(const char *str, int c_ascii);
char		*ft_strcat(char *dest, const char *src);
char		*ft_strncat(char *dest, const char *src, size_t n);
char		*ft_strcpy(char *destination, const char *source);
char		*ft_strncpy(char *desti, const char *source, size_t size);
char		*ft_strnstr(const char *str_1, const char *str_2, size_t n);
char		*ft_strrchr(const char *str, int c_ascii);
char		*ft_strstr(const char *str_1, const char *str_2);
char		*ft_strtok(char *str, char sepa);

size_t		ft_strlcat(char *dest, const char *src, size_t n);

/* Gestion des commandes entree standard */
int		verifstr(int argc, char **argv, char ***option);
int		getCommand(int argc, char **argv, char **option);

/* Fonction gestion de fichier */
int		traitement(char **stock, char **line);
int		get_next_line(int const fd, char **line);
char		*extract_line(char **str);
char		*re_malloc(char *buff, char *str);

#endif

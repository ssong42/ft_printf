/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:04:14 by ssong             #+#    #+#             */
/*   Updated: 2018/11/10 15:20:16 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <wchar.h>
#include <locale.h>
#include <unistd.h>

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}					t_btree;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_putstr(char *str);
void				ft_wputstr(wchar_t *str);
void				ft_wputchar(wchar_t c);
wchar_t				*ft_wstrdup(wchar_t *str);
int					ft_atoi(const char *str);
void				ft_bzero(void *a, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_memrset(char *buf, char c, int index);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strnew(size_t size);
char				*ft_strcatnew(char *str, char *cat);
char				*ft_strnstr(const char *big, const char *little, int n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strrcpy(char *dest, char *src, int i, int a);
char				*ft_strstr(const char *big, const char *little);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_iswhite(char *str);
int					ft_countdigits(int n);
int					ft_countwords(char const *s, char c);
int					**ft_mem_grid(int row, int col);
t_btree				*ft_btree_create_node(void *item);
void				ft_swap(int *a, int *b);
void				ft_free2darray(void **longmap, int y);
char				*ft_strjoinfree(char *final, char *end);
char				*ft_straddchr(char *str, char a);
char				*ft_stradduchr(char *str, unsigned char a);

/*
**	ft_printf functions
*/

char				*ft_uintmaxt_itoa(uintmax_t n);
int					ft_uintmaxt_countdigits(uintmax_t n);
int					ft_hex_countdigits(uintmax_t n);
int					ft_hex2_countdigits(uintmax_t n);
int					ft_lcountdigit(long n);
char				*ft_hexitoa(uintmax_t n);
char				*ft_hex_itoa(uintmax_t n);
char				*ft_itoa_base(uintmax_t n, int base);
char				*ft_itoa_deci(double digit);
char				*ft_itoa_float(double digit);
int					ft_countdigits_base(uintmax_t n, int base);
int					ft_printf(const char *str, ...);
char				*ft_intmaxt_itoa(intmax_t n);
char				*extract_string(const char *str, int start, int end);
char				**ft_twodchararray(int row, int col);
/*
**	Get Next Line
*/

int				get_next_line(const int fd, char **line);
void				ft_bzeroint(void *a, size_t n);
int				ft_abs(int c);
#endif

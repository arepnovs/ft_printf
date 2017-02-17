/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepnovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 18:45:27 by arepnovs          #+#    #+#             */
/*   Updated: 2017/02/17 18:54:25 by arepnovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include <stddef.h>
# include <wchar.h>
# include <wctype.h>
# include <locale.h>

typedef struct		s_specs
{
	int				width;
	int				prec;
	char			*len;
	char			type;
	int				neg;
	char			*pct;
}					t_specs;

typedef struct		s_flags
{
	int				space;
	int				zero;
	int				plus;
	int				minus;
	int				hash;
}					t_flags;

void				go_to(va_list args, t_specs params, t_flags flags,
		int *ret);
void				get_specs(char *set, va_list args, int *ret, char *z);
void				get_sets(va_list args, const char *format, int *i,
		int *ret);
int					get_args(va_list args, const char *format);
int					ft_printf(const char *format, ...);
int					check_rep(char *str, char c, int j);
int					check_flags(char c);
int					check_len(char c);
int					check_specs(char c);
int					check_pcpc(char c);
int					check_wrong(char *str);
int					check_pct(char *str);
int					check_undef(char c);
char				*get_flags(char *str);
int					get_width(char *str);
int					get_precision(char *str);
char				*get_length(char *str);
char				get_types(char *set);
void				get_pct(char *str, va_list args, int *ret);
void				get_pct_specs(char *set, va_list args, char *res, int *ret);
void				get_pct_parts(char *str, va_list args, int *ret);
void				get_wid(char *str, char **o_width, char **f_width, int *i);
void				get_prec(char *str, char **o_prec, int *i);
char				*proc_width(t_specs params, t_flags flags, char *res);
long long			cast_len(va_list args, t_specs params);
long long			proc_len(va_list args, t_specs params);
void				print_int(va_list args, t_specs params, t_flags flags,
		int *ret);
int					len_cmp(int a, int b, int c);
void				ft_zero(void *s, size_t n, char c);
void				bzero_paraflags(t_specs *params, t_flags *flag);
void				org_flags(char *str, t_flags *flag);
void				first_symbol_alchemy(char **str, t_specs par,
		t_flags flags);
char				*res_transmut(char *str, t_specs p, t_flags flags,
		char *res);
char				*str_magic(t_specs params, t_flags flags, int res_len,
		char *res);
char				*sign_pref_enchant(char *res, char *str, t_flags flags);
char				*str_sorcery(char *str, t_specs params, t_flags flags);
char				*prefix_witchery(char *str, t_specs par);
char				*char_kadabra(t_specs p, t_flags flags, int len);
char				*char_voodoo(t_specs p, t_flags flags, char *str,
		int res_len);
char				*ft_itow(int wch);
char				*ft_itowstr(int *wch, int prec);
void				get_char(char **str, va_list args, t_specs params);
void				print_char(va_list args, t_specs params, t_flags flags,
		int *ret);
unsigned long long	proc_unlen2(va_list args, t_specs params);
unsigned long long	proc_unlen(va_list args, t_specs p);
void				print_unint(va_list args, t_specs params, t_flags flags,
		int *ret);
int					ft_atoi(char *str);
void				ft_bzero(void *s, size_t n);
void				ft_putstr(char *str);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(const char *s1, const char *s2);
size_t				ft_strlen(const char *s);
char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_charjoin(const char *s1, const char s2);
char				*ft_itoa_long(long long value, int base, char mod);
char				*ft_itoa_unsigned(unsigned long long value, int base,
		char mod);
void				ft_putcharf(char *str, t_specs params, int *ret);

#endif

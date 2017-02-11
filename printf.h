#ifndef PRINTF_H
# define PRINTF_H

//# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include <stddef.h>

typedef struct		s_specs
{
    char			*flags;
    int             width;
    int             prec;
    char            *len;
    char            type;
    int             neg;
    char            *pct;
}					t_specs;

typedef struct		s_flags
{
    int             space;
    int             zero;
    int             plus;
    int             minus;
    int             hash;
}					t_flags;

int     ft_printf(const char *format, ...);
void    go_to(va_list *args, t_specs params, t_flags flags, int *ret);
void    print_int(va_list *args, t_specs params, t_flags flags, int *ret);
char	*ft_charjoin(const char *s1, const char s2);
void    get_specs(char *set, va_list *args, int *ret);
char    *get_flags(char *str);
int     get_width(char *str);
int     get_precision(char *str);
char    *get_length(char *str);
char    get_types(char *set);
int		rep_check(char *str, char c, int j);
int     check_flags(char c);
int     check_len(char c);
int     check_specs(char c);
t_flags org_flags(char *str);
void    bzero_flags(t_flags *flag);
void    bzero_params(t_specs *params);
char    *proc_width(t_specs params, t_flags flags, char *res);
int     len_cmp(int a, int b, int c);
void    ft_zero(void *s, size_t n, char c);
void    proc_flags(t_flags flags, t_specs params, char *str, char *res);
char	*ft_itoa_long(long long value, int base, char mod);
void    print_unint(va_list *args, t_specs params, t_flags flags, int *ret);
char    *str_magic(t_specs params, t_flags flags, int res_len, char *res);
char    *str_sorcery(char *str, t_specs params, t_flags flags);
void    print_char(va_list *args, t_specs params, t_flags flags, int *ret);
char    *char_voodoo(t_specs params, t_flags flags, char *str, int res_len);
char	*ft_itoa_long(long long value, int base, char mod);
char	*ft_itoa_unsigned(unsigned long long value, int base, char mod);
void    get_pct(char *str, va_list *args, int *ret);
void    ppcent(char *str, va_list *args, int *ret);
int     check_pct(char *str);
void	 get_pct_specs(char *set, va_list *args, char *res, int *ret);
int					ft_atoi(char *str);
void				ft_bzero(void *s, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(const char *s1, const char *s2);
size_t				ft_strlen(const char *str);
char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void	ft_putstr(char *str, t_specs params, int *ret);

#endif

#ifndef PRINTF_H
# define PRINTF_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdarg.h>

typedef struct		s_specs
{
    char			*flags;
    int             width;
    int             prec;
    char            *len;
    char            type;
    int             neg;
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
void    go_to(va_list *args, t_specs params, t_flags flags);
void    print_int(va_list *args, t_specs params, t_flags flags);
char	*ft_charjoin(const char *s1, const char s2);
void    get_specs(char *set, va_list *args);
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
void    print_unint(va_list *args, t_specs params, t_flags flags);
char    *str_magic(t_specs params, t_flags flags, int res_len, char *res);
char    *str_sorcery(char *str, t_specs params, t_flags flags);
void    print_char(va_list args, t_specs params, t_flags flags);
char    *char_voodoo(t_specs params, t_flags flags, char *str);


#endif

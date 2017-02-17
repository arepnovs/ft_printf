#include "printf.h"


char    *proc_width(t_specs params, t_flags flags, char *res)
{
    char *str;
    int len;
    int res_len;

    res_len = ft_strlen(res);
    str = str_magic(params, flags, res_len, res);
    if (params.width != 0 && params.width > res_len && params.width > params.prec)
        str = str_sorcery(str, params, flags);
    return(str);
}

long long	proc_len(va_list args, t_specs params)
{
    signed char	c;
    short int	s_i;
    
    if(params.len && params.type != 'p')
    {
        if (ft_strcmp(params.len, "hh") == 0 && (params.type != 'D'))
        {
            c = (signed char)va_arg(args, int);
            return ((long long)c);
        }
        else if (ft_strcmp(params.len, "h") == 0 && (params.type != 'D'))
        {
            s_i = (short int)va_arg(args, int);
            return ((long long)s_i);
        }
        else if (ft_strcmp(params.len, "l") == 0)
            return ((long long)va_arg(args, long));
        else if (ft_strcmp(params.len, "ll") == 0)
            return (va_arg(args, long long));
        else if (ft_strcmp(params.len, "j") == 0)
            return ((long long)va_arg(args, intmax_t));
        else if (ft_strcmp(params.len, "z") == 0)
            return ((long long)va_arg(args, size_t));
        else if (ft_strcmp(params.len, "t") == 0)
            return ((long long)va_arg(args, ptrdiff_t));
    }
    else if (params.type == 'p')
        return ((long long)va_arg(args, void*));
    return ((params.type == 'D') ? va_arg(args, long long) : (long long)va_arg(args, int));
}


void    print_int(va_list args, t_specs params, t_flags flags, int *ret)
{
    long long f;
    char *res;
    char *str;
    
    f = proc_len(args, params);
    if(f < 0)
    {
        f = -f;
        params.neg = 1;
    }
    if(params.type == 'd' || params.type == 'i' || params.type == 'D')
        res = ft_itoa_long(f, 10, params.type);
    else if(params.type == 'p')
        res = ft_itoa_long(f, 16, params.type);
    str = proc_width(params, flags, res);
    *ret = *ret + ((!str) ? 0 : ft_strlen(str));
    ft_putstr(str);
}




















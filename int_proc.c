#include "printf.h"

/*void    proc_flags(t_flags flags, t_specs params, char *str, char *res)
{
    
}*/

char    *proc_width(t_specs params, t_flags flags, char *res)
{
    char *str;
    char *ftr;
    int len;
    int res_len;

    res_len = ft_strlen(res);
    ftr = str_magic(params, flags, res_len, res);
    //printf("ftr = %s\n", ftr);
    //printf("width = %d\n", params.width);
    if (params.width != 0 && params.width > res_len && params.width > params.prec)
        ftr = str_sorcery(ftr, params, flags);
    return(ftr);
}

long long	proc_len(va_list args, t_specs params)
{
    signed char	c;
    short int	s_i;
    
    if(params.len)
    {
        if (ft_strcmp(params.len, "hh") == 0)
        {
            c = (signed char)va_arg(args, int);
            return ((long long)c);
        }
        else if (ft_strcmp(params.len, "h") == 0)
        {
            s_i = (short int)va_arg(args, int);
            return ((long long)s_i);
        }
        else if (ft_strcmp(params.len, "l") == 0)
            return ((long long)va_arg(args, long));
        else if (ft_strcmp(params.len, "ll") == 0)
            return (va_arg(args, long long));
    }
    return ((long long)va_arg(args, int));
}


void    print_int(va_list *args, t_specs params, t_flags flags)
{
    long long f;
    char *res;
    char *str;
    
    f = proc_len(*args, params);
    if(f < 0)
    {
        f = -f;
        params.neg = 1;
    }
    if(params.type == 'd' || params.type == 'i' || params.type == 'D')
        res = ft_itoa_long(f, 10, params.type);
    else if(params.type == 'x' || params.type == 'X')
        res = ft_itoa_long(f, 16, params.type);
    else if(params.type == 'o' || params.type == 'O')
        res = ft_itoa_long(f, 8, params.type);
    str = proc_width(params, flags, res);
   // proc_flags(flags, params, str, res);
    printf("str = |%s\n", str);
}




















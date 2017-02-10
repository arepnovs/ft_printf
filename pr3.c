#include "printf.h"

unsigned long long	proc_unlen(va_list args, t_specs params)
{
    unsigned char	c;
    unsigned short int	s_i;
    
    if(params.len)
    {
        if (ft_strcmp(params.len, "hh") == 0 && (params.type != 'O' && params.type != 'U'))
        {
            c = (unsigned char)va_arg(args, unsigned int);
            return ((unsigned long long)c);
        }
        else if (ft_strcmp(params.len, "h") == 0 && params.type != 'O' && params.type != 'U')
        {
            s_i = (unsigned short int)va_arg(args, unsigned int);
            return ((unsigned long long)s_i);
        }
        else if (ft_strcmp(params.len, "l") == 0)
            return ((unsigned long long)va_arg(args, unsigned long));
        else if (ft_strcmp(params.len, "ll") == 0)
            return (va_arg(args, unsigned long long));
        else if (ft_strcmp(params.len, "j") == 0)
            return ((unsigned long long)va_arg(args, uintmax_t));
        else if (ft_strcmp(params.len, "z") == 0)
            return ((unsigned long long)va_arg(args, size_t));
        else if (ft_strcmp(params.len, "t") == 0)
            return ((unsigned long long)va_arg(args, ptrdiff_t));
    }
    return ((params.type == 'O' || params.type == 'U') ?
            (unsigned long long)va_arg(args, unsigned long)
            : (unsigned long long)va_arg(args, unsigned int));
}


void    print_unint(va_list *args, t_specs params, t_flags flags, int *ret)
{
    char *res;
    char *str;
    
    if(params.type == 'x' || params.type == 'X')
        res = ft_itoa_unsigned(proc_unlen(*args, params), 16, params.type);
     else if(params.type == 'o' || params.type == 'O')
        res = ft_itoa_unsigned(proc_unlen(*args, params), 8, params.type);
     else if (params.type == 'u' || params.type == 'U')
         res = ft_itoa_unsigned(proc_unlen(*args, params), 10, params.type);
    //printf("res = %s\n", res);
    str = proc_width(params, flags, res);
    //proc_flags(flags, params, str, res);
    *ret = *ret + ft_strlen(str);
    printf("%s", str);
    //printf("str = |%s\n", str);
}

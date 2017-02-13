
#include "printf.h"

char    *char_voodoo(t_specs params, t_flags flags, char *str, int res_len)
{
    char *ftr;
    
    if (params.prec == -1 && ft_strlen(str) == 0)
    {
        str = ft_strnew(0);
        if (params.type != 'c' && params.width > 1)
        return(str);
    }
    if (params. prec > 0 && res_len > params.prec
        && (params.type != 'c' || params.type != 'C'))
        str = ft_strsub(str, 0, params.prec);
    if (params.width > 1)
    {
        ftr = (params.type == '%') ? ft_strnew(params.width - 1)
        : ft_strnew(params.width - ft_strlen(str));
        if (flags.zero == 1)
            ft_zero(ftr, (params.type == '%') ? (params.width - 1) : (params.width - ft_strlen(str)), '0');
        else
            ft_zero(ftr, (params.type == '%') ? (params.width - 1) : (params.width - ft_strlen(str)), ' ');
        str = (flags.minus == 1) ? ft_strjoin(str, ftr) : ft_strjoin(ftr, str);
    }
    return(str);
}

void    print_char(va_list *args, t_specs params, t_flags flags, int *ret)
{
    char *str = NULL;
    char f;
    int res_len;
    
    if (params.type != '%')
    {
        if (params.type == 'c' || params.type == 'C')
        {
            f = (char)va_arg(*args, int);
            str = ft_strnew(0);
            str[0] = f;
        }
        else if (params.type == 's' || params.type == 'S')
        {
            str = va_arg(*args, char*);
            if (str == NULL)
                str = "(null)";
        }
    }
    else
        str = params.pct;
    res_len = (str == NULL) ? 0 : ft_strlen(str);
    str = char_voodoo(params, flags, str, res_len);
    *ret = *ret + ft_strlen(str);
    (params.type == 'c' || params.type == 'C') ? ft_putcharf(str, params, ret) : ft_putstr(str);
}

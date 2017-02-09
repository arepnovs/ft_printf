
#include "printf.h"

char    *char_voodoo(t_specs params, t_flags flags, char *str)
{
    char *ftr;
    
    if (params.width > 1)
    {
        ftr = ft_strnew(params.width - ft_strlen(str));
        if (flags.zero == 1)
            ft_zero(ftr, (params.width - ft_strlen(str)), '0');
        else
            ft_zero(ftr, (params.width - ft_strlen(str)), ' ');
        str = (flags.minus == 1) ? ft_strjoin(str, ftr) : ft_strjoin(ftr, str);
    }
    return(str);
}

void    print_char(va_list args, t_specs params, t_flags flags)
{
    char *str;
    char f;
    
    if (params.type == 'c' || params.type == 'C')
    {
        f = (char)va_arg(args, int);
        str = ft_strnew(1);
        str[0] = f;
    }
    else if (params.type == 's' || params.type == 'S')
        str = va_arg(args, char*);
    str = char_voodoo(params, flags, str);
    printf("str = |%s\n", str);
}

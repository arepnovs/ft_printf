#include "printf.h"

char    *get_flags(char *str)
{
    int i;
    char *o_flags;
    
    i = 0;
    o_flags = ft_strnew(0);
    while(str[i] != '\0')
    {
        if (str[i] > '0' && str[i] <= '9')
        {
            while (str[i] >= '0' && str[i ] <= '9')
                i++;
        }
        if (check_flags(str[i]) == 1 && rep_check(o_flags, str[i], i) != 0
            && str[i] != '\0')
            o_flags = ft_charjoin(o_flags, str[i]);
        i++;
    }
    return(o_flags);
}

void    get_pct(char *str, va_list args, int *ret)
{
    char *pc;
    char *z;
    int i;
    int f;
    
    i = 0;
    f = 1;
    z = ft_strnew(0);
    pc = ft_strnew(0);
    while(str[i])
    {
        while (str[i] && f <= 2)
        {
            pc = ft_charjoin(pc, str[i]);
            if (str[i + 1] == '%')
                f++;
            i++;
        }
        if(check_specs(pc[ft_strlen(pc) - 1]) != 1
           || (check_specs(pc[ft_strlen(pc) - 1]) == 1 && f >= 2))
            ppcent(pc, args, ret);
        else
            get_specs(pc, args, ret, z);
        pc = ft_strnew(0);
        f = 1;
    }
}

void	 get_pct_specs(char *set, va_list args, char *res, int *ret)
{
    t_specs params;
    t_flags flags;
    
    bzero_params(&params);
    flags = org_flags(get_flags(set));
    params.width = get_width(set);
    params.prec = get_precision(set);
    params.len = get_length(set);
    params.type = get_types(set);
    params.pct = res;
    go_to(args, params, flags, ret);
}


void ppcent(char *str, va_list args, int *ret)
{
    char *res;
    char *specs;
    int i;
    int f;
    
    i = 0;
    f = 0;
    specs = ft_strnew(0);
    while (f < 2 && str[i])
    {
        if (str[i] == '%')
            f++;
        if (f != 2)
            specs = ft_charjoin(specs, str[i]);
        i++;
    }
    res = ft_strsub(str, i - 1, ft_strlen(str));
    specs = ft_charjoin(specs, '%');
    get_pct_specs(specs, args, res, ret);
}

int    get_width(char *str)
{
    int i;
    char *o_width;
    char *f_width;
    
    i = 0;
    o_width = ft_strnew(0);
    f_width = ft_strnew(0);
    while(str[i])
    {
        if((str[i - 1] < '0' || str[i - 1] > '9') && str[i] >= '0'
           && str[i] <= '9' && ft_strlen(o_width) != 0)
        {
            if (ft_atoi(o_width) != 0)
                f_width = ft_strdup(o_width);
            ft_bzero(o_width, ft_strlen(o_width));
        }
        if(str[i] == '.')
        {
            i++;
            while (str[i] >= '0' && str[i] <= '9')
                i++;
        }
        else if((str[i] >= '0' && str[i] <= '9') || (str[i] == '0' && str[i + 1] >= '0' && str[i + 1] <= '9'))
        {
            while (str[i] >= '0' && str[i] <= '9')
                 o_width = ft_charjoin(o_width,str[i++]);
            i--;
        }
        i++;
    }
    return((ft_atoi(o_width) == 0 && ft_atoi(f_width) != 0) ? ft_atoi(f_width) : ft_atoi(o_width));
}

int    get_precision(char *str)
{
    int i;
    int f;
    char *o_prec;
    int res;
    
    i = 0;
    f = 0;
    o_prec = ft_strnew(0);
    while(str[i])
    {
        if(ft_strlen(o_prec) != 0 && str[i] == '.' && str[i + 1] >= '0'
           && str[i + 1] <= '9')
            ft_bzero(o_prec, ft_strlen(o_prec));
        if(str[i] == '.')
        {
            f++;
            i++;
            while (str[i] >= '0' && str[i] <= '9')
            {
                o_prec = ft_charjoin(o_prec,str[i]);
                i++;
            }
            i--;
        }
        i++;
    }
    res = ft_atoi(o_prec);
    return((res == 0 && f != 0) ? -1 : res);
}

char    *get_length(char *str)
{
    int i;
    int len;
    char *raw_len;
    char *o_len;
    
    i = 0;
    raw_len = ft_strnew(0);
    o_len = ft_strnew(0);
    while(str[i])
    {
        if(check_len(str[i]) == 1 && str[i] != '\0')
            raw_len = ft_charjoin(raw_len, str[i]);
        i++;
    }
    len = ft_strlen(raw_len);
    if(raw_len[len - 1] != 'L')
    {
        o_len = ft_charjoin(o_len, raw_len[len - 1]);
        if(raw_len[len - 1] == raw_len[len - 2])
            o_len = ft_charjoin(o_len, raw_len[len - 1]);
    }
    else if (raw_len[len - 1] == 'L')
        o_len = ft_charjoin(o_len, raw_len[len - 1]);
    return(o_len);
}

char       get_types(char *set)
{
    int len;
    char type;
    
    len = ft_strlen(set);
    type = set[len - 1];
    return(type);
}



































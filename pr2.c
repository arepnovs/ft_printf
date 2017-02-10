#include "printf.h"

void    bzero_flags(t_flags *flag)
{
    flag->space = 0;
    flag->zero = 0;
    flag->plus = 0;
    flag->minus = 0;
    flag->hash = 0;
}

void    bzero_params(t_specs *params)
{
    params->width = 0;
    params->prec = 0;
    params->neg = 0;
}

int     len_cmp(int a, int b, int c)
{
    if (a >= b && a >= c)
        return (a);
    else if (b >= a && b >= c)
        return (b);
    else
        return (c);
}

void		ft_zero(void *s, size_t n, char c)
{
    size_t	i;
    char	*tmp;
    
    i = 0;
    tmp = (char *)s;
    while (i < n)
    {
        tmp[i] = c;
        i++;
    }
    tmp[i] = '\0';
}

char    *Ox_witchery(char *str, t_specs params)
{
    char *X_pref;
    char *x_pref;
    char *o_pref;
    
    X_pref = ft_strnew(2);
    x_pref = ft_strnew(2);
    o_pref = ft_strnew(1);
    X_pref = "0X";
    x_pref = "0x";
    o_pref = "0";
    if (params.type == 'x' || params.type == 'p')
        str = ft_strjoin(x_pref, str);
    else if (params.type == 'X')
        str = ft_strjoin(X_pref, str);
    else if (params.type == 'o')
        str = ft_strjoin(o_pref, str);
    return ((params.type == 'p' && params.prec == -1) ? x_pref : str);
}

char    *str_magic(t_specs params, t_flags flags, int res_len, char *res)
{
    char *str;
    int len;
    int i;
    
    i = 1;
    if (params.prec == -1 && ft_strcmp(res, "0\0") == 0)
    {
        str = ft_strnew(0);
        if (params.type != 'p')
            return(str);
    }
    len = (params.prec > res_len) ? params.prec : res_len;
    if (params.prec == 0)
    {
        len = res_len;
        i = (params.neg == 1) ? 1 : 0;
    }
    if ((params.neg == 1 || ((flags.plus == 1 || flags.space == 1) && params.neg != 1))
        && (params.type != 'x' && params.type != 'X' && params.type != 'o' && params.type != 'O'
            && params.type != 'u' && params.type != 'U' && params.type != 'p'))
        len++;
    str = ft_strnew(len);
    ft_zero(str, len, '0');
    if (params.type != 'x' && params.type != 'X' && params.type != 'o' && params.type != 'O'
        && params.type != 'u' && params.type != 'U' && params.type != 'p')
    {
        if ((flags.minus == 1 && params.neg == 1) || (params.prec == 0 && params.neg == 1) || params.neg == 1)
            str[0] = '-';
        else if (flags.plus == 1 && params.neg != 1)
            str[0] = '+';
        if (flags.space == 1 && params.neg != 1)
            str[0] = ' ';
    }
    while(str[i] != '\0')
    {
        if (params.prec != 0 || flags.plus == 1 || flags.space == 1)
        {
            while (i < len - res_len && len != res_len)
                i++;
        }
        str[i] = *res;
        res++;
        i++;
    }
    if (params.type == 'p' || (flags.hash == 1 && ft_atoi(str) != 0 &&(params.type == 'x' || params.type == 'X'
        || params.type == 'o' || params.type == 'O')))
        str = Ox_witchery(str, params);
    return(str);
}

char    *str_sorcery(char *str, t_specs params, t_flags flags)
{
    char *res;
    int i;
    
    i = 0;
    res = ft_strnew(params.width - ft_strlen(str));
    if (params.prec == 0 && flags.zero == 1)
        ft_zero(res, (params.width - ft_strlen(str)), '0');
    else
        ft_zero(res, (params.width - ft_strlen(str)), ' ');
    //printf("1str = %s\n", str);
    res = (flags.minus == 1) ? ft_strjoin(str, res) : ft_strjoin(res, str);
    //printf("2str = %s\n", str);
    while (res[i])
    {
        if ((str[0] == '+' || str[0] == '-') && res[0] == '0')
        {
            res[0] = str[0];
            res[ft_strlen(res) - ft_strlen(str)] = '0';
        }
        else if (str[0] == ' ' && flags.zero == 1)
            res[0] = str[0];
        else if (str[0] == ' ' && flags.zero != 1)
            i++;
        i++;
    }
    if ((str[1] == 'x' || str[1] == 'X') && res[0] == '0' && flags.zero != 0)
    {
        res[1] = str[1];
        res[ft_strlen(res) - ft_strlen(str) + 1] = '0';
    }
    return (res);
}







































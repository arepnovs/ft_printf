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
        if (check_flags(str[i]) == 1 && rep_check(str, str[i], i) != 0 && str[i] != '\0')
            o_flags = ft_charjoin(o_flags, str[i]);
        i++;
    }
    return(o_flags);
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

int    get_precision(char * str)
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
    //free(raw_len);
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



































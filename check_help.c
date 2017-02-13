#include "printf.h"

int check_wrong(char *str)
{
    int i = 0;
    
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
        {
            if (check_specs(str[i]) == 0 && check_flags(str[i]) == 0 && check_len(str[i]) == 0
            && str[i] !='.' && str[i] != '%')
                return (i);
        }
        i++;
    }
    return(-1);
}


t_flags     org_flags(char *str)
{
    t_flags org;
    
    bzero_flags(&org);
    while (*str)
    {
        if (*str == ' ')
            org.space = 1;
        if (*str == '0')
            org.zero = 1;
        if (*str == '+')
            org.plus = 1;
        if (*str == '-')
            org.minus = 1;
        if (*str == '#')
            org.hash = 1;
        str++;
    }
    if (org.zero == 1 && org.minus == 1)
        org.zero = 0;
    if (org.space == 1 && org.plus == 1)
        org.space = 0;
    return(org);
}

int check_pct(char *str)
{
    int i;
    int p;
    
    p = 0;
    i = 0;
    //ft_putstr(str);
    while (str[i])
    {
        if (str[i] == '%')
            p++;
        i++;
    }
    return ((p > 1) ? 1 : 0);
}

int		rep_check(char *str, char c, int j)
{
    int i;
    
    if (j == 0)
        i = 1;
    else
        i = 0;
    while (str[i] && i < j)
    {
        if (str[i] == c)
            return (0);
        i++;
    }
    return (1);
}

int     check_flags(char c)
{
    char *flags;
    int i;
    
    i = 0;
    flags = "+-0 #";
    while(flags[i])
    {
        if(flags[i] == c)
            return(1);
        i++;
    }
    return(0);
}

int     check_len(char c)
{
    char *len;
    int i;
    
    i = 0;
    len = "hlLjzt";
    while(*len)
    {
        if(*len == c)
            return(1);
        len++;
    }
    return(0);
}

int     check_specs(char c)
{
    char *specs;
    int i;
    
    i = 0;
    specs = "sSpdDioOuUxXcCb";
    while(*specs)
    {
        if(*specs == c)
            return(1);
        specs++;
    }
    return(0);
}

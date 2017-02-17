
#include "printf.h"

/*unsigned char    *ft_itow(int w)
{
    unsigned char *str;
    char k;
    
    str = ft_strnew(3);
    k = w;
    str[0] = (k<<6) + 224;
    str[1] = (k<<2);
    str[1] = (str[1]>>2) + 192;
    str[2] = (k<<2);
    str[2] = (str[2]>>2) + 128;
    //str[2] = 0;
   
    return(str);
}
*/
char    *ft_itow(int wch)
{
    char    *res;
    unsigned char   tw[3];
    unsigned char   tr[4];
    //int c;
  
    if (wch < 128)
    {
        res = ft_strnew(2);
        res[0] = wch;
        return (res);
    }
    if (wch > 127 && wch < 2048)
    {
        tw[0] = (wch >> 6) + 192;
        tw[1] = (wch << 2);
        tw[1] = (tw[1] >> 2) + 128;
        tw[2] = '\0';
        return (ft_strdup((char *)tw));
    }
    tr[0] = (wch >> 12) + 224;
    tr[1] = (wch >> 6);
    tr[1] = tr[1] << 2;
    tr[1] = (tr[1] >> 2) + 128;
    tr[2] = (wch << 2);
    tr[2] = (tr[2] >> 2) + 128;
    tr[3] = '\0';
    return (ft_strdup((char *)tr));
}

char    *ft_itowstr(int *wch, int prec)
{
    int i;
    int len;
    char *str;
    char *symb;

    str = ft_strnew(0);
    len = 0;
    i = 0;
    if(!wch)
        return("(null)");
    if (prec > 0)
    {

        while (wch[i] && len <= prec)
        {
            symb = ft_itow(wch[i]);
            len = len + ft_strlen(symb);
            if (len <= prec)
                str = ft_strjoin(str, symb);
          i++;
        }
    }
    else
    {
        while (wch[i])
        {
          str = ft_strjoin(str, ft_itow(wch[i]));
          i++;
        }
    }   
    return (str);
}

char    *char_voodoo(t_specs p, t_flags flags, char *str, int res_len)
{
    char *ftr;
    int len;

    if (p.prec == -1 && ft_strlen(str) == 0)
    {
        str = ft_strnew(0);
        if ((p.type != 'c' && p.width > 1) && (p.type != 's' && p.width < 1))
            return (str);
    }
    if (p.prec == -1 && (p.type == 's' || p.type == 'S'))
         str = ft_strnew(0);
    if (p.prec > 0 && res_len > p.prec && (p.type != 'c' || p.type != 'C'))
        str = ft_strsub(str, 0, p.prec);
    len = ft_strlen(str);
    if (p.width > 1 && p.width > len)
    {
        ftr = (p.type == '%' || (p.type == 'c' && p.width <= 2))
        ? ft_strnew(p.width - 1) : ft_strnew(p.width - len);
        if (flags.zero == 1)
            ft_zero(ftr, (p.type == '%' || (p.type == 'c' && p.width <= 2))
                ? (p.width - 1) : (p.width - len), '0');
        else
            ft_zero(ftr, (p.type == '%' || (p.type == 'c' && p.width <= 2))
                ? (p.width - 1) : (p.width - len), ' ');
        str = (flags.minus == 1) ? ft_strjoin(str, ftr) : ft_strjoin(ftr, str);
    }
    return(str);
}

void    print_char(va_list args, t_specs params, t_flags flags, int *ret)
{
    char *str = NULL;
    int res_len;
    //int wch;

    str = ft_strnew(0);
    if (params.type != '%')
    {
        if (params.type == 'c' || params.type == 'C')
        {
            if (ft_strcmp(params.len, "l") != 0 && params.type != 'C')
                str[0] = (char)va_arg(args, int);
            else
                str = ft_itow(va_arg(args, int));
        }
        else if (params.type == 's' || params.type == 'S')
        {
            if(params.type == 'S' || ft_strcmp(params.len, "l") == 0)
                str = ft_itowstr(va_arg(args, int*), params.prec);
            else
                str = va_arg(args, char*);
            if (str == NULL && params.width > 1)
                str = ft_strnew(0);
            else if (str == NULL)
                str = "(null)";
        }
    }
    else
        str = params.pct;
    res_len = (str == NULL || (ft_strcmp(str, "(null)")) == 0) ? 0 : ft_strlen(str);
    str = char_voodoo(params, flags, str, res_len);
    *ret = *ret + ft_strlen(str);
    (params.type == 'c' || params.type == 'C') ? ft_putcharf(str, params, ret) : ft_putstr(str);
}

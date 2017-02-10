
void simple_printf(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    
    while (*fmt != '\0') {
        if (*fmt == 'd') {
            int i = va_arg(args, int);
            printf( "%d\n", i ) ;
        } else if (*fmt == 'c') {
            int c = va_arg(args, int);
            printf( "%c\n", (char)c ) ;
        } else if (*fmt == 'f') {
            double d = va_arg(args, double);
            printf( "%f\n", d ) ;
        }
        ++fmt;
    }
    
    va_end(args);
}

int main()
{
    simple_printf("dcff", 3, 'a', 1.999, 42.5);
}


/*void    str_mod(char **str, char mod)
 {
 char lhex[3] = "0x\0";
 char uhex[3] = "0X\0";
 char oct[2] = "0\0";
 
 if (mod == 'x')
 *str = ft_strjoin(lhex, *str);
 else if (mod == 'X')
 *str = ft_strjoin(uhex, *str);
 else if (mod == 'o' || mod == 'O')
 *str = ft_strjoin(uhex, *str);
 }*/


void    proc_flags(t_flags flags, t_specs params, char *str, char *res)
{
    int i;
    int p;
    int j;
    int res_len;
    
    i = 1;
    p = params.prec;
    res_len = ft_strlen(res);
    printf("p = %d\n", p);
    printf("res_len = %d\n", res_len);
    if((j = p - res_len) <= 0)
        j = -1;
    else
        j = p - res_len + 1;
    if(flags.plus == 1 && params.neg != 1 && params.type != 'x'
       && params.type != 'X' && params.type != 'o' && params.type != 'O')
    {
        //write(1, "aaa\n", 4);
        str[0] = '+';
    }
    else if (params.neg == 1 && params.type != 'x'
             && params.type != 'X' && params.type != 'o' && params.type != 'O')
        str[0] = '-';
    else
    {
        i = 0;
        j--;
    }
    //printf("i = %d\n", i);
    //printf("j = %d\n", j);
    //printf("plus = %d\n", flags.plus);
    //if (params.width >= params.prec && (flags.plus == 1 || flags.minus != 1);)
    //{
    while (str[i])
    {
        while(i < j)
            i++;
        while(*res && str[i] != '\0')
        {
            str[i] = *res;
            res++;
            i++;
        }
        if(flags.zero == 1 && str[i] != '\0')
            str[i] = '0';
        else if (str[i] != '\0')
            str[i] = ' ';
        i++;
    }
    //}
    
}

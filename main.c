#include "printf.h"
//#include <stdio.h>
//#include <stdarg.h>

//#0-+
//hh, h, l, ll, j, z

int main()
{
    short int a = 59;
    
    //ft_printf("hu = %7.3X\nanother hu = %+10.4i\none more hu = %-10.8D\n", 156, 165, 30);
    //printf("hu = %7.3X\nanother hu = %010.4i\none more hu = %-10.8D\n", 156, -165, 30);
    //ft_printf("str =        |%-04.10i\n", 165);
    //ft_printf("3  |%10465=690 0 0 000 0.4i\n", 165);
    //ft_printf("2  |%+d\n", 165);
    ft_printf("1     |%#10.x\n", 0);
    ft_printf("1     |%#10.X\n", 0);
    ft_printf("1     |%U\n", 123456789123456789);
    ft_printf("1     |%u\n", 123456789123456789);
     ft_printf("1     |%+010u\n", 165);
    ft_printf("1     |%+ 010u\n", 165);
    ft_printf("1     |%10u\n", 165);
    ft_printf("1     |%-10u\n", 165);
    ft_printf("1     |%10.4u\n", 165);
    /*ft_printf("1  |%10.14d\n", 165);
    ft_printf("1  |%+10.7kkkd\n", 165);
    ft_printf("1  |%0.10i\n\n", -165);
    ft_printf("2  |%+0.10  12i\n", 165);
      printf("1     |%0#10x\n", 165);
    ft_printf("2  |%+10 .4i\n\n", -165);
    ft_printf("3  |%10 0.4i\n", 165);
    ft_printf("3  |%+010.4i\n\n",-165);*/
    //printf("3  |%10 0.4i\n", 165);
    //printf("2  |%+010 -85-35%76d\n", 165, 87);
    printf("\n");
    printf("1     |%#10.x\n", 0);
    printf("1     |%#10.X\n", 0);
    printf("1     |%u\n", 123456789123456789);
    printf("1     |%U\n", 123456789123456789);
    // printf("\n");
    printf("1     |%+010u\n", 165);
    printf("1     |% +010u\n", 165);
    printf("1     |%10u\n", 165);
    printf("1     |%-10u\n", 165);
    printf("1     |%10.4u\n", 165);
    /*printf("1  |% .010097#00#0350-.0056ld\n", 165);
    printf("1  |%+10.mmm7kkkd\n", 165);
    printf("1  |%0.10i\n", -165);
    printf("2  |%+0.10  12i\n", 165);
    printf("2  |%+10 .4i\n", -165);
    printf("3  |%10 0.4i\n", 165);
    printf("3  |%+010.4i\n",-165);*/
    /*printf("4  |%10.6i\n", 165);
    printf("4  |%10.6i\n\n", -165);
    printf("5  |%6.10i\n", 165);
    printf("5  |%6.10i\n\n", -165);
    printf("6  |%+i\n", 165);
    printf("6  |%+i\n\n",-165);
    printf("7  |%-i\n", 165);
    printf("7  |%-i\n\n", -165);
    printf("8  |%+10i\n", 165);
    printf("8  |%+10i\n\n", -165);
    printf("9  |%-.6i\n", 165);
    printf("9  |%-.6i\n\n",+165);
    printf("10 |%+10.6i\n", 165);
    printf("10 |%+10.6i\n\n", -165);
    printf("11 |%-6.10i\n", 165);
    printf("11 |%-6.10i\n\n", -165);
    printf("12 |%0i\n", 165);
    printf("12 |%0i\n\n",-165);*/
        return(0);
}

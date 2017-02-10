#include "printf.h"
//#include <stdio.h>
//#include <stdarg.h>

//#0-+
//hh, h, l, ll, j, z

int main()
{
    short int a = 59;
    char l = 'c';
    long long g = 9494949499949;
    int c = 949;
    char *str = "djhjk";
    char k = 'k';
    //ft_printf("3  |% s\n","absd");
    //ft_printf("3  |%hU\n",-999999999999999);
    //ft_printf("3  |%hhU\n",-999999999999999);
    //ft_printf("3  |%hhO\n",-999999999999999);
    //ft_printf("3  |%.p\n",0);
    ft_printf("my = %d\n",ft_printf("my = |%%10+0%3%0d\n",165));
    ft_printf("my = |%d\n",165);
    ft_printf("my   |%0.5%10%0d\n",165);
    ft_printf("my = |%%10+0%3%0d\n",165);
    ft_printf("my = |%%%10+0%10%0d\n",165);
    ft_printf("my = |%%10+0%%%%%10%0d\n",165);
    /*ft_printf("my = |%p\n",&l);
    ft_printf("my = |%p\n",&l);
    ft_printf("my = |%p\n",&l);
    ft_printf("my = |%p\n",&l);*/
    /*ft_printf("3  |%hhx\n",999999999999999);
    ft_printf("3  |%hhX\n",999999999999999);
    ft_printf("3  |%hhu\n",999999999999999);
    ft_printf("3  |%hhU\n",999999999999999);
    ft_printf("3  |%hho\n",999999999999999);
    ft_printf("3  |%hhO\n",999999999999999);*/

    //xsprintf("3  |%#o\n",126);
    //printf("1     |% s\n","absd");
    printf("%d\n",printf("my = |%%10+0%3%0d\n",165));
    printf("1    |%10+0%10%0d\n",165);
    printf("1    |%0.5%10%0d\n",165);
    printf("my = |%%10+0%3%0d\n",165);
    printf("my = |%%%10+0%10%0d\n",165);
    printf("my = |%%10+0%%%%%10%0d\n",165);
    //printf("1  |%.#%.#%.%\n",&l);

    /*printf("3  |%hhx\n",999999999999999);
    printf("3  |%hhX\n",999999999999999);
    printf("3  |%hhu\n",999999999999999);
    printf("3  |%hhU\n",999999999999999);
    printf("3  |%hho\n",999999999999999);
    printf("3  |%hhO\n",999999999999999);*/
    return(0);
}

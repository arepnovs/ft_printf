#include "printf.h"
//#include <stdio.h>
//#include <stdarg.h>

//#0-+
//hh, h, l, ll, j, z

int main()
{
    short int a = 59;
    char c = 'c';
    long long l = 9494949499949;
    long long g = 9494949499949;
    //ft_printf("3  |%#o\n",126);
    //ft_printf("3  |%hU\n",-999999999999999);
    //ft_printf("3  |%hhU\n",-999999999999999);
    //ft_printf("3  |%hhO\n",-999999999999999);
    ft_printf("3  |%p\n",l);
    ft_printf("3  |%p\n",g);
    /*ft_printf("3  |%hhx\n",999999999999999);
    ft_printf("3  |%hhX\n",999999999999999);
    ft_printf("3  |%hhu\n",999999999999999);
    ft_printf("3  |%hhU\n",999999999999999);
    ft_printf("3  |%hho\n",999999999999999);
    ft_printf("3  |%hhO\n",999999999999999);*/

    //xsprintf("3  |%#o\n",126);
    //printf("1  |%d\n", -100);
    printf("3  |%p\n",l);
    printf("1  |%p\n",g);
    /*printf("3  |%hhx\n",999999999999999);
    printf("3  |%hhX\n",999999999999999);
    printf("3  |%hhu\n",999999999999999);
    printf("3  |%hhU\n",999999999999999);
    printf("3  |%hho\n",999999999999999);
    printf("3  |%hhO\n",999999999999999);
    /*ft_printf("123456789  |%+10.mmm7kkkd\n", 165);
    ft_printf("1  |%0.10i\n", -165);
    ft_printf("2  |%+0.10  12i\n", 165);
    ft_printf("2  |%+10 .4i\n", -165);
    ft_printf("3  |%10 0.4i\n", 165);
    ft_printf("3  |%+010.4i\n",-165);
    
    printf("1  |%+10.mmm7kkkd\n", 165);
    printf("1  |%0.10i\n", -165);
    printf("2  |%+0.10  12i\n", 165);
    printf("2  |%+10 .4i\n", -165);
    printf("3  |%10 0.4i\n", 165);
    printf("3  |%+010.4i\n",-165);
    
    /*ft_printf("1     |%-10hyys\n", "abcd");
    ft_printf("1     |%.1s\n", "abcd");
    ft_printf("1     |%.10s\n", "abcd");
    ft_printf("1     |%p\n", "abcd");
    ft_printf("1     |% +50p\n", "abcd");
    ft_printf("1     |%.50p\n", "abcd");
    ft_printf("1     |%-50p\n", "abcd");
    ft_printf("1     |%50.70p\n", "abcd");
    
    printf("1     |%-10hyys\n", "abcd");
    printf("1     |%.1s\n", "abcd");
    printf("1     |%.10s\n", "abcd");
    printf("1     |%p\n", "abcd");
    printf("1     |% +50p\n", "abcd");
    printf("1     |%.50p\n", "abcd");
    printf("1     |%-50p\n", "abcd");
    printf("1     |%50.70p\n", "abcd");*/
    return(0);
}

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
    printf("1     |%50.70p\n", "abcd");
    /*ft_printf("1     |%d\n", 99999999);
    //ft_printf("1     |%.X\n", 0);
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
   /* printf("\n");
    printf("1     |%ld\n", 99999999);
    printf("1     |%.0X\n", 0);
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

#include "printf.h"

void	go_to(va_list *args, t_specs params, t_flags flags, int *ret)
{
	if (params.type == 'd' || params.type == 'D'
        || params.type == 'i' || params.type == 'p')
		print_int(args, params, flags, ret);
	else if (params.type == 'x' || params.type == 'X' || params.type == 'o'
			 || params.type == 'O' || params.type == 'u' || params.type == 'U')
		print_unint(args, params, flags, ret);
	else if (params.type == 'c' || params.type == 'C'
             || params.type == 's' || params.type == 'S')
		print_char(args, params, flags, ret);
}

void	 get_specs(char *set, va_list *args, int *ret)
{
	t_specs params;
	t_flags flags;
	
	bzero_params(&params);
	params.flags = get_flags(set);
	flags = org_flags(params.flags);
	params.width = get_width(set);
	params.prec = get_precision(set);
	params.len = get_length(set);
	params.type = get_types(set);
	go_to(args, params, flags, ret);
}

int		get_args(va_list *args, const char *format)
{
	int i;
	int len;
	char	*set;
    int ret;
	
	i = 0;
    ret = 0;
	set = ft_strnew(0);
	len = ft_strlen(format);
	while(format[i] != '\0' && i < len)
	{
		while(format[i] != '%' && i < len && format[i] != '\0')
        {
			i++;
            ret++;
        }
		if(format[i] == '%' && format[i] != '\0' && i < len)
		{
			i++;
			while(check_specs(format[i]) != 1 && i < len && format[i] != '\0')
			{
				set = ft_charjoin(set, format[i]);
				i++;
			}
			set = ft_charjoin(set, format[i]);
			get_specs(set, args, &ret);
			ft_bzero(set, ft_strlen(set));
		}
		i++;
	}
   	return(ret);
}

int		ft_printf(const char *format, ...)
{
	int		i;
	va_list		args;
	
	i = 0;
	if (format)
	{
		va_start(args, format);
		i = get_args(&args, format);
		va_end(args);
	}
	return (i);
}

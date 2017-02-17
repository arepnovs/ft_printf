NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRC = abra_formating.c\
		char_proc.c\
		check_help.c\
		check_help2.c\
		ft_itoa_long.c\
		ft_itoa_unsigned.c\
		ft_printf.c\
		ft_putcharf.c\
		get_params.c\
		get_params2.c\
		int_proc.c\
		lib_func.c\
		lib_func2.c\
		magicus_formaticus.c\
		organiser.c\
		unsign_and_long_proc.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
		@echo "Doing magic!!!"
		@gcc $(FLAGS) -c $(SRC)
		@ar rc $(NAME) $(OBJ)
		@echo "Vzhuh!!! Printf is ready!!"

		
clean:
		@rm -f $(OBJ)
		@echo "Objects removed"	
fclean:
		@make clean
		@rm -f $(NAME)
		@echo "Executable removed"		
re:
		@make fclean
		@make all
		@ar rc $(NAME) $(OBJ)
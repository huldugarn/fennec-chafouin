NAME = libftprintf.a
HEADER = ft_printf.h Libft/libft.h
SRC_PATH=./
OBJ_PATH=./
LIBS= Libft/libft.a
SRC = main.c aux0.c aux1.c aux2.c aux3.c aux4.c aux5.c aux6.c aux7.c

OBJ = $(SRC:.c=.o )

all : lib $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	libtool -static -o $(NAME) $(NAME) $(LIBS)

lib :
	make -C libft/

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	gcc -Wall -Werror -Wextra -o $@ -c $<

clean :
	/bin/rm -f $(OBJ)
	make clean -C libft/

fclean : clean
	/bin/rm -f $(NAME)
	make fclean -C libft/

re : fclean all
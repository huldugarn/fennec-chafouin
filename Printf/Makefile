# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 16:57:32 by rle-corr          #+#    #+#              #
#    Updated: 2016/04/19 11:31:59 by rle-corr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE_NAME = x
CMP_NAME = gcc
CMP_FLAG = -Wall -Werror -Wextra
DELETING = rm -f
ARCHIVES = ar -rc
INC_PATH = -I.
LIB_PATH = -L../Libft/
LIB_NAME = -lft
LIB_FLAG = $(LIB_PATH) $(LIB_NAME)
SRC_PATH = .
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC_NAME = ft_printf.c \
		   ft_printf_conversions1.c \
		   ft_printf_conversions2.c \
		   ft_printf_displays.c \
		   ft_printf_options1.c \
		   ft_printf_options2.c \
		   proto.c
SRC_FULL = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

.PHONY: all, clean, fclean, re

all : $(EXE_NAME)

$(EXE_NAME): $(OBJ_NAME)
	@$(CMP_NAME) $(CMP_FLAG) $(INC_PATH) ../Libft/libft.h $(LIB_FLAG) $(OBJ_NAME)

$(OBJ_NAME):
	@$(CMP_NAME) $(CMP_FLAG) $(INC_PATH) ../Libft/libft.h -c $(SRC_NAME) 

clean:
	@$(DELETING) $(OBJ_NAME)
	@echo Objects deleted.

fclean: clean
	@$(DELETING) $(EXE_NAME)
	@echo Executable deleted.

re: fclean all

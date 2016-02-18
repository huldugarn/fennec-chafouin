# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 16:57:32 by rle-corr          #+#    #+#              #
#    Updated: 2016/01/31 14:41:30 by rle-corr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE_NAME = fillit
CMP_NAME = gcc
CMP_FLAG = -Wall -Werror -Wextra
DELETING = rm -f
ARCHIVES = ar -rc
INC_PATH = -I./includes
LIB_PATH = -L./libft
LIB_NAME = -lft
LIB_FLAG = $(LIB_PATH) $(LIB_NAME)
SRC_PATH = ./sources
SRC_NAME = main.c read.c resolve.c display.c error.c
SRC_FULL = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

.PHONY: all, clean, fclean, re

all : $(EXE_NAME)

$(EXE_NAME): mklib
	@$(CMP_NAME) $(CMP_FLAG) $(LIB_FLAG) $(INC_PATH) $(SRC_FULL) -o $(EXE_NAME)
	@echo Executable created.

mklib:
	@make -C ./libft/

clean:
	@$(DELETING) $(OBJ_NAME)
	@make -C ./libft/ clean
	@echo Objects deleted.

fclean: clean
	@$(DELETING) $(EXE_NAME)
	@$(DELETING) ./libft/libft.a 
	@echo Library deleted.

re: fclean all

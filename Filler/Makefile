# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 16:57:32 by rle-corr          #+#    #+#              #
#    Updated: 2016/11/22 11:49:54 by rle-corr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE_NAME = rle-corr.filler
TMP_NAME = test
CMP_NAME = gcc
CMP_FLAG = -Wall -Werror -Wextra
DELETING = rm -f
ARCHIVES = ar -rc
INC_PATH = -I./includes
LIB_PATH = -L./Libft
LIB_NAME = -lft
LIB_FLAG = $(LIB_PATH) $(LIB_NAME)
SRC_PATH = ./sources
SRC_NAME = 00_main.c
SRC_FULL = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

.PHONY: all, clean, fclean, re

all : $(EXE_NAME)

$(EXE_NAME): mklib
#	@$(CMP_NAME) $(CMP_FLAG) $(LIB_FLAG) $(INC_PATH) $(SRC_FULL) -o $(EXE_NAME)
	@$(CMP_NAME) $(CMP_FLAG) $(LIB_FLAG) $(INC_PATH) $(SRC_FULL) -o $(TMP_NAME)
	@echo Executable created.

mklib:
	@make -C ./Libft/

clean:
	@$(DELETING) $(OBJ_NAME)
	@make -C ./Libft/ clean
	@echo Objects deleted.

fclean: clean
	@$(DELETING) $(EXE_NAME)
	@$(DELETING) ./Libft/libft.a 
	@echo Library deleted.

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/16 15:46:22 by rle-corr          #+#    #+#              #
#    Updated: 2016/08/16 16:42:32 by rle-corr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXENAME=fdf
CMPNAME=gcc
CMPFLAG=-Wall -Werror -Wextra
INCPATH=./includes/
HEADERS= ./includes/fdf_0_header.h
LIBFLAG=-L ../includes/libft/ -lft
MLXFLAG=-lmlx -framework OpenGL -framework Appkit
INCFULL=$(addprefix $(INCPATH),$(LIBFLAG))\
		$(addprefix $(INCPATH),$(MLXFLAG))
SRCPATH=./sources
SRCNAME=fdf_1_main.c\
		fdf_2_auxiliary_input_parsing.c\
		fdf_3_auxiliary_mlx_hooks.c\
		fdf_4_auxiliary_interactions.c\
		fdf_5_auxiliary_calculations.c\
		fdf_6_auxiliary_drawing.c
SRCFULL=$(addprefix $(SRCPATH)/,$(SRCNAME))
OBJPATH=./objects
OBJNAME=$(SRCNAME:.c=.o)
OBJFULL=$(addprefix $(OBJPATH)/,$(OBJNAME))

# -----------------------------------------------------------------------------#
#	Aide 
# -----------------------------------------------------------------------------#

.PHONY: help

help:
	@echo "<*----------------------------------------------------------------*>"
	@echo " | Available rules"
	@echo " |   - all	:	code compilation and executable creation"
	@echo " |   - clean	:	objects deleting"
	@echo " |   - fclean	:	objects and executable deleting"
	@echo " |   - re	:	fclean + all"
	@echo "<*----------------------------------------------------------------*>"

# -----------------------------------------------------------------------------#
#	Compilation 
# -----------------------------------------------------------------------------#

.PHONY: all, linkage, clean, fclean, re

all: $(EXENAME)

$(EXENAME): linkage

linkage: $(OBJFULL)
	@echo Objects____created
	@$(CMPNAME) -o $(EXENAME) $(OBJNAME) $(CMPFLAG) $(MLXFLAG) $(LIBFLAG)
	@echo Executable_created

$(OBJPATH)/%.o: $(HEADERS) $(SRCPATH)/%.c
	$(CMPNAME) $(CMPFLAG) -c $^

clean:
	@rm -f $(OBJNAME)
	@echo Objects____deleted

fclean: clean
	@rm -f $(EXENAME)
	@echo Executable_deleted

re: fclean all

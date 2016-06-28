EXENAME=fdf
CMPNAME=gcc
CMPFLAG=-Wall -Werror -Wextra
MLXFLAG=-L Libft/ -lft \
		-lmlx -framework OpenGL -framework Appkit
INCLUDE=-I Libft/
SRCNAME=main.c
OBJNAME=$(SRCNAME:.c=.o)



all: $(EXENAME)

$(EXENAME): linkage

linkage: objectify
	$(CMPNAME) -o $(EXENAME) $(OBJNAME) $(CMPFLAG) $(MLXFLAG)

objectify:
	$(CMPNAME) -c $(SRCNAME) fdf.h

clean:
	rm -f $(OBJNAME)

fclean: clean
	rm -f $(EXENAME)

re: fclean all

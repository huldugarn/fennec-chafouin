EXENAME=fdf
CMPNAME=gcc
CMPFLAG=-Wall -Werror -Wextra
MLXFLAG=-lmlx -framework OpenGL -framework Appkit
SRCNAME=main.c
OBJNAME=$(SRCNAME:.c=.o)



all: $(EXENAME)

$(EXENAME): linkage

linkage: objectify
	$(CMPNAME) -o $(EXENAME) $(OBJNAME) $(CMPFLAG) $(MLXFLAG)

objectify:
	$(CMPNAME) -c $(SRCNAME)

clean:
	rm -f $(OBJNAME)

fclean: clean
	rm -f $(EXENAME)

re: fclean all

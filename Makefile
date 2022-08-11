# ------------------------------ Sources ------------------------------
###### Files #####
LIBFT = cd libft && make
LIB = libft/libft.a

###### OBJ ########
SRC := $(wildcard *.c)
C_EXECUTABLE :=$(SRC:.c=)

###### NAME #######
NAME = push_swap

###### RULES ######
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I.

# ------------------------------ Colors ------------------------------

BOLD_PURPLE	=	\033[1;35m

BOLD_CYAN	=	\033[1;36m

BOLD_YELLOW	=	\033[1;33m

NO_COLOR	=	\033[0m

# ------------------------------ Messages ------------------------------

COMP_START	=	echo "\n🚧 $(BOLD_YELLOW)Make: $(NO_COLOR)Starting the compilation...\n"

FCLEANED	=	echo "\n🧼 $(BOLD_YELLOW)Fclean: $(NO_COLOR)Removed the executables \n"

EXEC_READY	=	echo "\n📟 Executable ready!\n"

# ------------------------------ Rules ------------------------------

all: comp_start $(NAME)

comp_start:
	@$(COMP_START)
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(C_EXECUTABLE:=.o)
	$(CC) $(CFLAGS) $(C_EXECUTABLE:=.o) libft/libft.a -o $(NAME)
	@$(EXEC_READY)

clean:
	$(RM)	$(C_EXECUTABLE:=.o)
	@make clean -C ./libft

fclean: clean
	$(RM)	$(LIB)
	$(RM)	$(NAME)
	@$(FCLEANED)

re:	fclean	all

.PHONY: all fclean clean re

NAME := pipex
SRC :=  $(wildcard ft_*.c)
OBJ  := $(SRC:.c=.o)
TEST := Test
MAKEFLAGS += -r
CFLAGS :=

RM := rm -f
CC := cc
AR = ar rcs
CFLAGS := -Werror -Wextra -Wall

%.o : %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) main.c $(OBJ) -Llibftprintf -lftprintf -Llibft -lft  -o $(NAME)

$(LIBFT):
	cd $(LIBFT_DIR); make;

$(PRINTF):
	cd $(PRINTF_DIR); make;

# === CLEANING UP ===

clean:
	$(RM) $(OBJ) $(OBJ:.o=.d)

fclean: clean
	$(RM) $(NAME)

re:	fclean all


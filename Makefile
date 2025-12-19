NAME := pipex
LIBFT_DIR := libft/
LIBFT := libft.a
PRINTF_DIR := libftprintf/
PRINTF := libftprintf.a
SRC :=  $(wildcard ft_*.c)
OBJ  := $(SRC:.c=.o)
TEST := Test 
MAKEFLAGS += -r

RM := rm -f
CC := cc 
AR = ar rcs
CFLAGS := -Werror -Wextra -Wall

%.o : %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) main.c -g3 $(OBJ) -Llibftprintf -lftprintf -Llibft -lft  -o $(NAME)

$(LIBFT):
	cd $(LIBFT_DIR); make;

$(PRINTF):
	cd $(PRINTF_DIR); make;

# === CLEANING UP ===
clean:
	cd $(LIBFT_DIR); make clean
	cd $(PRINTF_DIR); make clean
	$(RM) $(OBJ) $(OBJ:.o=.d)

fclean: clean
	cd $(LIBFT_DIR); make fclean
	cd $(PRINTF_DIR); make fclean
	$(RM) $(NAME)

re:	fclean all


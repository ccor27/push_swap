NAME        = push_swap
SRC         = main.c utils.c
OBJ         = $(SRC:.c=.o)
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

# Paths
PRINTF_DIR  = printf
PRINTF_LIB  = $(PRINTF_DIR)/libftprintf.a
INCLUDES    = -I. -I$(PRINTF_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(PRINTF_DIR) --silent
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C $(PRINTF_DIR) clean --silent

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(PRINTF_DIR) fclean --silent

re: fclean all

.PHONY: all clean fclean re

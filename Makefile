NAME        = push_swap
SRC         = main.c utils.c
OBJ         = $(SRC:.c=.o)
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
FSANITIZE	= -fsanitize=address -g3

# Paths
PRINTF_DIR  = printf
PRINTF_LIB  = $(PRINTF_DIR)/libftprintf.a
INCLUDES    = -I. -I$(PRINTF_DIR)

define LOADING_BAR_COMP
	@printf "\033[0;32mCompiling push_swap: ["
	@for i in `seq 1 20`; do \
		printf "█"; \
		sleep 0.05; \
	done; \
	printf "] ✔️\033[0m\n\n"
endef

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(PRINTF_DIR) --silent
	$(call LOADING_BAR_COMP)
	@$(CC) $(CFLAGS) $(OBJ) $(PRINTF_LIB) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES)  -c $< -o $@

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C $(PRINTF_DIR) clean --silent

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(PRINTF_DIR) fclean --silent

re: fclean all

.PHONY: all clean fclean re

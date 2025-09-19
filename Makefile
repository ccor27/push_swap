NAME        = push_swap
SRC         = push_swap.c sort_utils.c args_validation.c swap_moves.c rotate_moves.c put_moves.c sort_process.c \
            args_validation_utils.c move_executor.c target_finder.c sort_process_utils.c
OBJ         = $(SRC:.c=.o) 
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
FSANITIZE   = -fsanitize=address -g3

# Paths
LIBFT_DIR   = libft
LIBFT_LIB   = $(LIBFT_DIR)/libft.a
INCLUDES    = -I. -I$(LIBFT_DIR) -I$(LIBFT_DIR)

define LOADING_BAR_COMP
	@printf "\033[0;32mCompiling push_swap: ["
	@for i in `seq 1 20`; do \
		printf "█"; \
		sleep 0.05; \
	done; \
	printf "] ✔️\033[0m\n\n"
endef

define LOADING_BAR_CLEAN
	@printf "\033[0;31mCleaning objects: ["
	@for i in `seq 1 20`; do \
		printf "█"; \
		sleep 0.05; \
	done; \
	printf "] ✔️\033[0m\n\n"
endef

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) --silent      # Compilamos la libft
	$(call LOADING_BAR_COMP)
	@$(CC) $(CFLAGS) $(FSANITIZE) $(OBJ) $(LIBFT_LIB) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	$(call LOADING_BAR_CLEAN)
	@$(MAKE) -C $(LIBFT_DIR) clean --silent

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --silent

re: fclean all

.PHONY: all clean fclean re

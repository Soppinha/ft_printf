NAME		=	libftprintf.a

# ********************************* OUTPUT ********************************** #

TAG			=	ft_printf
RESET		=	\033[0m
C_TAG		=	\033[1;34m
C_BUILD		=	\033[0;32m
C_DONE		=	\033[1;32m
C_CLEAN		=	\033[0;33m
C_RM		=	\033[0;31m
LOG			=	printf "$(C_TAG)%-12s$(RESET) %b%-10s$(RESET) %s\n" "[$(TAG)]"
SUBMAKE		=	$(MAKE) -s --no-print-directory -C

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

SRC_DIR		=	src
OBJ_DIR		=	obj
INC_DIR		=	include

INCLUDES	=	-I$(INC_DIR)

SRC_FILES	=	ft_printf.c \
				ft_parse_format.c \
				ft_parse_spec.c \
				ft_print_char.c \
				ft_print_str.c \
				ft_print_ptr.c \
				ft_print_per.c \
				ft_print_nbr.c \
				ft_print_usg.c \
				ft_print_hex.c \
				ft_print_utils.c \
				ft_pf_libc.c

OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/ft_printf.h | $(OBJ_DIR)
	@$(LOG) "$(C_BUILD)" compiling "$<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@$(LOG) "$(C_DONE)" archived "$(NAME)"

bonus: all

clean:
	@rm -rf $(OBJ_DIR)
	@$(LOG) "$(C_CLEAN)" cleaned objects

fclean: clean
	@rm -f $(NAME)
	@$(LOG) "$(C_RM)" removed "$(NAME)"

re: fclean all

.PHONY: all bonus clean fclean re

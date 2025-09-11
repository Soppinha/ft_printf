NAME		=	libftprintf.a
LIBFT_DIR	=	libft
LIBFT		=	$(LIBFT_DIR)/libft.a

SRCS		=	ft_printf.c \
				ft_parser.c \
				ft_print_char.c \
				ft_print_str.c \
				ft_print_nbr.c \
				ft_print_unsigned.c \
				ft_print_hex.c \
				ft_print_ptr.c

OBJS		=	$(SRCS:.c=.o)

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re

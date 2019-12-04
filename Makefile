
SRCS	= ft_printf.c\
		  ft_printf_conversions.c\
		  ft_printf_conversions2.c\
		  ft_printf_format.c\
		  ft_printf_utils.c

OBJS	= $(SRCS:.c=.o)

HEADER	= ft_printf.h

NAME	= libftprintf.a

LIBFT	= libft/

LIBNAME = libft.a

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra -I $(HEADER)

RM		= rm -f

%.o: 		%.c $(HEADER)
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C $(LIBFT)
			mv $(LIBFT)$(LIBNAME) .
			ar rc $(LIBNAME) $(OBJS)
			mv $(LIBNAME) $(NAME)
			ranlib $(NAME)

clean:
			$(RM) $(OBJS)
			cd $(LIBFT) && make clean

fclean: 	clean
			$(RM) $(NAME)
			cd $(LIBFT) && make fclean

re: 		fclean all

.PHONY: 	all clean fclean re

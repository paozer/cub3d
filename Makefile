# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/12/04 14:03:03 by pramella     #+#   ##    ##    #+#        #
#    Updated: 2019/12/04 14:03:03 by pramella    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

SRCS	=

OBJS	= $(SRCS:.c=.o)

HEADER	=

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

clean:
			$(RM) $(OBJS)
			cd $(LIBFT) && make clean

fclean: 	clean
			$(RM) $(NAME)
			cd $(LIBFT) && make fclean

re: 		fclean all

.PHONY: 	all clean fclean re

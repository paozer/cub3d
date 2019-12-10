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

HEADERS	= $(LIBFT)includes/libft.h\
		  $(SRCS_D)cub3d.h\
		  $(SRCS_D)/parsing/parsing.h\

SRCS_D	= srcs/

SRCS	= $(SRCS_D)parsing/parsing_check.c\
		  $(SRCS_D)parsing/parsing_init.c\
		  $(SRCS_D)parsing/parsing_main.c\
		  $(SRCS_D)parsing/parsing_map.c\
		  $(SRCS_D)cub3d.c\

OBJS	= $(SRCS:.c=.o)

LIBFT	= libft/

LIBNAME = libft.a

NAME	= cub3d

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

RM		= rm -f

%.o: 		%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C $(LIBFT)
			mv $(LIBFT)$(LIBNAME) .
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBNAME)

clean:
			$(RM) $(OBJS)
			cd $(LIBFT) && make clean

fclean: 	clean
			$(RM) $(NAME)
			$(RM) $(LIBNAME)

re: 		fclean all

.PHONY: 	all clean fclean re

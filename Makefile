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

HEADER	= $(LIBFT)includes/libft.h\
		  $(SRCS_D)cub3d.h\

SRCS	= $(SRCS_D)cub3d.c\
		  $(SRCS_D)init.c\
		  $(SRCS_D)/utils/utils.c\
		  $(SRCS_D)/utils/free.c\
		  $(SRCS_D)/utils/bmp.c\
		  $(SRCS_D)raycasting/raycasting.c\
		  $(SRCS_D)raycasting/draw.c\
		  $(SRCS_D)raycasting/movement.c\
		  $(SRCS_D)raycasting/movement2.c\
		  $(SRCS_D)raycasting/sprites.c\
		  $(SRCS_D)parsing/check.c\
		  $(SRCS_D)parsing/parsing.c\
		  $(SRCS_D)parsing/map.c\

OBJS	= $(SRCS:.c=.o)

SRCS_D	= srcs/

LIBFT	= libft/

LIBNAME = libft.a

LIBMLX	= mlx/

NAME	= cub3D

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra -I srcs

MLXFLAGS = -I $(LIBMLX) -g -L $(LIBMLX) -l mlx -framework OpenGL -framework AppKit

RM		= rm -f

%.o: 		%.c $(HEADER)
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C $(LIBFT)
			make -C $(LIBMLX)
			$(CC) $(CFLAGS) -g3 -fsanitize=address $(MLXFLAGS) -o $(NAME) $(OBJS) $(LIBFT)$(LIBNAME)

clean:
			$(RM) $(OBJS)
			cd $(LIBFT) && make clean
			cd $(LIBMLX) && make clean

fclean: 	clean
			$(RM) $(NAME)
			$(RM) $(LIBFT)$(LIBNAME)

re: 		fclean all

.PHONY: 	all clean fclean re

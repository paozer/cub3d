# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: pramella <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/13 19:22:26 by pramella     #+#   ##    ##    #+#        #
#    Updated: 2019/10/23 16:38:42 by pramella    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

SRCS	= ft_atoi.c\
		  ft_bzero.c\
		  ft_calloc.c\
		  ft_isalnum.c\
		  ft_isalpha.c\
		  ft_isascii.c\
		  ft_isdigit.c\
		  ft_isprint.c\
		  ft_itoa.c\
		  ft_lstadd_back.c\
  		  ft_lstadd_front.c\
  		  ft_lstclear.c\
   		  ft_lstdelone.c\
   		  ft_lstiter.c\
   		  ft_lstlast.c\
   		  ft_lstmap.c\
  		  ft_lstnew.c\
  		  ft_lstsize.c\
		  ft_memccpy.c\
		  ft_memchr.c\
		  ft_memcmp.c\
		  ft_memcpy.c\
		  ft_memmove.c\
		  ft_memset.c\
		  ft_putchar_fd.c\
		  ft_putendl_fd.c\
		  ft_putnbr_fd.c\
		  ft_putstr_fd.c\
		  ft_split.c\
		  ft_strchr.c\
		  ft_strdup.c\
		  ft_strjoin.c\
		  ft_strlcat.c\
		  ft_strlcpy.c\
		  ft_strlen.c\
		  ft_strmapi.c\
		  ft_strncmp.c\
		  ft_strnstr.c\
		  ft_strrchr.c\
		  ft_strtrim.c\
		  ft_substr.c\
		  ft_tolower.c\
		  ft_toupper.c

OBJS	= $(SRCS:.c=.o)

HEADER	= libft.h

NAME	= libft.a

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra -I $(HEADER)

RM		= rm -f

%.o: 		%.c $(HEADER)
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)

clean:
			$(RM) $(OBJS) $(B_OBJS)

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re

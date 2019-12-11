# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/07 15:11:52 by dgascon      #+#   ##    ##    #+#        #
#    Updated: 2019/12/10 19:37:23 by dgascon     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY:	all clean fclean re

NAME		=	libft

PATH_INC	=	includes
PATH_SRC	=	srcs
PATH_OBJ	=	objs

SRC_LIST	= 	string/ft_strlen.c		string/ft_toupper.c			\
				string/ft_tolower.c		string/ft_atoi.c			\
				string/ft_isascii.c		string/ft_isprint.c			\
				string/ft_isalpha.c		string/ft_isdigit.c			\
				string/ft_isalnum.c		string/ft_strchr.c			\
				string/ft_strrchr.c		string/ft_strncmp.c			\
				string/ft_strlcpy.c		string/ft_strlcat.c			\
				string/ft_strnstr.c		string/ft_strdup.c			\
				string/ft_substr.c		string/ft_strjoin.c			\
				string/ft_strtrim.c		string/ft_split.c			\
				string/ft_itoa.c		string/ft_strmapi.c			\
				string/ft_strcat.c		string/ft_strichr.c			\
				string/ft_chartostr.c								\
				mem/ft_memset.c			mem/ft_bzero.c				\
				mem/ft_memcpy.c			mem/ft_memccpy.c			\
				mem/ft_memmove.c		mem/ft_memchr.c				\
				mem/ft_memcmp.c			mem/ft_calloc.c				\
				put/ft_putchar_fd.c		put/ft_putstr_fd.c			\
				put/ft_putendl_fd.c		put/ft_putnbr_fd.c			\
				put/ft_putnbr_base_fd.c	put/ft_putnstr_fd.c			\
				lists/ft_lstnew.c		lists/ft_lstadd_front.c		\
				lists/ft_lstsize.c		lists/ft_lstlast.c			\
				lists/ft_lstadd_back.c	lists/ft_lstdelone.c		\
				lists/ft_lstclear.c		lists/ft_lstiter.c			\
				lists/ft_lstmap.c									\
				gnl/get_next_line.c		gnl/get_next_line_utils.c	\
				maths/ft_power.c		maths/ft_sqrt.c				\
				numbers/ft_digit.c		numbers/ft_digit_base.c		\
				numbers/ft_itoa_base.c

INCS_LIST	=	libft.h

OBJS		=	$(addprefix $(PATH_OBJ)/, $(SRC_LIST:.c=.o))
INCS		=	$(addprefix $(PATH_INC)/, $(INCS_LIST))

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -I.

C-O			=	$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

$(NAME): $(OBJS) $(INCS)
	@ ar rc $(NAME).a $(OBJS)

$(PATH_OBJ)/%.o: $(PATH_SRC)/%.c $(INCS)
	@ $(shell mkdir -p $(PATH_OBJ) $(PATH_OBJ)/mem $(PATH_OBJ)/put)
	@ $(shell mkdir -p $(PATH_OBJ)/lists $(PATH_OBJ)/string)
	@ $(shell mkdir -p $(PATH_OBJ)/gnl $(PATH_OBJ)/maths $(PATH_OBJ)/numbers)
	@ $(C-O)
	@ echo "\033[32m V \033[1m$<\033[0;32m\t| \033[1m$@ create !\033[0m"
	@ echo " \033[36m--CMD-- \033[32m$(C-O) create !\033[0m"

clean:
	@ /bin/rm -rf $(PATH_OBJ)

fclean: clean
	@ /bin/rm -f $(NAME).out $(NAME).a
	@ echo "\033[31m > \033[1m$(NAME)/$(PATH_OBJ)/*\033[0;31m delete.\033[0m"
	@ echo "\033[31m > \033[1m$(NAME)/$(NAME).a\033[0;31m delete.\033[0m"

re: fclean all

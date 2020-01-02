# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/07 15:11:52 by dgascon      #+#   ##    ##    #+#        #
#    Updated: 2020/01/02 23:01:57 by dgascon     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY:	all clean fclean re

NAME			=	libftprintf.a

PATH_INC		=	includes

PF_PATH_SRC		=	srcs
PF_PATH_OBJ		=	objs
SRC_LIST		= 	ft_printf.c				pf_conv.c					\
					lists/pf_initlst.c									\
					display/pf_disp.c		display/pf_disp_int.c 		\
					display/pf_disp_char.c	display/pf_disp_string.c	\
					display/pf_disp_ptr.c	display/pf_disp_perc.c		\
					pf_utils.c

INCS_LIST		=	ft_printf.h

PF_OBJS			=	$(addprefix $(PF_PATH_OBJ)/, $(SRC_LIST:.c=.o))
PF_OBJS_BONUS	=	$(addprefix $(PF_PATH_OBJ)/, $(BONUS_LIST:.c=.o))
PF_INCS			=	$(addprefix $(PATH_INC)/, $(INCS_LIST))

LIBFT_PATH		=	libft
LIBFT_NAME		=	libft.a
LIBFT_FLAG 		=	-Llibft -lft
LIBFT_LIB 		= 	$(FLAG_FT)
LIBFT_INC		=	$(addprefix $(LIBFT_PATH)/, $(PATH_INC))
LIBFT			=	$(addprefix $(LIBFT_PATH)/, $(LIBFT_NAME))

CC				=	gcc
INCLUDES		=	-I$(LIBFT_INC) -I$(PATH_INC)
CFLAGS			=	-Wall -Wextra -Werror
C-O				=	$(CC) $(CFLAGS) $(LIBFT_LIB) $(INCLUDES) -c $< -o $@

all:	$(LIBFT_NAME) $(NAME)

$(NAME): $(PF_OBJS) 
	@ ar rcsu $(NAME) $(LIBFT_PATH)/objs/*/*.o $(PF_OBJS)

$(PF_PATH_OBJ)/%.o: $(PF_PATH_SRC)/%.c $(PF_INCS)
	@ $(shell mkdir -p $(PF_PATH_OBJ) $(PF_PATH_OBJ)/lists $(PF_PATH_OBJ)/display)
	@ $(C-O)
	@ echo "\033[32m V \033[1m$<\033[0;32m\t| \033[1m$@ create !\033[0m"
	@ echo " \033[36m--CMD-- \033[32m$(C-O) create !\033[0m"

$(LIBFT_NAME):
	@ make -C $(LIBFT_PATH)
	@ echo "\033[33;1m-- -- -- Compilation de la libft réussis. -- -- --\033[0m"

bonus: all

clean:
	@ /bin/rm -rf $(PF_PATH_OBJ)
	@ make -C $(LIBFT_PATH) clean

fclean: clean
	@ /bin/rm -rf $(NAME) ./a.out*
	@ echo "\033[31m > \033[1m$(NAME)/$(PF_PATH_OBJ)/*\033[0;31m delete.\033[0m"
	@ echo "\033[31m > \033[1m$(NAME)/$(NAME).a\033[0;31m delete.\033[0m"
	@ make -C $(LIBFT_PATH) fclean
	@ echo "-----------------------------------------"

re: fclean all

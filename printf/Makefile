.PHONY: all clean fclean re

# Name of file
NAME		=	printf.a

# Name directory
PATH_INC	=	includes
PATH_SRC	=	srcs
PATH_OBJ	=	objs
PATH_LOG	=	logs
PATH_LIBFT	=	../libft

# List of sources
SRCS_DISP	=	$(addprefix display/, pf_disp.c pf_disp_char.c pf_disp_int.c pf_disp_perc.c pf_disp_ptr.c pf_disp_string.c)
SRCS_LISTS	=	$(addprefix lists/, pf_initlst.c)
SRCS_UTILS	=	$(addprefix utils/, ft_putnbr_format.c ft_putnbr_ui_base_fd.c ft_digit_format_base.c ft_digit_ul_base.c ft_putnstr_fd.c)
SRCS_CORE	=	$(addprefix core/, pf_conv.c pf_utils.c ft_printf.c)
SRCS		=	$(addprefix $(PATH_SRC)/, $(SRCS_DISP) $(SRCS_LISTS) $(SRCS_UTILS) $(SRCS_CORE))
OBJS		=	$(addprefix $(PATH_OBJ)/, $(notdir $(SRCS:.c=.o)))
INCS		=	$(wildcard $(PATH_INC)/*.h)
LOG			=	$(addprefix $(PATH_LOG)/, $(patsubst %.a.log,%.log,$(NAME).log))
LIBFT		=	-L$(PATH_LIBFT) -lft

# Commands of compilation
COMP		=	clang
COMP_FLAG	=	-Wall -Werror -Wextra
COMP_ADD	=	-I$(PATH_LIBFT)/$(PATH_INC) -I$(PATH_INC)

# Others Command
RM			=	/bin/rm

# Color Code and template code
_YELLOW		=	\e[38;5;184m
_GREEN		=	\e[38;5;46m
_RESET		=	\e[0m
_INFO		=	[$(_YELLOW)INFO$(_RESET)]
_SUCCESS	=	[$(_GREEN)SUCCESS$(_RESET)]

# Functions
all:	init $(NAME)
	@ echo "$(_SUCCESS) Compilation done"

init:
	@ $(shell mkdir -p $(PATH_OBJ) $(PATH_LOG))
	@ make -C $(PATH_LIBFT)

$(NAME): $(OBJS) $(INCS)
	@ (set -x; ar rcs $(NAME) $(OBJS)) >> $(LOG) 2>&1

$(PATH_OBJ)/%.o : $(PATH_SRC)/*/%.c $(INCS)
	@ (set -x; $(COMP) $(COMP_FLAG) $(COMP_ADD) -c $< -o $@) >> $(LOG) 2>&1

clean:
	@ $(RM) -rf $(PATH_OBJ)
	@ make -C $(PATH_LIBFT) clean

fclean: clean
	@ $(RM) -rf $(NAME)
	@ $(RM) -rf $(PATH_LOG)
	@ make -C $(PATH_LIBFT) fclean

re: fclean all
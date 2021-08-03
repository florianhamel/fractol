# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/25 20:20:38 by florianhame       #+#    #+#              #
#    Updated: 2021/08/03 15:43:06 by fhamel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#####                              FILES VARS                              #####
################################################################################

NAME		=	fractol

NAME_B		=	fractol_bonus

D_INCLUDES	=	includes/

D_OBJS		=	objs/

D_SRCS		=	srcs/

_SRC_		=	color.c \
				events_utils.c \
				events.c \
				fractol.c \
				image.c \
				julia.c \
				main.c \
				mandelbrot.c \
				operations.c \
				parsing.c \
				utils.c \

_SRC_B		=	burning_ship_bonus.c \
				color.c \
				events_bonus.c \
				events_utils.c \
				events.c \
				fractol.c \
				image.c \
				julia.c \
				main_bonus.c \
				mandelbrot.c \
				movement_bonus.c \
				operations.c \
				parsing.c \
				start_bonus.c \
				utils.c \

SRCS		=	$(addprefix $(D_SRCS), $(_SRC_))

OBJS		=	$(addprefix $(D_OBJS), $(_SRC_:.c=.o))

SRCS_B		=	$(addprefix $(D_SRCS), $(_SRC_B))

OBJS_B		=	$(addprefix $(D_OBJS), $(_SRC_B:.c=.o))

D_LIBFT		=	libft/

LIBFT		=	libft.a

D_MLX		=	minilibx-linux/

APPS		=	-L$(D_MLX) -lmlx -lXext -lX11 -lm -lbsd

################################################################################
#####                           COMPILER OPTIONS                           #####
################################################################################

CC			=	clang

FLAGS		=	-Wall -Wextra -Werror

FSANITIZE	=	-g -fsanitize=address

################################################################################
#####                            MAKEFILE RULES                            #####
################################################################################

all	: $(D_OBJS) $(LIBFT) $(NAME)

bonus : $(D_OBJS) $(LIBFT) $(NAME_B)

compiling_start_m :
	@python -c 'print u"\033[0;33m\u2192 " + "\033[0;33mCompiling \033[0;34m$(NAME)\033[0;33m sources..."'

compiling_end_m :
	@python -c 'print u"\033[0;32mCompiling successful \u2713 \033[0m"'

compiling_start_b :
	@python -c 'print u"\033[0;33m\u2192 " + "\033[0;33mCompiling \033[0;34m$(NAME)\033[0;33m bonus sources..."'

compiling_end_b :
	@python -c 'print u"\033[0;32mCompiling successful \u2713 \033[0m"'

$(D_OBJS) :
	@mkdir -p $@

$(LIBFT) :
	@make -C $(D_LIBFT)

$(D_OBJS)%.o : $(D_SRCS)%.c
	$(CC) $(FLAGS) -c $< -o $@ -Iincludes -Ilibft/includes/ -I$(D_MLX)

$(NAME) : compiling_start_m $(OBJS) compiling_end_m
	@python -c 'print u"\033[0;33m\u2192 " + "Linking objects for \033[0;34m$(NAME)\033[0;33m... \033[0m"'
	@$(CC) $(FSANITIZE) $(OBJS) -L$(D_LIBFT) -lft $(APPS) -o $(NAME)
	@python -c 'print u"\033[0;32mLinking successful \u2713 \033[0m"'

$(NAME_B) : compiling_start_b $(OBJS_B) compiling_end_b
	@python -c 'print u"\033[0;33m\u2192 " + "Linking objects for \033[0;34m$(NAME)\033[0;33m... \033[0m"'
	@$(CC) $(OBJS_B) -L$(D_LIBFT) -lft $(APPS) -o $(NAME)
	@python -c 'print u"\033[0;32mLinking successful \u2713 \033[0m"'

clean :
	@rm -rf $(D_OBJS)
	@make clean -C $(D_LIBFT)
	@python -c 'print u"\033[0;33mObjects deleted \u2713 \033[0m"'

fclean : clean
	@rm -rf $(D_LIBFT)$(LIBFT)
	@rm -rf $(NAME)
	@python -c 'print u"\033[0;34m$(LIBFT) \033[0;33mdeleted \u2713 \033[0m"'
	@python -c 'print u"\033[0;34m$(NAME) \033[0;33mdeleted \u2713 \033[0m"'

re : fclean all

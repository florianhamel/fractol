# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/21 19:44:59 by fhamel            #+#    #+#              #
#    Updated: 2021/07/19 16:56:30 by fhamel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#####                              FILES VARS                              #####
################################################################################

NAME		=	libft.a

D_INCLUDES	=	includes/

D_OBJS		=	objs/

D_SRCS		=	srcs/

_SRC_		=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
				ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c \
				ft_atoi.c ft_isalpha.c ft_is_ws.c ft_isdigit.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
				ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
				ft_strtrim.c ft_split.c ft_free_arr.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
				ft_putnbr_fd.c ft_malloc.c

SRCS		=	$(addprefix $(D_SRCS), $(_SRC_))

OBJS		=	$(addprefix $(D_OBJS), $(_SRC_:.c=.o))

################################################################################
#####                           COMPILER OPTIONS                           #####
################################################################################

CC			=	clang

FLAGS		=	-Wall -Wextra -Werror

AR			=	ar -rcs

################################################################################
#####                            MAKEFILE RULES                            #####
################################################################################

.PHONY : all bonus clean fclean re

all : $(D_OBJS) $(NAME)

compiling_start:
	@python -c 'print u"\033[0;33m\u2192 " + "\033[0;33mCompiling \033[0;34m$(NAME)\033[0;33m sources... \033[0m"'

compiling_end :
	@python -c 'print u"\033[0;32mCompiling successful \u2713 \033[0m"'

$(D_OBJS) :
	@mkdir -p $@

$(D_OBJS)%.o : $(D_SRCS)%.c
	@$(CC) $(FLAGS) -c $< -o $@ -Iincludes

$(NAME) : compiling_start $(OBJS) compiling_end
	@python -c 'print u"\033[0;33m\u2192 " + "\033[0;33mLinking objects for \033[0;34m$(NAME)\033[0;33m... \033[0m"'
	@$(AR) $(NAME) $(OBJS)
	@python -c 'print u"\033[0;32mLinking successful \u2713 \033[0m"'

clean :
	@rm -rf $(D_OBJS)
	@python -c 'print u"\033[0;33mObjects deleted \u2713 \033[0m"'

fclean : clean
	@rm -rf $(NAME)
	@python -c 'print u"\033[0;34m$(NAME) \033[0;33mdeleted \u2713 \033[0m"'

re : fclean all

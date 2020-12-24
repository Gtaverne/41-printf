# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/02 18:18:11 by user42            #+#    #+#              #
#    Updated: 2020/12/10 17:35:08 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
SRCS		= ft_printf.c ft_utils.c pf_cors.c pf_num.c pf_xtoa.c pf_hex.c \
				pf_ptr.c pf_char.c
OBJS		= ${SRCS:.c=.o}
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -Iincludes
LIB			= ar -rcs
RM			= rm -rf

all: ${NAME}

${NAME}: ${OBJS}
			${LIB} ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean: clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

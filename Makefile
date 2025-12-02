# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbarbe <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 15:33:53 by tbarbe            #+#    #+#              #
#    Updated: 2023/03/03 16:29:53 by tbarbe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	scop

SRCS	=	*.cpp

SRCS_ 	=	$(addprefix srcs/, $(SRCS))

GLAD	=	./glad/src/glad.c

INCLUDE	=	./include

CC		=	c++

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror -lm 

LIBS 	=	-lglfw -lGL -ldl -lpthread -lX11 -lm

all:		${NAME}			

${NAME}:
			${CC} ${GLAD} ${SRCS_} -o ${NAME} ${CFLAGS} ${LIBS} -I ${INCLUDE}

fclean: 	
			${RM} $(NAME)

re:			fclean all

.PHONY:		all fclean re

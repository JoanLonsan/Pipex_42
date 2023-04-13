# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcrescen <jcrescen@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 12:48:47 by jcrescen          #+#    #+#              #
#    Updated: 2023/04/05 13:27:47 by jcrescen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	pipex
BONUS		=	pipex_bonus

LIBFT		=	./libft/libft.a

SRCS		=	src/childs.c src/error.c src/free.c src/pipex.c
BONUS_SRCS	=	bonus/child_bonus.c bonus/error_bonus.c bonus/files_bonus.c \
				bonus/here_doc_bonus.c bonus/pipex_bonus.c bonus/free_bonus.c \

OBJS		=	${SRCS:.c=.o}
BONUS_OBJS	=	${BONUS_SRCS:.c=.o}

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -Iincludes

ECHO		=	echo
RM			=	rm -rf

DEF_COLOR	=	\033[0;39m
GREEN		=	\033[1;92m

all: ${NAME}
${NAME}: ${OBJS}
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}
	@$(ECHO) "Pipex: $(GREEN)Created ✔️$(DEF_COLOR)"

bonus: ${BONUS}
${BONUS}: ${BONUS_OBJS}
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${BONUS_OBJS} ./libft/libft.a -o ${BONUS}
	@$(ECHO) "Bonus: $(GREEN)Created ✔️$(DEF_COLOR)"


clean:
	@${MAKE} -C ./libft fclean
	@${RM} ${OBJS} ${BONUS_OBJS}
	@${ECHO} "Pipex: objc. files$(DEF_COLOR)$(GREEN) Cleaned ✔️$(DEF_COLOR)"

fclean: clean
	@${RM} ${NAME} ${BONUS}
	@$(ECHO) "Pipex: exec. files$(DEF_COLOR)$(GREEN) Cleaned ✔️$(DEF_COLOR)"

re:		fclean all

.PHONY:	all clean fclean bonus re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsedat <vsedat@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 15:08:55 by vsedat            #+#    #+#              #
#    Updated: 2022/02/07 10:06:43 by vsedat           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

##**********##
### COLORS ###
##**********##
BLACK		= \033[1;30m
RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
VIOLET		= \033[1;35m
CYAN		= \033[1;36m
WHITE		= \033[1;37m
IGREY		= \x1b[40m
IRED		= \x1b[41m
IGREEN		= \x1b[42m
IYELLOW		= \x1b[43m
IBLUE		= \x1b[44m
IPURPLE		= \x1b[45m
ICYAN		= \x1b[46m
IWHITE		= \x1b[47m
END			= \x1b[0m
UNDERLINE	= \x1b[4m
REV			= \x1b[7m

##********##
### NAME ###
##********##
NAME	= libftprintf.a

##***************##
### COMPILATION ###
##**************###
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rc

##*******************##
### DIRECTORY PATHS ###
##*******************##
HEADER		= ./incl/ft_printf.h
MLX			= ./mlx
OBJ_PATH	= ./objs
SRC_PATH	= ./srcs

##***********##
### OBJECTS ###
##***********##
SRCS = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS = $(addprefix $(OBJ_PATH)/,$(SOURCES:%.c=%.o))

##****************##
### SOURCE FILES ###
##****************##
SOURCES	=	ft_printf.c	\
			ft_printfutils.c	\
			ft_printfutils2.c	\
			ft_printhex.c		\
			ft_printptr.c		\
			ft_printunsigned.c		\

##*********##
### RULES ###
##*********##
all: 	${NAME}

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER) Makefile
			@echo "$(BLUE)$(UNDERLINE)Compiling:$(END)$(CYAN) $<"
			@${CC} ${CFLAGS} -c $< -o $@

		
${NAME}:	${OBJS}
			@$(AR) $(NAME) $(OBJS)
			@echo "$(GREEN)Successful compilation"
		
clean:
		@rm -f ${OBJS}
		@echo "$(BLUE)Object files cleaned$(DEF_COLOR)"

fclean:	clean
		@rm -f ${NAME}
		@echo "$(CYAN)Executable files cleaned"

re:	fclean
	@${MAKE} all
	@echo "$(VIOLET)Cleaned and rebuilt everything"

.PHONY:	all clean fclean re

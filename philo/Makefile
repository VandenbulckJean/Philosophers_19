# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/25 11:52:43 by jvanden-          #+#    #+#              #
#    Updated: 2021/09/28 09:41:58 by jvanden-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
INCL		=	./includes/

CFLAGS		=	-I $(INCL) $(FLAGS)

NAME		=	philo

### PATH ###

SRCS_PATH			=	srcs/

SRCS_PHILOSOPHERS	=	philosophers.c \
						parsing.c \
						get_arguments.c \
						initialisation.c \
						life.c \
						terminate.c
				
SRCS_UTILS			=	ft_atoi.c \
						exit.c \
						ft_strlen.c \
						ft_strcmp.c \
						check_int.c \
						ft_isdigit.c \
						get_time.c \
						ft_usleep.c \
						log_writer.c

SRCS_PHILOSOPHERS2	=	$(addprefix $(SRCS_PATH), $(SRCS_PHILOSOPHERS)) \
						$(addprefix $(SRCS_PATH)utils/, $(SRCS_UTILS))

OBJ_PHILOSOPHERS	=	$(SRCS_PHILOSOPHERS2:.c=.o)

######### RULES #######

all : $(NAME)

$(NAME) : $(OBJ_PHILOSOPHERS)
	@$(CC) -o $(NAME) $(OBJ_PHILOSOPHERS) $(CFLAGS)

clean:
	@/bin/rm -rf $(OBJ_PHILOSOPHERS)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all
	
.PHONY: all re clean fclean 
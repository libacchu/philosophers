# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: libacchu <libacchu@students.42wolfsburg.de +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/02 15:36:46 by libacchu          #+#    #+#              #
#    Updated: 2022/09/08 20:15:58 by libacchu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	philo

CC		= 	gcc
CFLAGS	= 	-Wall -Wextra -Wextra -pthread -g

SRC_DIR	= 	./src
SRC		= 	$(SRC_DIR)/main.c \
			$(SRC_DIR)/input_handler.c \
			$(SRC_DIR)/init_struct.c \
			$(SRC_DIR)/get_time.c \
			$(SRC_DIR)/sleep.c \
			$(SRC_DIR)/utils.c \
			$(SRC_DIR)/print_msg.c \
			$(SRC_DIR)/threads.c \
			$(SRC_DIR)/background_pthread.c \
			$(SRC_DIR)/routine.c \
			$(SRC_DIR)/eat.c \
			$(SRC_DIR)/think.c \

OBJ		= 	$(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re

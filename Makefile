# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/02 15:36:46 by libacchu          #+#    #+#              #
#    Updated: 2022/09/03 19:22:30 by libacchu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	philo

CC		= 	gcc
CFLAGS	= 	-Wall -Wextra -Wextra -pthread -g

SRC_DIR	= 	./src
SRC		= 	$(SRC_DIR)/main.c \
			$(SRC_DIR)/utils.c \
			$(SRC_DIR)/get_time.c \
			$(SRC_DIR)/sleep.c \

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

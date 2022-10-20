# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: libacchu <libacchu@students.42wolfsburg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/02 15:36:46 by libacchu          #+#    #+#              #
#    Updated: 2022/10/20 15:27:34 by libacchu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	philo

CC		= 	gcc
# CFLAGS	= 	-Wall -Wextra -Wextra -pthread -g -fsanitize=thread
CFLAGS	= 	-Wall -Wextra -Wextra -pthread -O3

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
			$(SRC_DIR)/free.c \
			$(SRC_DIR)/checker.c \

OBJ_DIR	= 	./obj
OBJ = 		$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
		rm -rf $(OBJ_DIR); \
		echo "rm -rf $(OBJ_DIR)"; \
	fi

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

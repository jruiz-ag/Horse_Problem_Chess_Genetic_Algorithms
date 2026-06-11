# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jruiz-ag <confidentjaime@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/11 14:11:58 by jruiz-ag          #+#    #+#              #
#    Updated: 2026/06/11 14:11:58 by jruiz-ag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= horse_problem
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRC		= main.c individuals.c aux_individuals.c algorithm.c
OBJ_DIR = obj
OBJECTS	= $(SRC:%.c=$(OBJ_DIR)/%.o)
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a


# All needs to be always the first rule
all: $(NAME)

# Executable compilation
$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

# First compilation of my own library
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Object compilation in a hide directory
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Cleaning objects
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

# Full clean
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

# Recompile all from the beggining
re: fclean all

.PHONY: all clean fclean re
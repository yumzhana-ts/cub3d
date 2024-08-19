# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/05 18:06:28 by ytsyrend          #+#    #+#              #
#    Updated: 2024/08/19 17:38:48 by ytsyrend         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project Name
NAME		:= cub3d

# Compiler
CC			:= gcc
CFLAGS 		:= -Wall -Wextra -Werror -Iheaders/

# Directories
MINILIBX	:= mlx/
SRC_DIR		:= src/
MAP_DIR		:= src/map/
GRAPH_DIR	:= src/graphics/
UTIL_DIR	:= src/utils/
GNL_DIR		:= get_next_line/
PRINTF_DIR	:= ft_printf/
LIBFT_DIR	:= 01_libft
OBJS_DIR	:= objs/

# Source and Object Files
COMMON_SRCS	:= $(SRC_DIR)*.c $(GRAPH_DIR)*.c $(MAP_DIR)*.c $(UTIL_DIR)*.c $(GNL_DIR)*.c
SRCS 		:= $(COMMON_SRCS)
OBJS 		:= $(SRCS:%.c=$(OBJS_DIR)/%.o)

# Libraries and Frameworks
LIBRARY		:= -Lmlx -lmlx -framework OpenGL -framework AppKit
PRINTF_LIB	:= $(PRINTF_DIR)libftprintf.a

# Valgrind Command
VALGRIND	:= @valgrind --leak-check=full --show-leak-kinds=all \
			   --track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

# Phony Targets
.PHONY: all clean fclean re

# Default Target
all: $(OBJS_DIR) $(NAME)

# Define a target to run the Python script
proto:
	@echo "Updating prototypes..."
	python3 head.py $(SRC_DIR)
	
dox:
	@echo "Running Doxygen..."
	doxygen Doxyfile

# Compile and Link the Project
$(NAME): $(OBJS)
	make -C $(MINILIBX)
	make -C $(PRINTF_DIR)
	make -C $(LIBFT_DIR)
	@echo "Running Doxygen..."
	doxygen Doxyfile
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT_DIR)/libft.a $(PRINTF_LIB) $(LIBRARY) -o $(NAME)
	@echo "main: Compilation successful."

# Compile Source Files into Object Files
$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Create the Object File Directory
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

# Clean Object Files
clean:
	rm -rf $(OBJS_DIR)
	@echo "Object files removed."

# Clean Everything (including executable)
fclean: clean
	make clean -C $(MINILIBX)
	make fclean -C $(PRINTF_DIR)
	make fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)
	@echo "Executable removed."

# Rebuild Everything
re: fclean all
	@echo "Rebuilt everything."

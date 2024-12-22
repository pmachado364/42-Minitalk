# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/05 13:13:10 by pmachado          #+#    #+#              #
#    Updated: 2024/06/05 13:13:10 by pmachado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME        = libftprintf.a
INCLUDE     = include
LIBFT       = Libft
SRC_DIR     = src/
OBJ_DIR     = obj/
CC          = gcc
CFLAGS      = -Wall -Werror -Wextra -I$(INCLUDE) -I$(LIBFT)
RM          = rm -f
AR          = ar rcs

# Sources
SRC_FILES   = ft_printf ft_printf_utils ft_printf_utils2

SRC         = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ         = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

# Ensure object directory exists
OBJF        = .cache_exists

all:        $(NAME)

$(NAME):    $(OBJ)
	@make -C $(LIBFT)
	@cp $(LIBFT)/libft.a .
	@mv libft.a $(NAME)
	@$(AR) $(NAME) $(OBJ)
# @echo "ft_printf compiled!"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
#	@echo "Compiling: $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) -rf $(OBJ_DIR)
	@make clean -C $(LIBFT)
#	@echo "ft_printf object files cleaned!"

fclean:     clean
	@$(RM) -f $(NAME)
	@$(RM) -f $(LIBFT)/libft.a
#	@echo "ft_printf executable files cleaned!"
#	@echo "libft executable files cleaned!"

re:         @fclean all
#	@echo "Cleaned and rebuilt everything for ft_printf!"

# Test target to compile and run main.c
test:       $(NAME)
	@$(CC) $(CFLAGS) -o test_main src/main.c -L. -lftprintf
	@./test_main

.PHONY:     all clean fclean re test

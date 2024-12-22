# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
INC_DIR = include
LIB_DIR = lib/Ft_printf
SRC_DIR = src
OBJ_DIR = obj

# Library
LIBFTPRINTF = $(LIB_DIR)/libftprintf.a

# Source files
SRC_SERVER = $(SRC_DIR)/server.c
SRC_CLIENT = $(SRC_DIR)/client.c
SRC_SERVER_BONUS = $(SRC_DIR)/server_bonus.c
SRC_CLIENT_BONUS = $(SRC_DIR)/client_bonus.c

# Object files
OBJ_SERVER = $(OBJ_DIR)/server.o
OBJ_CLIENT = $(OBJ_DIR)/client.o
OBJ_SERVER_BONUS = $(OBJ_DIR)/server_bonus.o
OBJ_CLIENT_BONUS = $(OBJ_DIR)/client_bonus.o

# Executable names
SERVER_EXEC = server
CLIENT_EXEC = client
SERVER_EXEC_BONUS = server_bonus
CLIENT_EXEC_BONUS = client_bonus

# Include paths
INCLUDES = -I$(INC_DIR)

# Color codes
YELLOW = \033[1;33m
RED = \033[1;31m
RESET = \033[0m

# Rules
all: $(LIBFTPRINTF) $(SERVER_EXEC) $(CLIENT_EXEC)
	@echo "$(YELLOW)Server and Client compiled successfully.$(RESET)"

bonus: $(LIBFTPRINTF) $(SERVER_EXEC_BONUS) $(CLIENT_EXEC_BONUS)
	@echo "$(YELLOW)Bonus: Server and Client compiled successfully.$(RESET)"

# Ensure the obj directory exists before compiling object files
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Compile the library in lib/Ft_printf
$(LIBFTPRINTF):
	@$(MAKE) --no-print-directory -C $(LIB_DIR) --silent

$(SERVER_EXEC): $(OBJ_SERVER)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBFTPRINTF)

$(CLIENT_EXEC): $(OBJ_CLIENT)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBFTPRINTF)

$(SERVER_EXEC_BONUS): $(OBJ_SERVER_BONUS)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBFTPRINTF)

$(CLIENT_EXEC_BONUS): $(OBJ_CLIENT_BONUS)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBFTPRINTF)

$(OBJ_DIR)/server.o: $(SRC_SERVER) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(OBJ_DIR)/client.o: $(SRC_CLIENT) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(OBJ_DIR)/server_bonus.o: $(SRC_SERVER_BONUS) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(OBJ_DIR)/client_bonus.o: $(SRC_CLIENT_BONUS) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) --no-print-directory -C $(LIB_DIR) clean

fclean: clean
	@rm -f $(SERVER_EXEC) $(CLIENT_EXEC) $(SERVER_EXEC_BONUS) $(CLIENT_EXEC_BONUS)
	@$(MAKE) --no-print-directory -C $(LIB_DIR) fclean
	@echo "$(RED)Server, Client, Bonus Server, Bonus Client, and Objects deleted.$(RESET)"

re: fclean all

rebonus: fclean bonus

# Phony targets
.PHONY: all clean fclean re bonus rebonus $(LIBFTPRINTF)

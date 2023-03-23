# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fra <fra@student.42.fr>                      +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/30 15:27:27 by faru          #+#    #+#                  #
#    Updated: 2023/03/23 03:41:22 by fra           ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SHELL := /bin/bash

MAIN := push_swap
BONUS := checker
SRC_DIR := sources
OBJ_DIR := objects
LIBFT_DIR := libft
MAIN_OBJ := $(OBJ_DIR)/$(MAIN).o
BONUS_OBJ := $(OBJ_DIR)/$(BONUS).o
LIBFT := $(LIBFT_DIR)/libft.a
HEADERS := $(shell find include -type f -name '*.h')
SOURCES = $(shell find $(SRC_DIR) -type f -name '*.c')
OBJECTS := $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SOURCES:.c=.o))	

CC  := gcc
IFLAGS := -Iinclude -I$(LIBFT_DIR)/include
CFLAGS := -Wall -Wextra -Werror -g3 -fsanitize=address
LFLAGS := -Llibft -lft

GREEN = \x1b[32;01m
RED = \x1b[31;01m
BLUE = \x1b[34;01m
RESET = \x1b[0m
YELLOW = \x1b[33;01m

all: $(LIBFT) $(MAIN)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --quiet

$(MAIN): $(LIBFT) $(OBJ_DIR) $(OBJECTS)
	@$(CC) $(CFLAGS) $(IFLAGS) $(subst $(BONUS_OBJ),,$(OBJECTS)) $(LFLAGS) -o $(MAIN)
	@printf "(push_swap) $(GREEN)Created executable $(MAIN)$(RESET)\n"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@printf "(push_swap) $(BLUE)Created object $$(basename $@)$(RESET)\n"

bonus: $(LIBFT) $(OBJ_DIR) $(OBJECTS)
	@$(CC) $(CFLAGS) $(IFLAGS) $(subst $(MAIN_OBJ),,$(OBJECTS)) $(LFLAGS) -o $(BONUS)
	@printf "(push_swap) $(GREEN)Created executable $(BONUS)$(RESET)\n"

clean:
	@$(MAKE) clean -C $(LIBFT_DIR) --quiet
	@for file in $(OBJECTS); do \
		rm -f $$file;	\
		printf "(push_swap) $(RED)Removed object $$(basename $$file)$(RESET)\n"; \
	done

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR) --quiet
	@-rm -f $(MAIN) $(BONUS)
	@printf "(push_swap) $(RED)Removed executable(s)$(RESET)\n"

re: fclean all

.PHONY: all, clean, fclean, re


















# NAME := push_swap
# NAME_BONUS := checker
# SRC_DIR := sources/
# OBJ_DIR := objects/
# TLS_DIR := tools/
# INCLUDE := include/
# MAIN_SRC := $(SRC_DIR)$(NAME).c
# MAIN_OBJ := $(OBJ_DIR)$(NAME).o
# MAIN_SRC_BNS := $(SRC_DIR)$(NAME_BONUS).c
# MAIN_OBJ_BNS := $(OBJ_DIR)$(NAME_BONUS).o

# TLS := $(TLS_DIR)basic_moves.c \
# 	   $(TLS_DIR)bonus.c \
# 	   $(TLS_DIR)checks.c \
# 	   $(TLS_DIR)count_moves.c \
# 	   $(TLS_DIR)finder.c \
# 	   $(TLS_DIR)sort.c \
# 	   $(TLS_DIR)stack.c \
# 	   $(TLS_DIR)turk.c
	   
# OBJS := $(subst $(TLS_DIR), $(OBJ_DIR), $(TLS:.c=.o))

# LIB_PS := libps.a
# LIB_LIBFT := libft.a
# LIBS := $(LIB_PS) libft/$(LIB_LIBFT)

# CC  := gcc
# WFLAGS  := -Wall -Wextra -Werror #-g -fsanitize=address
# IFLAGS := -I$(INCLUDE) -Ilibft/$(INCLUDE)

# GREEN = \x1b[32;01m
# RED = \x1b[31;01m
# BLUE = \x1b[34;01m
# RESET = \x1b[0m
# YELLOW = \x1b[33;01m

# all: $(NAME)

# $(NAME): $(LIB_LIBFT) $(LIB_PS) $(MAIN_SRC)
# 	@$(CC) $(WFLAGS) $(IFLAGS) -c $(MAIN_SRC) -o $(MAIN_OBJ)
# 	@printf "$(BLUE)Created object $(subst $(OBJ_DIR),,$(MAIN_OBJ))$(RESET)\n"
# 	@$(CC) $(WFLAGS) $(IFLAGS) $(MAIN_OBJ) $(LIBS) -o $(NAME)
# 	@printf "$(GREEN)Created executable $(NAME)$(RESET)\n"

# $(LIB_PS): $(OBJ_DIR) $(OBJS)
# 	@ar -rcs $(LIB_PS) $(OBJS) && printf "$(YELLOW)Created archive $(LIB_PS)$(RESET)\n"

# $(LIB_LIBFT):
# 	@cd libft && $(MAKE) --no-print-directory

# $(OBJ_DIR):
# 	@mkdir $(OBJ_DIR)

# $(OBJ_DIR)%.o: $(TLS_DIR)%.c
# 	@$(CC) $(WFLAGS) $(IFLAGS) -c $^ -o $@
# 	@printf "$(BLUE)Created object file $@$(RESET)\n"


# bonus: $(LIB_LIBFT) $(LIB_PS) $(MAIN_SRC_BNS)
# 	@$(CC) $(WFLAGS) $(IFLAGS) -c $(MAIN_SRC_BNS) -o $(MAIN_OBJ_BNS)
# 	@printf "$(BLUE)Created object $(subst $(OBJ_DIR),,$(MAIN_OBJ_BNS))$(RESET)\n"
# 	@$(CC) $(WFLAGS) $(IFLAGS) $(MAIN_OBJ_BNS) $(LIBS) -o $(NAME_BONUS)
# 	@printf "$(GREEN)Created executable $(NAME_BONUS)$(RESET)\n"

# clean:
# 	@-rm -f $(OBJS) $(MAIN_OBJ) $(MAIN_OBJ_BNS)
# 	@printf "$(RED)Removing files $(OBJS) $(MAIN_OBJ)$(RESET)\n"
# 	@cd libft && $(MAKE) clean --no-print-directory

# fclean: clean
# 	@-rm -f $(NAME) $(NAME_BONUS) $(LIB_PS)
# 	@printf "$(RED)Removing $(NAME_EXE) and $(LIB_PS)$(RESET)\n"
# 	@cd libft && $(MAKE) fclean --no-print-directory

# re: fclean all

# .PHONY: all clean fclean re
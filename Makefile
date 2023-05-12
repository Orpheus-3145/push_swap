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

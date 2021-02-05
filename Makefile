# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: viclucas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/26 00:24:15 by viclucas          #+#    #+#              #
#    Updated: 2019/09/26 21:17:46 by vimarkov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : clean all fclean re malloc

NAME = libft_malloc_$(HOSTTYPE).so

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

CC = gcc
FLAGS = -I$(INC_PATH)

SRC_PATH = ./src/
SRCS = $(addprefix $(SRC_PATH), $(SRC))
SRC = malloc.c \
	  check_zone.c \
      alloc_block.c \
	  show_alloc_mem.c \
	  free.c \
	  realloc.c \
	  sup_fonctions.c \
	  sup_fonctions2.c \

OBJ_PATH = ./obj/
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))
OBJ = $(SRC:.c=.o)

INC_PATH = ./includes/
INCS = $(addprefix $(INC_PATH), $(INC))
INC = malloc.h \

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJS)
	make -C libft/
	gcc -o $(NAME) -L libft/ -lft -shared $(OBJS)
	$(shell ln -sf  libft_malloc_$(HOSTTYPE).so libft_malloc.so)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INCS)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

malloc:
	make -C libft
	gcc -I ./includes/ $(SRCS) $(INCS) -L libft/ -lft -Wall -Wextra -Werror -fsanitize=address

malloc_clean:
	make -C libft/ clean
	rm a.out

clean:
	make -C libft/ clean
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_PATH)

fclean: clean
	make -C libft/ fclean
	rm -rf libft_malloc.so
	rm -rf $(NAME)

re: fclean all

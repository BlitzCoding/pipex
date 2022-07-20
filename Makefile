# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonghlee <yonghlee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 15:22:06 by yonghlee          #+#    #+#              #
#    Updated: 2022/07/20 15:53:08 by yonghlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAG		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -rf

OBJ_MKDIR	= create_dir
OBJ_DIR		= objs/
SRC_DIR		=

NAME		= pipex
LIBFT		= libft

SRC			= main			\
				pipex_util	\

SRCS		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC)))
OBJS		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC)))

all : $(NAME)

$(OBJ_MKDIR):
	mkdir -p $(OBJ_DIR)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)
	mv libft/libft.a ./$(OBJ_DIR)
	$(CC) $(CFLAG) $^ $(OBJ_DIR)libft.a -o $@ -fsanitize=address

$(OBJ_DIR)%.o : %.c | $(OBJ_MKDIR)
	$(CC) $(CFLAGS) -c $^ -I./ -o $@

clean:
	make fclean -C $(LIBFT)
	$(RM) libft.a pipex
	$(RM) $(OBJ_DIR)

fclean : clean
	$(RM) $(OBJ_DIR)
	
re : fclean all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonghlee <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 15:00:44 by yonghlee          #+#    #+#              #
#    Updated: 2022/03/23 16:01:11 by yonghlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_memset.c	\
		ft_bzero.c		\
		ft_memcpy.c		\
		ft_memmove.c 	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_strlen.c		\
		ft_isalpha.c 	\
		ft_isdigit.c	\
		ft_isalnum.c	\
		ft_isascii.c	\
		ft_isprint.c	\
		ft_toupper.c	\
		ft_tolower.c	\
		ft_strchr.c		\
		ft_strrchr.c	\
		ft_strncmp.c	\
		ft_strlcpy.c	\
		ft_strlcat.c	\
		ft_strnstr.c	\
		ft_atoi.c		\
		ft_calloc.c		\
		ft_strdup.c		\
		ft_substr.c		\
		ft_strjoin.c 	\
		ft_strtrim.c	\
		ft_split.c		\
		ft_itoa.c		\
		ft_strmapi.c	\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\
		ft_striteri.c

BONSRCS = ft_lstnew.c		\
		ft_lstadd_front.c	\
		ft_lstsize.c		\
		ft_lstlast.c		\
		ft_lstadd_back.c	\
		ft_lstclear.c		\
		ft_lstdelone.c		\
		ft_lstiter.c		\
		ft_lstmap.c			\

OBJS = $(SRCS:.c=.o)

BONOBJS = $(BONSRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

ifdef WITH_BONUS
	OBJ_RESULT = ${OBJS} ${BONOBJS}
else
	OBJ_RESULT = ${OBJS}
endif

all : $(NAME)

$(NAME) : $(OBJ_RESULT)
	ar rcs $@ $^

%.o : %c
	gcc $(CFLAGS) -c $< -o $@

bonus :
	@make WITH_BONUS=1 all

clean :
	rm -rf $(OBJS) $(BONOBJS)

fclean : clean
	rm -rf $(NAME) 

re : fclean all

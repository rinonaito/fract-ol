# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 12:49:08 by rnaito            #+#    #+#              #
#    Updated: 2023/05/14 16:49:54 by rnaito           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol

HEADER		= fractol.h

LIBFT		= ./libft/libft.a

LIBFT_DIR	= libft/

SRCS		= main.c \
			  event_handler.c \
			  pixel_put.c \
			  mandelbrot.c \

OBJS 		= $(SRCS:%.c=%.o)

CC			= cc
# CFLAGS		= -Wall -Wextra -Werror
CFLAGS		= -Wall -Wextra -Werror -g 
# LFLAGS		= -fsanitize=address

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(LFLAGS) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o%.c: $(LIBFT)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(LIBFT): $(LIBFT_DIR)
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all %.o%.c clean fclean re 

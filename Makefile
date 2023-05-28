# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnaito <rnaito@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 16:01:50 by rnaito            #+#    #+#              #
#    Updated: 2023/05/26 19:51:27 by rnaito           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

LIBS = -lm -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

NAME_LIBFT = libft.a
LIBFT_DIR = libft/

MLX_DIR = /usr/local/lib/
MLX_INCLUDE = /usr/local/include/

#####################################
#          MANDATORY PART           #
#####################################
NAME = fractol
INCLUDES = -I $(SRCSDIR) -I $(LIBFT_DIR) -I $(MLX_INCLUDE)
SRCSDIR = srcs/
SRCS =	main.c\
		ft_check_arg.c\
		ft_get_pallet.c\
		ft_get_julia_type.c\
		ft_show_options.c\
		ft_make_img.c\
		ft_determine_colour.c\
		key_event.c\
		mouse_event.c
OBJSDIR = objs/
OBJS = $(SRCS:%.c=$(OBJSDIR)%.o)

#####################################
#            BONUS  PART            #
#####################################
NAME_BONUS = fractol_bonus
INCLUDES_BONUS = -I $(SRCSDIR_BONUS) -I $(LIBFT_DIR) -I $(MLX_INCLUDE)
SRCSDIR_BONUS = srcs_bonus/
SRCS_BONUS =	main_bonus.c\
				ft_check_arg_bonus.c\
				ft_get_pallet_bonus.c\
				ft_get_julia_type_bonus.c\
				ft_show_options_bonus.c\
				ft_make_img_bonus.c\
				ft_determine_colour_bonus.c\
				key_event_bonus.c\
				mouse_event_bonus.c
OBJSDIR_BONUS = objs_bonus/
OBJS_BONUS = $(SRCS_BONUS:%.c=$(OBJSDIR_BONUS)%.o)

vpath %.c $(SRCSDIR) $(SRCSDIR_BONUS)
vpath %.h $(SRCSDIR) $(SRCSDIR_BONUS)
vpath %.o $(OBJSDIR) $(OBJSDIR_BONUS) $(OBJSDIR_DEBUG)
vpath %.a $(LIBFT_DIR) $(MLX_DIR)

#####################################
#          MANDATORY PART           #
#####################################
all: $(NAME)
$(NAME): $(NAME_LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@
$(OBJSDIR)%.o: %.c
	mkdir -p $(OBJSDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
$(NAME_LIBFT):
	make -C $(LIBFT_DIR)

#####################################
#            BONUS  PART            #
#####################################
bonus: $(NAME_BONUS)
$(NAME_BONUS): $(NAME_LIBFT) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBS) -o $@
$(OBJSDIR_BONUS)%.o: %.c
	mkdir -p $(OBJSDIR_BONUS)
	$(CC) $(CFLAGS) $(INCLUDES_BONUS) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -rf $(OBJS) $(OBJS_BONUS) $(OBJS_DEBUG) $(OBJSDIR) $(OBJSDIR_BONUS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME) $(NAME_BONUS) $(NAME_DEBUG)

re: fclean all

.PHONY: fclean all re clean

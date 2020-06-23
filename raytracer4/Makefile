# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/02 17:42:25 by aahizi-e          #+#    #+#              #
#    Updated: 2020/06/08 15:56:38 by aahizi-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = raytracer

CC = gcc

CFLAGS = -Wall -Wextra

OPTIFLAGS = -O2 -flto

DEBUGFLAG = -g3 -fsanitize=address

LIBMLX = minilibx_macos/libmlx.a

LIBMATH = libmath/libmath.a

LIBFT = get_next_line/libft/libft.a

SRCS = \
		mlx.c\
		ray.c\
		object.c\
		sphere.c\
		intersection.c\
		reflection.c\
		light.c\
		world.c\
		computations.c\
		camera.c\
		plane.c\
		cylinder.c\
		cone.c\
		get_next_line/get_next_line.c\
		creation.c\
		parse_file.c\
		parse_infos.c\


OBJS = $(SRCS:.c=.o)

all: math $(NAME)

math:
	@$(MAKE) -C libmath/

$(NAME): $(OBJS) rt.h Makefile
	$(CC) $(CFLAGS) $(OPTIFLAGS) $(LIBMATH) $(OBJS) $(LIBMLX) $(LIBFT) -framework OpenGl -framework AppKit -lm -o $@

normal: $(OBJS) rt.h Makefile
	@$(MAKE) -C libmath/
	@$(CC) $(CFLAGS) $(LIBMATH) $(OBJS) $(LIBMLX) -framework OpenGl -framework AppKit -lm -o $(NAME)

opti: $(OBJS) rt.h Makefile
	$(CC) $(OPTIFLAGS) $(CFLAGS) $(LIBMATH) $(OBJS) $(LIBMLX) $(LIBFT) -framework OpenGl -framework AppKit -lm -o $(NAME)

debug: $(OBJS) rt.h Makefile
	$(CC) -g3 -fsanitize=address $(CFLAGS) $(LIBMATH) $(OBJS) $(LIBMLX) $(LIBFT) -framework OpenGl -framework AppKit -lm -o $(NAME)

clean:
	@$(MAKE) clean -C libmath/
	@rm -f $(OBJS)

fclean: clean
	@$(MAKE) fclean -C libmath/
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re opti normal math
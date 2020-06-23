# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aahizi-e <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/03 23:24:55 by aahizi-e          #+#    #+#              #
#    Updated: 2020/06/05 16:29:47 by aahizi-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libmath.a

CC = gcc

CFLAGS = -O2 -c -flto -Wall -Werror -Wextra -Wconversion

# SRCS =
# 		assign_matrix.c\
# 		assign_tuple.c\
# 		clampd.c\
# 		deg_to_rad.c\
# 		is_matrix_16_equal.c\
# 		is_tuple_equal.c\
# 		rad_to_deg.c\

SRCS = \
		add_color.c\
		add_tuple.c\
		color.c\
		cross.c\
		display_matrix_4.c\
		display_tuple.c\
		div_tuple.c\
		dot.c\
		equal.c\
		identity.c\
		inverse_matrix.c\
		magnitude.c\
		mul_color.c\
		mul_mm.c\
		mul_mt.c\
		mul_scl_color.c\
		mul_scl_tuple.c\
		negate.c\
		normalize.c\
		point.c\
		rotation_x.c\
		rotation_y.c\
		rotation_z.c\
		scaling.c\
		sub_color.c\
		sub_tuple.c\
		vector.c\
		translation.c\
		transpose.c\
		zero_matrix.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) libmath.h Makefile
	@$(CC) -c $(CFLAGS) $(SRCS)
	@ar rcs $@ $(OBJS)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: izelensk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 12:17:24 by izelensk          #+#    #+#              #
#    Updated: 2017/08/07 16:21:45 by izelensk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

SRCS = main.c operations.c read_data.c get_next_line.c rotations.c perlin.c\
		init_objects.c init_structs.c colors.c vectors.c intersections.c hooks.c images.c intersect_smt.c 

OBJS = main.o operations.o read_data.o get_next_line.o rotations.o perlin.o\
		init_objects.o init_structs.o colors.o vectors.o intersections.o hooks.o images.o intersect_smt.o

HEADER = rtv1.h get_next_line.h

mlgcc = gcc -framework OpenGL -framework AppKit 

JUNK = $(wildcard .DS_Store */.DS_Store */*/.DS_Store *.gch \
		  get_next_line/*.gch )

all:$(NAME)

$(NAME): $(OBJS)
	@make -C libft/
	@gcc -c -Wall -Wextra -Werror $(HEADER) $(SRCS)
	@$(mlgcc) -o $(NAME) $(OBJS) libft/libft.a 	libmlx.a
	@rm -rf $(JUNK)
	@echo "compiled"

clean:
	@rm -rf $(OBJS)
	@rm -f rtv1.h.gch get_next_line.h.gch
	@echo "cleaned"

fclean: clean
	@rm -rf $(NAME)
	@echo "fcleaned"

libclean: fclean
	@make fclean -C libft/
	@echo "libcleaned"

re: fclean all

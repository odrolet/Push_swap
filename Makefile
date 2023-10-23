# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oldrolet <oldrolet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 13:28:18 by oldrolet          #+#    #+#              #
#    Updated: 2023/10/19 12:49:19 by oldrolet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = push_swap_bonus
LIBFT = libft
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
MK = mkdir -p
RM = rm -rf
USER = $(shell whoami)
HEADERS = -I ./include
INCDIR = inc
SRCDIR = src
LIBFT_A = libft.a
LIBFTDIR = libft
LIBFT = $(addprefix $(LIBFTDIR)/, $(LIBFT_A))
SRC = 	main.c \
		stack_init.c \
		utils.c \
		errors.c \
		swap.c \
		sort.c \
		rotate.c \
		reverse_rotate.c \
		push.c \
		push_swap.c \
		push_swap_init.c \
		ps_split.c \
		parsing.c \
	

VPATH = $(SRCDIR)
OBJDIR = obj
OBJS = $(addprefix ${OBJDIR}/, ${SRC:%.c=%.o})
OBJSB = $(addprefix ${OBJDIR}/, ${SRCB:%.c=%.o})

all: $(NAME)

${OBJDIR}/%.o : %.c
	${CC} ${CFLAGS} -I${INCDIR} -Ilibft -c $< -o $@

$(NAME): $(OBJDIR) $(OBJS)
	make -C $(LIBFTDIR) bonus
	$(CC) ${CFLAGS} $(OBJS) -L$(dir $(LIBFT)) -lft -o $(NAME)

$(OBJDIR):
	$(MK) $(OBJDIR)

$(NAME_BONUS): $(OBJDIR) $(OBJSB)
	make -C $(LIBFTDIR) bonus
	$(CC) ${CFLAGS} $(OBJSB) -L$(dir $(LIBFT))-lft -o $(NAME_BONUS)

#bonus: $(NAME_BONUS)

clean:
	$(RM) $(OBJDIR)
	make -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	make -C $(LIBFTDIR) fclean

visudown:
	git clone https://github.com/o-reo/push_swap_visualizer.git && cd push_swap_visualizer && mkdir build && cd build && cmake .. && make

visu:
	./push_swap_visualizer/build/bin/visualizer

test:
	@echo "10 tests/ 0 - 500"
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@echo "/	/	/	/	/"
	@echo "10 tests/ 0 - 100"
	@./push_swap `ruby -e "puts (1..100).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..100).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..100).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..100).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..100).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..100).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..100).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..100).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..100).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..100).to_a.shuffle.join(' ')"` | wc -l
	@echo "/	/	/	/	/"
	@echo "10 tests/ 0 - 3"
	@./push_swap `ruby -e "puts (0..2).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (0..2).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (0..2).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (0..2).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (0..2).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (0..2).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (0..2).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (0..2).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (0..2).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (0..2).to_a.shuffle.join(' ')"` | wc -l

re: fclean all

run: re

.PHONY: all clean fclean re run

leaks : all
	valgrind --track-fds=yes --trace-children=yes --leak-check=full --show-leak-kinds=all ./$(NAME)
NAME = push_swap
SRCS = helper.c\
	main_sort_utilits.c\
	node_utilits.c\
	pre_checker.c\
	push_swap.c\
	push_to_stack.c\
	rotatedown2top.c\
	rotatetop2down.c\
	sort_utilits.c\
	swap.c\
	utilits.c
CC = cc
CFLAGS =  -Wall -Wextra -Werror -g
OBJS = $(SRCS:.c=.o)
all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
clean:
	rm -f $(OBJS)
fclean:clean
	rm -f $(NAME)
re: fclean $(NAME)
.PHONY: all clean fclean re
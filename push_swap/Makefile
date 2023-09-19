CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = change.c check_err.c hard_cording.c operations_push.c operations_reverse_rotate.c operations_rotate.c operations_swap.c push_swap.c setting.c sort_functions_ver_2.c sort_functions.c
NAME = push_swap
HEADER = push_swap.h

.PHONY : all clean fclean re

all : $(NAME)

re : fclean all

clean :
	rm -rf $(NAME)

fclean : clean 
	rm -rf $(NAME)

$(NAME) : $(SRCS) $(HEADER)
	$(CC) $(CFLAGS) $(SRCS) -o $@


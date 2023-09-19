CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = pipex.c ft_functions1.c ft_functions2.c error_functions.c fork_functions.c
NAME = pipex
HEADER = pipex.h

.PHONY : all clean fclean re

all : $(NAME)

re : fclean all

clean :
	

fclean : clean 
	rm -rf $(NAME)

$(NAME) : $(SRCS) $(HEADER)
	$(CC) $(CFLAGS) $(SRCS) -o $@

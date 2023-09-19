CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
SRCS = ft_printf.c print_function1.c print_function2.c
NAME = libftprintf.a
HEADER = ft_printf.h

.PHONY : all clean fclean re

all : $(NAME)

re : fclean all

clean :
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean : clean 
	rm -rf $(NAME)

$(NAME) : $(OBJS)
	ar rcs $@ $^

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<
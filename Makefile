NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf_number.c ft_printf_pointer.c ft_printf.c ft_split.c main.c get_next_line_utils.c exe_cmd.c get_next_line.c library.c here_doc.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I . -c $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
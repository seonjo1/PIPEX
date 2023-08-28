NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf_number.c freeing.c ft_printf_pointer.c ft_printf.c ft_split.c main.c get_next_line_utils.c exe_cmd.c get_next_line.c library.c here_doc.c
SRCS2 = ft_printf_number_bonus.c freeing_bonus.c ft_printf_pointer_bonus.c ft_printf_bonus.c ft_split_bonus.c main_bonus.c get_next_line_utils_bonus.c exe_cmd_bonus.c get_next_line_bonus.c library_bonus.c here_doc_bonus.c
OBJS = $(SRCS:.c=.o)
OBJS2 = $(SRCS2:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus : $(OBJS2)
	$(CC) $(CFLAGS) $(OBJS2) -o $(NAME)
	@touch bonus

%.o : %.c
	$(CC) $(CFLAGS) -I . -c $<

clean :
	rm -f $(OBJS)
	rm -f $(OBJS2)
	rm -f bonus

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
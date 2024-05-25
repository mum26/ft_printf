NAME    = libftprintf.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
AR      = ar rcs
RM      = rm -f
INC_DIR = ./libftpritf.h
SRC_DIR = .
SRCS    = ft_printf.c
OBJS    = 

all: $(NAME)

$(NAME): $(OBJS) 
	$(NAME) -C ./libft
	cp libft/libft.a $(NAME)
	$(AR) $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(STD_OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

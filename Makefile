NAME    = libftprintf.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g -Ilibft
LDFLAGS = -Llibft -lft
AR      = ar rcs
RM      = rm -f
INC_DIR = .
SRC_DIR = .
SRCS    = ft_printf.c
OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) libft/libft.a
	$(AR) $@ $^
	ranlib $@

libft/libft.a:
	@$(MAKE) -C libft

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@$(MAKE) -C libft clean
	$(RM) $(OBJS)

fclean:
	@$(MAKE) -C libft fclean
	$(RM) $(OBJS)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

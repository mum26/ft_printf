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

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS) libft/libft.a
	$(AR) $(NAME) $(OBJS)
	ranlib $(NAME)

libft/libft.a:
	$(MAKE) -C libft bonus

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean
clean:
	$(MAKE) -C libft clean
	$(RM) $(OBJS)

.PHONY: fclean
fclean:
	$(MAKE) -C libft fclean
	$(RM) $(OBJS) $(NAME)

.PHONY: re
re: fclean all

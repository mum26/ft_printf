NAME     = libftprintf.a
CFLAGS   = -Wall -Wextra -Werror -g -Ilibft
AR       = ar rcs
SRCS     = ft_printf.c
OBJS     = $(SRCS:.c=.o)
LIB_NAME = libft
LIB_PATH = ./$(LIB_NAME)/$(LIB_NAME).a

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS) $(LIB_PATH)
	cp $(LIB_PATH) $(NAME)
	$(AR) $(NAME) $(OBJS)
	ranlib $(NAME)

$(LIB_PATH):
	$(MAKE) -C $(LIB_NAME) bonus

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(MAKE) -C $(LIB_NAME) clean
	$(RM) $(OBJS)

.PHONY: fclean
fclean:
	$(MAKE) -C $(LIB_NAME) fclean
	$(RM) $(OBJS) $(NAME)

.PHONY: re
re: fclean all

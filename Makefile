CC = gcc

LIBFT_DIR = ../LibC
PRINTF_DIR = ../printf

CFLAGS = -Wall -Wextra -Werror -g3 -Iinclude -I$(LIBFT_DIR)/include
CFLAGS += -I$(PRINTF_DIR)/include

LDFLAGS = -L$(LIBFT_DIR) -L$(PRINTF_DIR) -lftprintf -lft

NAME = ft_ls

SRCS = $(shell find src/ -name "*.c")

OBJS = $(SRCS:.c=.o)

all: make_libs $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

make_libs:
	(cd $(LIBFT_DIR) && $(MAKE))
	(cd $(PRINTF_DIR) && $(MAKE))

clean_libs:
	(cd $(LIBFT_DIR) && $(MAKE) clean)
	(cd $(PRINTF_DIR) && $(MAKE) clean)

fclean_libs:
	(cd $(LIBFT_DIR) && $(MAKE) fclean)
	(cd $(PRINTF_DIR) && $(MAKE) fclean)

re_libs:
	(cd $(LIBFT_DIR) && $(MAKE) re)
	(cd $(PRINTF_DIR) && $(MAKE) re)

.PHONY: all clean fclean re make_libs clean_libs fclean_libs re_libs
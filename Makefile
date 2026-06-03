NAME		= ft_ssl

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I includes

SRCS_DIR	= srcs
OBJS_DIR	= objs

SRCS		= $(SRCS_DIR)/main.c \
			  $(SRCS_DIR)/dispatcher.c \
			  $(SRCS_DIR)/commands/md5.c \
			  $(SRCS_DIR)/commands/sha256.c \
			  $(SRCS_DIR)/hash/md5_algo.c \
			  $(SRCS_DIR)/hash/sha256_algo.c \
			  $(SRCS_DIR)/io/input.c \
			  $(SRCS_DIR)/io/output.c \
			  $(SRCS_DIR)/parsing/args.c \
			  $(SRCS_DIR)/utils/string.c \
			  $(SRCS_DIR)/utils/error.c

OBJS		= $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

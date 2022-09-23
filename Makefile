NAME = minitalk
SERVER = server
CLIENT = client
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = libft/libft.a
SERVER_SRCS = server.c
CLIENT_SRCS = client.c

all: $(NAME)

$(NAME):
	@make -C libft
	$(CC) $(CFLAGS) $(INC) $(SERVER_SRCS) -o $(SERVER)
	$(CC) $(CFLAGS) $(INC) $(CLIENT_SRCS) -o $(CLIENT)

clean:
	@make clean -C libft
	rm -rf $(SERVER)
	rm -rf $(CLIENT)

fclean:
	@make fclean -C libft
	rm -rf $(SERVER)
	rm -rf $(CLIENT)

re: fclean all

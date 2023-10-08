NAME 	= "cub3D"
HEADER	= includes/$(NAME).h
FILES	=	main.c					\
			src/check_file_map.c	\
			src/file/file.c			\
			src/map/map.c			\
			src/load_game.c			\
			src/finish_game.c		\
			src/start_game.c
OBJS	= $(FILES:.c=.o)
CC		= gcc
CC_ARGS = -Wextra -Wall -Werror -g3
LIBS	= libs/libft

all: $(LIBS) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CC_ARGS) $(OBJS) -L $(LIBS) -lft -lreadline -o $(NAME)
	ar rsc $(LIBS)/lib$(NAME).a $(OBJS)

%.o: %.c
	$(CC) $(CC_ARGS) -I$(LIBS) -c $< -o $@	

$(LIBS):
	make -C $(LIBS)

clean:
	make -C $(LIBS) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBS) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re $(LIBS)

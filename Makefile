NAME 	=	cub3D

LIBS	=	libs/libft

HEAD_DIR=	includes libs/libft
OBJ_DIR	=	bin
SRC_DIR	=	src

SRC	=	src/main.c					\
		src/file/check_file_map.c	\
		src/file/file.c				\
		src/engine/exit/exit.c		\
		src/engine/hooks/keys.c		\
		src/map/map.c				\
		src/load_game.c				\
		src/finish_game.c			\
		src/start_game.c

OBJ	=	$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
HEADERS = includes/$(NAME).h libs/libft/libft.h

CC	= gcc
CC_ARGS = -Wextra -Wall -Werror -g3

all: $(LIBS) $(NAME)

$(NAME): $(OBJ)

	$(CC) $(CC_ARGS) -o $(NAME) $(OBJ) -L $(LIBS) -lft -lXext -lX11 -lm -lz -lmlx $(HEAD_DIR:%=-I%/)
	ar rsc $(LIBS)/libft.a $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	mkdir -p $(@D)
	$(CC) $(CC_ARGS) -c $< -o $(@:$(SRC_DIR)=$(OBJ_DIR)) $(HEAD_DIR:%=-I%/)

$(LIBS):
	make -C $(LIBS)

clean:
	make -C $(LIBS) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIBS) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re $(LIBS)
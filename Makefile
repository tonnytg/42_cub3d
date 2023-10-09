NAME 	=	cub3D

LIBS	=	libs/libft

HEAD_DIR=	includes
OBJ_DIR	=	bin
SRC_DIR	=	src

SRC	=	src/main.c				\
		src/check_file_map.c	\
		src/file/file.c			\
		src/map/map.c			\
		src/load_game.c			\
		src/finish_game.c		\
		src/start_game.c

OBJ	=	$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

CC		= gcc
OPTIONS = -Wextra -Wall -Werror -lXext -lX11 -lm -lz -lmlx -g3

all: $(LIBS) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OPTIONS) -o $(NAME) $(OBJ) $(HEAD_DIR:%=-I%/)
	ar rsc $(LIBS)/lib$(NAME).a $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEAD)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $(@:$(SRC_DIR)=$(OBJ_DIR)) $(HEAD_DIR:%=-I%/)

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

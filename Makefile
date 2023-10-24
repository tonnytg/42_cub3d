NAME 	=	cub3D

LIBS	=	libs/libft

HEAD_DIR=	includes libs/libft
OBJ_DIR	=	bin
SRC_DIR	=	src

SRC	=	src/main.c								\
		src/file/check_file_map.c				\
		src/file/file.c							\
		src/engine/exit.c						\
		src/engine/keys.c						\
		src/engine/2D/player.c					\
		src/engine/2D/map/build_map.c			\
		src/engine/2D/images/put_image.c		\
		src/engine/3D/draw.c					\
		src/engine/3D/raycast/fov.c				\
		src/engine/3D/dda/dda.c					\
		src/engine/background.c					\
		src/engine/3D/raycast/raycast.c			\
		src/engine/render/render.c				\
		src/map/images/load_default_images.c 	\
		src/map/images/load_custom_images.c 	\
		src/map/images/load_images.c 			\
		src/map/map_player.c					\
		src/map/color/color.c					\
		src/load_game.c							\
		src/finish_game.c						\
		src/map/map_utils.c						\
		src/map/map_read.c						\
		src/map/map_check.c						\
		src/start_game.c

OBJ	=	$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
HEADERS =	includes/$(NAME).h \
			includes/player.h \
			libs/libft/libft.h

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
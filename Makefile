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
		src/engine/player.c						\
		src/engine/build_map.c					\
		src/engine/draw.c						\
		src/engine/fov.c						\
		src/engine/background.c					\
		src/engine/render.c						\
		src/images/load_default_images.c		\
		src/images/load_custom_images.c			\
		src/images/load_images.c 				\
		src/map/map_player.c					\
		src/images/color.c						\
		src/images/check_colors.c				\
		src/map/map_read.c						\
		src/map/map_check.c						\
		src/map/map_check_errors.c				\
		src/load_game.c							\
		src/start_game.c						\
		src/finish_game.c						\

OBJ	=	$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
OBJ_BONUS	=	$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)_bonus%.o)
HEADERS =	includes/$(NAME).h \
			includes/player.h \
			libs/libft/libft.h

CC	= gcc
CC_ARGS = -Wextra -Wall -Werror -g3

all: $(LIBS) $(NAME)
bonus: $(LIBS) $(NAME)_bonus

$(NAME): $(OBJ)

	$(CC) $(CC_ARGS) -o $(NAME) $(OBJ) -L $(LIBS) -lft -lXext -lX11 -lm -lz -lmlx $(HEAD_DIR:%=-I%/)
	ar rsc $(LIBS)/libft.a $(OBJ)

$(NAME)_bonus: $(OBJ_BONUS)
	$(CC) $(CC_ARGS) -o $(NAME)_bonus $(OBJ_BONUS) -L $(LIBS) -lft -lXext -lX11 -lm -lz -lmlx $(HEAD_DIR:%=-I%/)
	ar rsc $(LIBS)/libft.a $(OBJ_BONUS)	

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	mkdir -p $(@D)
	$(CC) $(CC_ARGS) -c $< -o $(@:$(SRC_DIR)=$(OBJ_DIR)) $(HEAD_DIR:%=-I%/)

$(OBJ_DIR)_bonus/%.o: $(SRC_DIR)/%.c $(HEADERS)
	mkdir -p $(@D)
	$(CC) $(CC_ARGS) -c $< -DMINIMAP=1 -o $(@:$(SRC_DIR)=$(OBJ_DIR)_bonus) $(HEAD_DIR:%=-I%/)	

$(LIBS):
	make -C $(LIBS)

clean:
	make -C $(LIBS) clean
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)

fclean: clean
	make -C $(LIBS) fclean
	rm -f $(NAME)
	rm -rf $(NAME)_bonus
	rm -rf bin
	rm -rf bin_bonus

re: fclean all

.PHONY: all clean fclean re $(LIBS) bonus
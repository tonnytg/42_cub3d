NAME 	=	cub3D
NAME_BONUS 	=	cub3D_bonus

LIBS	=	libs/libft

HEAD_DIR=	includes libs/libft
HEAD_DIR_BONUS =	includes_bonus libs/libft
OBJ_DIR	=	bin
OBJ_DIR_BONUS = bin_bonus
SRC_DIR	=	src
SRC_DIR_BONUS	=	src_bonus

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
		src/finish_game.c

SRC_BONUS	=	src_bonus/main.c								\
				src_bonus/file/check_file_map.c					\
				src_bonus/file/file.c							\
				src_bonus/engine/exit.c							\
				src_bonus/engine/keys.c							\
				src_bonus/engine/player.c						\
				src_bonus/engine/build_map.c					\
				src_bonus/engine/draw.c							\
				src_bonus/engine/fov.c							\
				src_bonus/engine/background.c					\
				src_bonus/engine/render.c						\
				src_bonus/images/load_default_images.c			\
				src_bonus/images/load_custom_images.c			\
				src_bonus/images/load_images.c 					\
				src_bonus/map/map_player.c						\
				src_bonus/images/color.c						\
				src_bonus/images/check_colors.c					\
				src_bonus/map/map_read.c						\
				src_bonus/map/map_check.c						\
				src_bonus/map/map_check_errors.c				\
				src_bonus/load_game.c							\
				src_bonus/start_game.c							\
				src_bonus/finish_game.c		

OBJ	=	$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
OBJ_BONUS	=	$(SRC_BONUS:$(SRC_DIR_BONUS)%.c=$(OBJ_DIR_BONUS)%.o)
HEADERS =	includes/$(NAME).h \
			includes/player.h \
			libs/libft/libft.h

HEADERS_BONUS =	includes_bonus/$(NAME).h \
			includes_bonus/player.h \
			libs/libft/libft.h			

CC	= gcc
CC_ARGS = -Wextra -Wall -Werror -g3

all: $(LIBS) $(NAME)
bonus: $(LIBS) $(NAME)_bonus

$(NAME): $(OBJ)

	$(CC) $(CC_ARGS) -o $(NAME) $(OBJ) -L $(LIBS) -lft -lXext -lX11 -lm -lz -lmlx $(HEAD_DIR:%=-I%/)
	ar rsc $(LIBS)/libft.a $(OBJ)

bonus: $(OBJ_BONUS)

	$(CC) $(CC_ARGS) -DMINIMAP=1 -o $(NAME_BONUS) $(OBJ_BONUS) -L $(LIBS) -lft -lXext -lX11 -lm -lz -lmlx $(HEAD_DIR_BONUS:%=-I%/)
	ar rsc $(LIBS)/libft.a $(OBJ_BONUS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	mkdir -p $(@D)
	$(CC) $(CC_ARGS) -c $< -o $(@:$(SRC_DIR)=$(OBJ_DIR)) $(HEAD_DIR:%=-I%/)

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c $(HEADERS_BONUS)
	mkdir -p $(@D)
	$(CC) $(CC_ARGS) -DMINIMAP=1 -c $< -o $(@:$(SRC_DIR_BONUS)=$(OBJ_DIR_BONUS)) $(HEAD_DIR_BONUS:%=-I%/)	

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
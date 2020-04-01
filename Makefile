NAME = fdf
WFL = -Wall -Wextra -Werror
FRAME = -framework OpenGL -framework AppKit
INC_DIR	= ./includes/
SRC_DIR = ./src/
SRC =   main.c \
		read_file.c \
		draw.c \
		extra_functions.c \
		check.c

OBJ_DIR = ./objects/

FDF_FILES = $(patsubst %.c, %.o, $(SRC))
FDF_OBJECTS = $(addprefix $(OBJ_DIR), $(FDF_FILES))

HEADER_FILES = fdf.h
HEADERS = $(addprefix $(INC_DIR), $(HEADER_FILES))

LIBFT = ./libft
MLX = ./minilibx_macos

IFL = -I$(INC_DIR)

all : $(NAME)

$(NAME): $(FDF_OBJECTS)
		$(MAKE) -C $(LIBFT)/
		$(MAKE) -C $(MLX)/
		gcc $(WFL) $^ $(LIBFT)/libftprintf.a $(MLX)/libmlx.a $(IFL) $(FRAME) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
		mkdir -p ./objects
		gcc $(WFL) -c $< -o $@ $(IFL)

clean:
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(MLX) clean
	/bin/rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
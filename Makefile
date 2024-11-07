#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#

.PHONY: all bonus clean fclean re
# .SILENT:

#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CC		=	gcc
TEMP	=
CFLAGS	=	-Wall -Werror -Wextra
DEBUG	=	-g3 -fsanitize=address 
RM		=	rm -rf

# Output file name
NAME	=	fdf

# Directories
LIBFT_DIR		=	libft
INC_LIBFT		=	libft/includes
MLX_DIR			=	mlx_linux
INC_DIR			=	includes
INCS			=	-I$(INC_LIBFT) -I$(MLX_DIR) -I$(INC_DIR)

SRCS_DIR		=	srcs/
OBJS_DIR		=	bin/

LIBFT_FLAGS		=	-L$(LIBFT_DIR) -lft
MLX_FLAGS		=	-L$(MLX_DIR) -lmlx_Linux
LIBS			=	$(MLX_FLAGS) $(LIBFT_FLAGS)
1X_FLAGS		=	-lXext -lX11 -lm -lz

SRCS_FILES		=	srcs/lines.c \
					srcs/main.c \
					srcs/map.c \
					srcs/mlx_hooks_bonus.c \
					srcs/mlx_hooks_mandatory.c \
					srcs/mlx.c \
					srcs/parser.c \
					srcs/render.c \
					srcs/rotation.c \
					srcs/utils_colour.c \
					srcs/utils_math.c \
					srcs/utils_parser.c \
					srcs/utils.view.c \
					srcs/view.c \
					srcs/debug.c

OBJS_FILES		=	$(patsubst %.c, $(OBJS_DIR)%.o, $(SRCS_FILES))

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(NAME)

bonus: all

mlx:
	make -C $(MLX_DIR)

# Generates output file
$(NAME): $(OBJS_FILES)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(INCS) $(OBJS_FILES) -o $(NAME) $(LIBS) $(1X_FLAGS)

# Rule to compile the mandatory object files
$(OBJS_DIR)%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCS) -O3 -c $< -o $@

# Rule to create the object directory if it doesn't exist
$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)$(SRCS_DIR)

remake_libft:
	make re -C $(LIBFT_DIR)

# Removes objects
clean:
	$(RM) $(OBJS_DIR)
	make clean -C $(LIBFT_DIR)

# Removes objects and executables
# $(RM) $(BONUS_NAME)
fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

# Removes objects and executables and remakes
re: fclean $(OBJS_DIR) all

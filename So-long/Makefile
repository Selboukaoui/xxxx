CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = solong

SRC = Mandatory/solong.c Mandatory/utils/ft_atoi.c Mandatory/utils/ft_strcmp.c Mandatory/utils/ft_strlen.c \
	  Mandatory/utils/grb_coll.c Mandatory/utils/check_map.c Mandatory/utils/errors.c
OBJS = $(SRC:.c=.o)

FT_PRINTF_DIR = ft_printf
GNL_DIR = get_next_line

FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a
GNL_SRC = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
GNL_OBJS = $(GNL_SRC:.c=.o)

INCLUDES = -Iincludes -I$(FT_PRINTF_DIR) -I$(GNL_DIR)

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

all: $(FT_PRINTF_LIB) $(GNL_OBJS) $(NAME)

$(NAME): $(OBJS) $(FT_PRINTF_LIB) $(GNL_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF_LIB) $(GNL_OBJS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(FT_PRINTF_LIB):
	make -C $(FT_PRINTF_DIR)

clean:
	rm -f $(OBJS) $(GNL_OBJS)
	make -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(FT_PRINTF_DIR) fclean


re: fclean all

.PHONY: clean

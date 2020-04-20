#Compiler Options
C_FLAGS =  -Wall -Wextra -Werror
#Filenames
LIBFT_DIR := libft/
LIBX_DIR := minilibx/
NAME := fdf
SRCS := main.c make_axis.c change_value.c charge_to_draw.c rotation.c control_key.c\
			lines_and_dots.c skitlz_to_map.c utils_for_axis.c zero_to_structures.c
OBJECTS := $(SRCS:.c=.o)
HEADER = libft/libft.h
all: $(NAME)
$(NAME): $(OBJECTS)
	make -C $(LIBFT_DIR)	
	gcc -o $(NAME) $(OBJECTS) -L$(LIBFT_DIR) -lft -L. -lmlx -framework OpenGL -framework AppKit
$(OBJECTS): %.o: %.c
	gcc $(C_FLAGS) -o $@ -c $<

clean:
	make clean -C $(LIBFT_DIR)
	/bin/rm -f $(OBJECTS)
fclean: clean
	make fclean -C $(LIBFT_DIR)
	/bin/rm -f $(NAME)
	/bin/rm -f libft.a
re: fclean all


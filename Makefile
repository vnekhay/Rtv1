NAME = RTv1

SRCS = 	src/draw_and_etc.c \
	  	src/figure_parser.c \
	  	src/init_scenes.c \
	 	src/init_scenes2.c \
	 	src/key_hook.c \
	  	src/math_equations.c \
	  	src/rtv_additions.c \
	  	src/rtv_begin.c \
	  	src/shade_reflection.c \

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror -O3

C_NO	=	"\033[00m"
C_OK	=	"\033[35m"
C_GOOD	=	"\033[32m"
C_ERROR	=	"\033[31m"
C_WARN	=	"\033[33m"
SUCCESS	=	$(C_GOOD)SUCCESS$(C_NO)
OK		=	$(C_OK)OK$(C_NO)

all: $(NAME)

%.o : src/%.c inc/rtv_1.h
	gcc $(FLAGS) -o $@ -c $<
	@echo "Linking" [ $< ] $(OK)

$(NAME):  $(OBJS) inc/rtv_1.h
	make -C libft
	gcc $(FLAGS) -L./libft -lft $(OBJS) -o $(NAME) -lmlx -framework OpenGL -framework AppKit
	@echo "Compiling & indexing" [$(NAME)] $(SUCCESS)

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all, clean, fclean, re

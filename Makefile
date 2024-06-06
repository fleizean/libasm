NAME	=	libasm.a

SRC		=	src/ft_read.asm \
			src/ft_strcmp.asm \
			src/ft_strcpy.asm \
			src/ft_write.asm \
			src/ft_strlen.asm \
			src/ft_strdup.asm

GREEN	= 	\033[38;5;46m
WHITE	= 	\033[38;5;15m
RED		= 	\033[38;5;160m
BLUE	=	\033[0;34m

SRC_O	=	$(SRC:.asm=.o)

FLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC_O)
	@echo "$(GREEN)Creating libasm.a$(WHITE)"
	@ar rc $(NAME) $(SRC_O)

%.o: %.asm
	@echo "$(BLUE)Compilling: $(WHITE)$<"
	@nasm -fmacho64 -o $@ $<

test: $(NAME)
	@gcc $(FLAGS) -L. -lasm test_cases/main.c -o test
	@echo "$(GREEN)Compiled main.c with libasm.a$(WHITE)"

clean:
	@echo "$(RED)Cleaning all .asm files$(WHITE)"
	@rm -f $(SRC_O)

fclean: clean
	@echo "$(RED)cleaning all .a files$(WHITE)"
	@rm -f $(NAME) test

re: fclean all

.PHONY: all clean fclean re test
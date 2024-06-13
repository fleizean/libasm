NAME    =   libasm.a

SRC     =   src/ft_read.s \
            src/ft_strcmp.s \
            src/ft_strcpy.s \
            src/ft_write.s \
            src/ft_strlen.s \
            src/ft_strdup.s

GREEN   =   \033[38;5;46m
WHITE   =   \033[38;5;15m
GREY    =   \033[38;5;8m
ORANGE  =   \033[38;5;202m
RED     =   \033[38;5;160m

SRC_O   =   $(SRC:.s=.o)

FLAGS   =   -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC_O)
	@echo "$(GREEN)Creating libasm.a$(WHITE)"
	@ar rc $(NAME) $(SRC_O)
	@ranlib $(NAME)

%.o: %.s
	@echo "$(GREY)Compiling: $(WHITE)$<"
	@nasm -fmacho64 -o $@ $<

test: $(NAME)
	@gcc $(FLAGS) -L. test_cases/main.c -o test -lasm -lc $(SRC_O)
	@echo "$(GREEN)Compiled main.c with libasm.a$(WHITE)"

clean:
	@echo "$(RED)Cleaning all .o files$(WHITE)"
	@rm -f $(SRC_O)

fclean: clean
	@echo "$(RED)Cleaning all .a files and test executable$(WHITE)"
	@rm -f $(NAME) test

re: fclean all

.PHONY: all clean fclean re test

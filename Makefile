CC = cc

s_c = \x1b[

NAME = push_swap

CCFLAGS = -Wall -Wextra -Werror

SRC_M = ft_split.c instructions_of_one_stack.c instructions_of_two_stacks.c push_swap.c tools.c tools2.c small_amount_of_numbers.c tools3.c sorting_functions.c

OBJ_M = $(SRC_M:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CCFLAGS) -c $< -o $@

$(NAME) : $(OBJ_M)
	$(CC) $(CCFLAGS) $(OBJ_M) -o $(NAME)

clean :
	rm -f $(OBJ_M)

fclean : clean
	rm -f $(NAME)

re : fclean all

push :
	@echo "$(s_c)32m  $(s_c)4m Please Enter The Files do You Want To Push It\n $(s_c)0m"
	@read  files;git add "$$files"
	@git status
	@echo "$(s_c)32m  $(s_c)4m Please Enter The Commit Message\n $(s_c)0m"
	@read commit; git commit -m "$$commit" ; \
	git push

CC = cc 

NAME = push_swap

CCFLAGS = -Wall -Wextra -Werror

SRC_M = src/ft_split.c src/instructions_of_one_stack.c src/instructions_of_two_stacks.c src/tools.c src/tools2.c  src/tools3.c src/tools4.c mandatory/push_swap.c mandatory/small_amount_of_numbers.c mandatory/sorting_functions.c

SRC_B =  bonus/src/ft_split.c bonus/instructions/instructions_of_one_stack_bonus.c bonus/instructions/instructions_of_two_stack_bonus.c bonus/src/tools.c bonus/src/tools2.c  bonus/src/tools3.c bonus/src/tools4.c bonus/checker.c bonus/gnl/get_next_line.c bonus/gnl/get_next_line_utils.c bonus/ft_str_cmp.c

OBJ_M = $(SRC_M:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CCFLAGS) -c $< -o $@

$(NAME) : $(OBJ_M)
	$(CC) $(CCFLAGS) $(OBJ_M) -o $(NAME)

clean :
	rm -f $(OBJ_M)
	rm -f $(OBJ_B)

fclean : clean
	rm -f $(NAME)
	rm -f checker

re : fclean all
   
bonus : $(OBJ_B)
	$(CC) $(CCFLAGS) $(OBJ_B) -o checker

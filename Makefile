INC = includes
SRC = src/*.c
INCS = -I$(INC)
FLAGS = -Wall -Wextra -Werror
NAME = push_swap.out

all:
	@clear
	@echo -n Compiling push_swap...
	@gcc $(SRC) $(INCS) $(FLAGS) -o $(NAME)
	@echo Done

run:
	@make
	@clear
	@echo sorting
	@./push_swap.out 5 4 6 3 7 2 8 1 9 4 6 3 7 2 6 4 8 23 73 234 7 33 7 34 7 23 7 1 35 4 15 68 114 35 48 72 3 14 58 64 337 15 68 13 516 48965 5641 13 51 14

git:
	@clear
	@git add .
	@echo "commit msg" 
	@read COMMIT; \
	git commit -m "$$COMMIT"; \
	git push;

clean:
	@rm -rf $(NAME)

norm:
	@clear
	@norminette $(INC) $(SRC)
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
	@echo sorting
	@./push_swap.out 5 4 6 3 7 2 8 1 9

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
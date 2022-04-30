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

run0:
	@make
	@clear
	@echo sorting
	@./push_swap.out 3 3

run1:
	@make
	@clear
	@echo sorting
	@./push_swap.out 5 12

run2:
	@make
	@clear
	@echo sorting
	@./push_swap.out 100 1500

run3:
	@make
	@clear
	@echo sorting
	@./push_swap.out 500 11500

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
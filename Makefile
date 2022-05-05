# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgobbett <jgobbett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 13:29:03 by jgobbett          #+#    #+#              #
#    Updated: 2022/05/05 16:19:49 by jgobbett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC = includes
SRC = src/*.c
SRCD = src_display/*.c
INCS = -I$(INC)
FLAGS = -Wall -Wextra -Werror
NAME = push_swap.out

all:
	@clear
	@echo -n Compiling push_swap...
	@gcc $(SRCD) $(INCS) $(FLAGS) -o $(NAME)
	@echo Done

# Run "$>ARG="<5 random values>"; ./push_swap $ARG | ./checker_OS $ARG"

run:
	@make
	@clear
	ARG="<5 random values>";
	./push_swap $ARG;

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

run4:
	@make
	@clear
	@echo sorting
	@./push_swap.out 12 50

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
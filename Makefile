# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 13:29:03 by jgobbett          #+#    #+#              #
#    Updated: 2022/05/06 15:25:18 by marvin           ###   ########.fr        #
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
	@gcc $(SRC) $(INCS) $(FLAGS) -o $(NAME)
	@echo Done

display:
	@clear
	@echo -n Compiling push_swap...
	@gcc $(SRCD) $(INCS) $(FLAGS) -o $(NAME)
	@echo Done

checker:
	Run ARG = "-100 -50 0 50 100 23 654 23 98 1 53 65"; ./push_swap $(ARG) | ./checker_OS $(ARG)"

test:
	@make
	@clear
	@echo
	@./push_swap.out 1 5 2 4 3

run0:
	@make display
	@clear
	@echo sorting
	@./push_swap.out 3 3

run1:
	@make display
	@clear
	@echo sorting
	@./push_swap.out 5 12

run2:
	@make display
	@clear
	@echo sorting
	@./push_swap.out 100 1500

run3:
	@make display
	@clear
	@echo sorting
	@./push_swap.out 500 11500

run4:
	@make display
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
	@norminette includes/push_swap.h $(SRC)
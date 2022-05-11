# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgobbett <jgobbett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 13:29:03 by jgobbett          #+#    #+#              #
#    Updated: 2022/05/11 17:28:16 by jgobbett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC = includes
SRC = src/*.c
SRCD = src_display/*.c
INCS = -I$(INC)
FLAGS = -Wall -Wextra -Werror
NAME = push_swap
ARG3 = 2 1 0
ARG5 = 1 5 2 4 3
ARG100 = -31 -39 13 19 -40 11 -12 -45 -32 48 -6 -9 8 22 23 2 -37 10 44 47 41 -1 35 -47 -43 -14 -33 -21 28 -3 -10 0 -46 -19 -42 -28 -25 49 -41 -30 50 43 45 -34 6 -49 12 20 9 -23 -22 -4 33 17 -5 32 42 -15 -8 4 30 -18 -38 -13 38 -26 -17 -50 36 31 39 7 25 24 -20 27 -29 -7 46 -2 18 -36 -48 -44 -35 5 15 3 16 37 40 26 14 -16 -27 29 34 1 21 -11
ARG500 = 67 -539 387 -532 247 -408 -901 -269 551 128 480 -272 312 -47 -483 -184 241 127 -394 -776 628 -710 -880 -238 556 -692 91 679 614 -6 696 655 506 -190 61 -424 -201 -732 -854 -634 382 -581 105 621 737 -53 -995 -476 586 413 882 313 378 -502 -668 377 -912 439 -729 198 989 623 -656 340 -404 -862 -615 283 669 847 507 -45 -154 -881 -458 408 218 608 25 -250 405 252 -761 259 566 -375 495 -99 764 -746 -134 -872 643 533 -921 175 -542 772 -933 -16 -534 565 510 -752 173 -598 -145 -312 821 2 -146 12 -856 58 -936 -391 -630 -200 269 -256 -662 618 103 231 -584 -266 211 -629 60 -704 310 685 180 -179 597 -549 266 -799 754 -650 -977 459 -758 -97 -481 -378 -428 -716 875 639 -844 -544 206 150 381 910 527 -993 945 -380 403 212 446 299 107 -623 486 -164 169 735 593 -789 -813 600 957 -702 844 930 -675 -83 45 203 500 -398 -955 681 978 -101 -770 9 -768 81 -307 26 -915 -521 -274 -117 570 117 -223 160 -877 364 -420 -595 407 -402 220 692 33 -321 -187 -490 394 -22 990 287 917 918 328 -158 -749 815 -434 626 944 983 813 -302 20 38 -791 -701 324 890 -213 864 -335 -518 -627 -237 905 -86 361 723 -341 -932 -767 767 -814 37 -303 3 808 -130 -189 -133 222 -935 -906 124 -616 19 662 142 860 743 -369 560 904 791 153 504 667 400 -388 437 557 -555 -358 335 -523 -717 -137 903 -510 197 -831 -600 969 323 493 -379 991 635 409 961 -859 416 43 775 891 294 -614 581 -366 -283 452 44 143 162 -289 -191 -495 683 -689 358 -781 -647 -504 -85 -325 665 428 227 -447 309 777 641 -659 388 610 -676 -364 911 494 -435 -26 373 -28 185 -361 682 919 -326 587 243 768 55 727 -946 603 -501 -513 264 627 -777 345 -517 580 140 -735 757 -261 822 -75 -693 456 -316 -322 -543 -173 -315 732 -695 -564 935 -496 -416 -320 629 476 976 465 163 885 29 239 624 308 -29 228 -980 -437 971 975 383 824 -694 -551 278 673 578 129 270 962 -665 -171 498 749 -40 306 -257 -896 -297 -354 7 -288 -507 -731 170 915 477 928 434 -667 -556 485 906 483 427 64 582 861 -678 960 552 -885 157 -505 943 366 -228 -802 85 302 -386 401 393 -484 16 -306 -707 908 392 -79 -599 -779 -430 419 -5 -983 351 712 -887 -836 -573 151 -588 -170 -491 922 -825 642 101 201 -804 147 -718 -498 913 -724 -889 -78 980 -966 753 511 956 878 986 539 -410 713 644 -907 344 -121 -27
ARG = 5 4 3 2 1 5555555555555555

all:
	@clear
	@echo -n Compiling push_swap...
	@gcc $(SRC) $(INCS) $(FLAGS) -o $(NAME)
	@echo Done

eval:
	@clear
	@make
	@./push_swap $(ARG) | ./checker_Mac $(ARG)

testp:
	@make
	@clear
	@echo "max ?" 
	@read PMAX; \
	python3 pyviz.py `ruby -e "puts (1..$$PMAX).to_a.shuffle.join(' ')"`;

display:
	@clear
	@echo -n Compiling push_swap...
	@gcc $(SRCD) $(INCS) $(FLAGS) -o $(NAME)
	@echo Done

test:
	@make display
	@clear
	@./push_swap $(ARG)

test100:
	@clear
	@./push_swap $(ARG100)

test500:
	@clear
	@./push_swap $(ARG500)

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
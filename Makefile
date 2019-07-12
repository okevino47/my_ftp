##
## EPITECH PROJECT, 2018
## nm objdump
## File description:
## makefile
##

CC		=	gcc -g3

RM		=	rm -rf

SERVER_NAME	=	server

TEST_NAME	=	tests_run

SERVER_MAIN_SRC	=	./server_folder/src/main.c

SERVER_GEN_SRC	=	./server_folder/src/connexion_creation.c	\
			./server_folder/src/connexion_destruction.c	\
			./server_folder/src/server_behavior.c		\
			./server_folder/src/client_handle.c		\
			./server_folder/src/check_error.c		\
			./server_folder/src/display_help.c		\
			./server_folder/src/various_check.c		\
			./server_folder/src/init_function.c		\
			./server_folder/src/destroy_ressources.c	\
			./server_folder/src/my_str_to_wordtab.c		\
			./server_folder/src/login_function.c		\
			./server_folder/src/noop_function.c		\
			./server_folder/src/displace_function.c		\
			./server_folder/src/listing_function.c		\
			./server_folder/src/quit_function.c		\
			./server_folder/src/delete_function.c		\
			./server_folder/src/store_function.c		\
			./server_folder/src/passif_transfert.c

TEST_GEN_SRC	=	./tests/outputs.c

SERVER_MAIN_OBJ	=	$(SERVER_MAIN_SRC:.c=.o)

SERVER_GEN_OBJ	=	$(SERVER_GEN_SRC:.c=.o)

TEST_GEN_OBJ	=	$(TEST_GEN_SRC:.c=.o)

TEST_FILES	=	./server_folder/src/*.gcno ./server_folder/src/*.gcda ./tests/*.gcno ./tests/*.gcda *.gcov

CFLAGS		+=	-I ./server_folder/includes/ -I ./commons/includes/
CFLAGS		+=	-W -Wall -Wextra
CFLAGS		+=	-fprofile-arcs -ftest-coverage

LDFLAGS		+=	-lcriterion -lgcov --coverage

all:			$(SERVER_NAME)

$(SERVER_NAME):			$(SERVER_MAIN_OBJ) $(SERVER_GEN_OBJ)
			$(CC) -o $(SERVER_NAME) $(SERVER_MAIN_OBJ) $(SERVER_GEN_OBJ) $(LDFLAGS)

tests_run:			$(TEST_GEN_OBJ) $(SERVER_GEN_OBJ)
			$(CC) -o $(TEST_NAME) $(TEST_GEN_OBJ) $(SERVER_GEN_OBJ) $(LDFLAGS)
			./tests_run
			gcov ./server_folder/src/*.gcda

clean:
			$(RM) $(TEST_GEN_OBJ) $(SERVER_GEN_OBJ) $(SERVER_MAIN_OBJ) $(TEST_FILES)

fclean:			clean
			$(RM) $(SERVER_NAME) $(TEST_NAME)

re:			fclean all

go:			re
			$(RM) $(TEST_GEN_OBJ) $(SERVER_GEN_OBJ) $(SERVER_MAIN_OBJ) $(TEST_FILES)

.PHONY: 		all clean fclean re go

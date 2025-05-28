NAME   =  7480203_MA_01_01
CC     =  gcc
LIBS   = -lm
CFLAGS = -g -Wall -I.

all: compile run

compile: 
	$(CC) -o $(NAME) $(NAME).c $(LIBS) $(CFLAGS)
run: 
	./$(NAME)

.PHONY: clean
clean:
	rm $(NAME)

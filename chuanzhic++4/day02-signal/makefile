.PHONY:clean all
CC=gcc
CFLAGS=-Wall -g
BIN=dm01_signal dm02_signal
all:$(BIN)
%.o:%.c 
	$(CC) $(CFLAGS) -c $< -o $@
clean: 
	rm -f *.o $(BIN)




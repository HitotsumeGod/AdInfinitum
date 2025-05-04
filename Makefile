CC=gcc
SRC=src/main
DEPS=src/headers

pilot: $(SRC)/pilot.c $(SRC)/uni.c $(SRC)/fsp.c
	$(CC) -o $@ $^ -I $(DEPS) -g 
clean:
	rm -f pilot

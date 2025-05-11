CC=gcc
SRC=src/main
DEPS=src/headers

pilot: $(SRC)/pilot.c $(SRC)/uni.c $(SRC)/fsp.c $(SRC)/query.c $(SRC)/get.c $(SRC)/create.c $(SRC)/write.c
	$(CC) -o $@ $^ -I $(DEPS) -g 
clean:
	rm -f pilot
	rm -f vgcore.*

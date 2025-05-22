CC=gcc
DBG=valgrind
SRC=src/main
DEPS=src/headers
BUILD=build
SRS=$(SRC)/pilot.c $(SRC)/uni.c $(SRC)/fsp.c $(SRC)/query.c $(SRC)/get.c $(SRC)/create.c $(SRC)/write.c

$(BUILD)/pilot: $(SRS) $(BUILD)
	$(CC) -o $@ $(SRS) -I $(DEPS) -g 
debug: $(BUILD)/pilot
	$(DBG) --leak-check=full --show-leak-kinds=all --track-origins=yes -s $<
$(BUILD):
	if ! [ -d $@ ]; then		\
		mkdir $@;		\
	fi
clean:
	rm -rf $(BUILD)
	rm -f vgcore.*

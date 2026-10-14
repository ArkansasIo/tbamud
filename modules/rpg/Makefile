CC ?= cc
CFLAGS ?= -O2
STRICT = -std=c99 -Wall -Wextra -Werror -pedantic
.PHONY: all test clean
all: test_rpg_core test_text_world
test_rpg_core: rpg_core.c rpg_core.h test_rpg_core.c
	$(CC) $(CFLAGS) $(STRICT) rpg_core.c test_rpg_core.c -o $@
test_text_world: text_world.c text_world.h test_text_world.c
	$(CC) $(CFLAGS) $(STRICT) text_world.c test_text_world.c -o $@
test: all
	./test_rpg_core
	./test_text_world
clean:
	rm -f test_rpg_core test_text_world

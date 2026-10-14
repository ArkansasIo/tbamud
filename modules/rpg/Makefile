CC ?= cc
CFLAGS ?= -O2
STRICT = -std=c99 -Wall -Wextra -Werror -pedantic
.PHONY: all test clean
all: test_rpg_core
test_rpg_core: rpg_core.c rpg_core.h test_rpg_core.c
	$(CC) $(CFLAGS) $(STRICT) rpg_core.c test_rpg_core.c -o $@
test: test_rpg_core
	./test_rpg_core
clean:
	rm -f test_rpg_core

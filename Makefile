CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
BIN_DIR = bin
DEMO_DIR = demos
TEST_DIR = tests

.PHONY: all clean test valgrind demo-linked_list demo-stack demo-queue demo-bst

all: $(BIN_DIR) $(OBJ)
	@echo "Build complete. Use make demo-<module> to build demos."

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

demo-linked_list: $(BIN_DIR)
	$(CC) $(CFLAGS) demos/demo_linked_list.c src/linked_list.c -o $(BIN_DIR)/demo_linked_list

demo-stack: $(BIN_DIR)
	$(CC) $(CFLAGS) demos/demo_stack.c src/stack_linked.c src/stack_array.c -o $(BIN_DIR)/demo_stack

demo-queue: $(BIN_DIR)
	$(CC) $(CFLAGS) demos/demo_queue.c src/queue_circular.c src/queue_linked.c -o $(BIN_DIR)/demo_queue

demo-bst: $(BIN_DIR)
	$(CC) $(CFLAGS) demos/demo_bst.c src/bst.c -o $(BIN_DIR)/demo_bst

clean:
	rm -rf $(BIN_DIR) *.o src/*.o

valgrind:
ifndef DEMO
	$(error DEMO is not set. Usage: make valgrind DEMO=linked_list)
endif
	./valgrind.sh $(DEMO)

test:
	@echo "Running tests in tests/ (if configured)"
	bash tests/run_tests.sh

CC := g++
CFLAGS := -O1 -Wall -g -fsanitize=address



lab9_prog.exe: matrix.o main.o
	# fill in commands here
	$(CC) $(CFLAGS) $^ -o $@

%.exe: %.c
	$(CC) $(CFLAGS) $< -c

.PHONY: clean
clean:
	rm -f *.exe
	rm -f lab9_prog.exe
# ***
# *** Do NOT modify this file
# ***

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c11 -g $(WARNING) $(ERROR) 

SRCS = practica_b.c
OBJS = $(SRCS:%.c=%.o) main_b.o

%.o: %.c
	$(GCC) -c $< -o $@

practica: $(OBJS) 
	$(GCC) $(OBJS) -o practica

testall: test1 test2 test3 test4 test5 test6 test7 test8 test9 test10

test%: practica
	./practica $@

leak: practica
	valgrind --leak-check=full --show-leak-kinds=all ./practica test10

clean:
	rm -rf practica_b.o practica

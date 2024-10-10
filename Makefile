# ***
# *** You can modify this file. You do not (should not) submit this file
# ***

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c11 -g $(WARNING) $(ERROR) 
VAL = valgrind --tool=memcheck --log-file=vallog --leak-check=full --verbose

SRCS = dtw.c main.c
OBJS = $(SRCS:%.c=%.o)

hw20: $(OBJS)
	$(GCC) $(OBJS) -o hw20

.c.o:
	$(GCC) -c $*.c

test1: hw20
	./hw20 inputs/alphabet1.txt inputs/alphabet2.txt inputs/alphabet3.txt inputs/alphabet4.txt CHAR > outputs/output1.txt
	diff outputs/output1.txt expected/expected1.txt

test2: hw20
	./hw20 inputs/numbers1.txt inputs/numbers2.txt inputs/numbers3.txt inputs/numbers4.txt INT > outputs/output2.txt
	diff outputs/output2.txt expected/expected2.txt

test3: hw20
	./hw20 inputs/poem1.txt inputs/poem2.txt inputs/poem3.txt inputs/poem4.txt STRING > outputs/output3.txt

memory: hw20
	$(VAL) ./hw20 inputs/alphabet1.txt inputs/alphabet2.txt inputs/alphabet3.txt inputs/alphabet4.txt CHAR > outputs/output1.txt

clean:
	rm -f hw20 *.o outputs/*.txt vallog *bin

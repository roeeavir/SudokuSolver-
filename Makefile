CC=gcc
OBJS=general.o CheckNumbers.o tickets.o  sudoku.o main.o -lm
EXEC=Avoda1
DEBUG = -g
CFLAGS = -std=c99  -Wall -Werror $(DEBUG)  #if you have CFLAGS you do not have to write for each file $(CC) -c $*.c!!!

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $@


general.o: general.c general.h
CheckNUmbers.o: CheckNumbers.c CHeckNumbers.h general.h 
tickets.o: tickets.c tickets.h general.h 
sudoku.o: sudoku.c sudoku.h general.h 
main.o: sudoku.h CheckNumbers.h tickets.h main.c


clean: 
	rm -f $(EXEC) $(OBJS)
	

CC := gcc
OBJ := main.o \
			 maxsumv.o \
			 maxsumh.o \
			 maxsuma.o \
			 maxsumvh.o \
			 maxsumhv.o
CFLAG := -fprofile-arcs -ftest-coverage
LDFLAG := -fprofile-arcs -ftest-coverage -lgcov
OPTFLAG :=

run : $(OBJ)
	$(CC) $(LDFLAG) $(OPTFLAG) -o run $(OBJ)

maxsumhv.o : maxsumhv.c main.h
	$(CC) -c $(CFLAG) $(OPTFLAG) maxsumhv.c

maxsumvh.o : maxsumvh.c main.h
	$(CC) -c $(CFLAG) $(OPTFLAG) maxsumvh.c

maxsuma.o : maxsuma.c main.h
	$(CC) -c $(CFLAG) $(OPTFLAG) maxsuma.c

maxsumh.o : maxsumh.c main.h
	$(CC) -c $(CFLAG) $(OPTFLAG) maxsumh.c

maxsumv.o : maxsumv.c main.h
	$(CC) -c $(CFLAG) $(OPTFLAG) maxsumv.c

main.o : main.c main.h
	$(CC) -c $(CFLAG) $(OPTFLAG) main.c

clean :
	rm $(OBJ) run

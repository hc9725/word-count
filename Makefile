mwc: mwc.o  getword.o   dbllink.o \
 getwordstdin.o wordinsert.o 
	gcc  -O2 -o  mwc mwc.o getword.o  dbllink.o\
 getwordstdin.o  wordinsert.o 
mwc.o: mwc.c getword.h wordcount.h dbllink.h getwordstdin.h
	gcc -O2 -c  mwc.c 
getword.o:  getword.c dbllink.h wordinsert.h
	gcc  -O2 -c getword.c  
getwordstdin.o:dbllink.h wordinsert.h
	gcc  -O2 -c getwordstdin.c 
dbllink.o: dbllink.c dbllink.h
	gcc  -O2  -c dbllink.c 
wordinsert.o: wordinsert.c wordinsert.h dbllink.h
	gcc  -O2 -c wordinsert.c 
.PHONY: clean

clean:
	rm -f *.o 

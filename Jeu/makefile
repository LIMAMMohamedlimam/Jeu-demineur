all: demineur
	./demineur

debg:
	gdb ./demineurdebg



demineurdebg: main.c demineur.c
	gcc -g -o demineur main.c demineur.c 



demineur: main.o demineur.o 
	gcc  main.o demineur.o -o demineur -lm

.o: main.c demineur.c 
	gcc -c main.c demineur.c


.PHONY :clean

clean :	
	rm -f *.o
	rm -f *.*~
	rm -f *.bak
	rm -f *.old
	rm -f demineur
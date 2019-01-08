all: main carbon ackermann newton

main: main.c
	gcc -Wall -ansi -pedantic -std=c99 -c main.c -o main.o

carbon: carbon.c main.c
	gcc -Wall -ansi -pedantic -std=c99 -c carbon.c -o carbon.o
	gcc -Wall -ansi -pedantic -std=c99 -include main.o carbon.o -o carbon

ackermann: ackermann.c main.c
	gcc -Wall -ansi -pedantic -std=c99 -c ackermann.c -o ackermann.o
	gcc -Wall -ansi -pedantic -std=c99 -include main.o ackermann.o -o ackermann

newton: newton.c main.c
	gcc -Wall -ansi -pedantic -std=c99 -c newton.c -o newton.o
	gcc -Wall -ansi -pedantic -std=c99 -include main.o newton.o -o newton

clean:
	rm -f *.o ackermann carbon main all

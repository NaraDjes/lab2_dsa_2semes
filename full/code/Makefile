
ex1: ex1.o libbstree.a libhashtab.a
	gcc -Wall ex1.o libbstree.a libhashtab.a -o ex1
ex1.o: ex1.c
	gcc -c -Wall ex1.c -o ex1.o

ex4: ex4.o libbstree.a libhashtab.a
	gcc -Wall ex4.o libbstree.a libhashtab.a -o ex4
ex4.o: ex4.c
	gcc -c -Wall ex4.c -o ex4.o

ex6: ex6.o libbstree.a libhashtab.a
	gcc -Wall ex6.o libbstree.a libhashtab.a -o ex6
ex6.o: ex6.c
	gcc -c -Wall ex6.c -o ex6.o	

bstree.o: bstree.c
	gcc -c -Wall bstree.c -o bstree.o
libbstree.a: bstree.o
	ar rcs $@ $^

hashtab.o: hashtab.c
	gcc -c -Wall hashtab.c -o hashtab.o
libhashtab.a: hashtab.o
	ar rcs $@ $^

clean:
	rm -rf  bstree.o libbstree.a hashtab.o libhashtab.a ex1.o ex1 ex4 ex4.o ex6.o ex6

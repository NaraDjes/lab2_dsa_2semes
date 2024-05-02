exp1: libbstree.a libhashtab.a exp1.o
	gcc -Wall exp1.o libbstree.a libhashtab.a -o exp1
exp1.o: main.c
	gcc -c -Wall main.c -o exp1.o

bstree.o: bstree.c
	gcc -c -Wall bstree.c -o bstree.o
libbstree.a: bstree.o
	ar rcs $@ $^

hashtab.o: hashtab.c
	gcc -c -Wall hashtab.c -o hashtab.o
libhashtab.a: hashtab.o
	ar rcs $@ $^

clean:
	rm -rf  bstree.o libbstree.a hashtab.o libhashtab.a exp1.o exp1


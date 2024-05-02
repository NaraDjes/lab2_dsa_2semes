exp4:libbstree.a libhashtab.a exp4.o
	gcc -Wall exp4.o libbstree.a libhashtab.a -o exp4 -g
exp4.o: main.c
	gcc -c -Wall main.c -o exp4.o

bstree.o: bstree.c
	gcc -c -Wall bstree.c -o bstree.o
libbstree.a: bstree.o
	ar rcs $@ $^

hashtab.o: hashtab.c
	gcc -c -Wall hashtab.c -o hashtab.o
libhashtab.a: hashtab.o
	ar rcs $@ $^

clean:
	rm -rf  bstree.o libbstree.a hashtab.o libhashtab.a exp4 exp4.o

exp6:libbstree.a libhashtab.a exp6.o
	gcc -Wall exp6.o libbstree.a libhashtab.a -o exp6
exp6.o: main.c
	gcc -c -Wall main.c -o exp6.o	

bstree.o: bstree.c
	gcc -c -Wall bstree.c -o bstree.o
libbstree.a: bstree.o
	ar rcs $@ $^

hashtab.o: hashtab.c
	gcc -c -Wall hashtab.c -o hashtab.o
libhashtab.a: hashtab.o
	ar rcs $@ $^

clean:
	rm -rf  bstree.o libbstree.a hashtab.o libhashtab.a exp6.o exp6

CC=gcc
CFLAGS=Wall

all: foo vis

foo: main.o graph_adj_mat.o
	$(CC) -o foo graph_adj_mat.o main.o

main.o: main.c
	$(CC) -c -$(CFLAGS) main.c

graph_adj_mat.o: graph_adj_mat.c
	$(CC) -c -$(CFLAGS) graph_adj_mat.c

vis: foo.exe
	foo.exe | dot -Tpdf > graph.pdf

clean :
	del *.o foo.exe
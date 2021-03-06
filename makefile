CC = gcc
CFLAGS = -std=c99 -Wall -pedantic

all: ttt1.o ttt2.o alphatoe show_node count_nodes

ttt1.o: ttt1.c ttt.h
	$(CC) $(CFLAGS) -c ttt1.c -o ttt1.o

ttt2.o: ttt2.c ttt.h
	$(CC) $(CFLAGS) -c ttt2.c -o ttt2.o

alphatoe.o: alphatoe.c ttt.h
	$(CC) $(CFLAGS) -c alphatoe.c -o alphatoe.o
alphatoe: alphatoe.o ttt1.o ttt2.o
	$(CC) $(CFLAGS) alphatoe.o ttt1.o ttt2.o -o alphatoe

show_node.o: show_node.c ttt.h
	$(CC) $(CFLAGS) -c show_node.c -o show_node.o
show_node: show_node.o ttt1.o ttt2.o
	$(CC) $(CFLAGS) show_node.o ttt1.o ttt2.o -o show_node

count_nodes.o: count_nodes.c ttt.h
	$(CC) $(CFLAGS) -c count_nodes.c -o count_nodes.o
count_nodes: count_nodes.o ttt1.o ttt2.o
	$(CC) $(CFLAGS) count_nodes.o ttt1.o ttt2.o -o count_nodes

clean:
	rm -i *.o alphatoe show_node count_nodes
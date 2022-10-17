CFLAGS=-Wall -pedantic -std=c99

all: ttt1.o ttt2.o count_nodes alphatoe show_node

ttt1.o: ttt.h
	cc $(CFLAGS) -c -o ttt1.o ttt1.c
	
ttt2.o: ttt.h
	cc $(CFLAGS) -c -o ttt2.o ttt2.c

alphatoe: alphatoe.c
	gcc ttt1.c ttt2.c alphatoe.c -o alphatoe $(CFLAGS)

count_nodes: count_nodes.c
	gcc ttt1.c ttt2.c count_nodes.c -o count_nodes $(CFLAGS)

show_node: show_node.c
	gcc ttt1.c ttt2.c show_node.c -o show_node $(CFLAGS)

clean:
	rm -f *~ *.o alphatoe count_nodes show_node

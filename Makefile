CC=gcc
CFLAGS=-g
TARGET=connect4
OBJS=main.o ai_rule.o ai_search.o tree_structure.o

all: $(TARGET)

clean:
	rm -f *.o $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

main.o: ai_header.h main.c
ai_rule.o: ai_header.h ai_rule.c
ai_search.o: ai_header.h ai_search.c
tree_structure.o: ai_header.h tree_structure.c

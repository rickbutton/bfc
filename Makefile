OBJ = bfc.c
TARGET = bfc

all: run

$(TARGET): $(OBJ)
	gcc $< -o $@

example: $(TARGET) example.bf
	./bfc example.bf example.c
	gcc example.c -o example

run: example
	./example

clean:
	rm -rf $(TARGET) example.c

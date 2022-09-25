CFLAGS=-g
OBJS = uimain.o tokenizer.o history.o

all: proj1

proj1: ${OBJS}
	cc -o $@ $(CFLAGS) $(OBJS)

$(OBJS): tokenizer.h history.h

clean:
	rm -f *.o proj1

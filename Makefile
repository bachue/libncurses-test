CC = gcc
CFLAGS = -O0 -g -Wall
LIBS = -lpanel -lncurses -lmenu
SRCS = $(wildcard *.c)
BUILDDIR = build/
EXES = $(addprefix $(BUILDDIR), $(SRCS:.c=))

.PHONY: all clean

all: $(EXES)

$(BUILDDIR)%: %.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	$(RM) $(EXES)

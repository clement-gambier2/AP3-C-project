CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11
LIBS = -lSDL2 -lSDL2_ttf


SRCDIR = src
OBJDIR = obj
BINDIR = bin

GAME_SRCS = $(wildcard $(SRCDIR)/game/*.c)
GAME_OBJS = $(patsubst $(SRCDIR)/game/%.c,$(OBJDIR)/game/%.o,$(GAME_SRCS))

MAIN_SRCS = $(wildcard $(SRCDIR)/*.c)
MAIN_OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(MAIN_SRCS))

TARGET = $(BINDIR)/main

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(GAME_OBJS) $(MAIN_OBJS)
	$(CC) $(CFLAGS) $(GAME_OBJS) $(MAIN_OBJS) -o $(TARGET) $(LIBS)

$(OBJDIR)/game/%.o: $(SRCDIR)/game/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)/* $(TARGET)


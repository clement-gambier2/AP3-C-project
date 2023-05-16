CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11
LIBS = -lSDL2 -lSDL2_ttf


SRCDIR = src
OBJDIR = obj
BINDIR = bin

CHARACTER_SRCS = $(wildcard $(SRCDIR)/character/*.c)
CHARACTER_OBJS = $(patsubst $(SRCDIR)/character/%.c,$(OBJDIR)/character/%.o,$(CHARACTER_SRCS))

COMBAT_SRCS = $(wildcard $(SRCDIR)/combat/*.c)
COMBAT_OBJS = $(patsubst $(SRCDIR)/combat/%.c,$(OBJDIR)/combat/%.o,$(COMBAT_SRCS))

GAME_SRCS = $(wildcard $(SRCDIR)/game/*.c)
GAME_OBJS = $(patsubst $(SRCDIR)/game/%.c,$(OBJDIR)/game/%.o,$(GAME_SRCS))

MAP_SRCS = $(wildcard $(SRCDIR)/map/*.c)
MAP_OBJS = $(patsubst $(SRCDIR)/map/%.c,$(OBJDIR)/map/%.o,$(MAP_SRCS))

MAIN_SRCS = $(wildcard $(SRCDIR)/*.c)
MAIN_OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(MAIN_SRCS))

TARGET = $(BINDIR)/main

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(GAME_OBJS) $(CHARACTER_OBJS) $(COMBAT_OBJS) $(MAP_OBJS) $(MAIN_OBJS)
	$(CC) $(CFLAGS) $(GAME_OBJS) $(CHARACTER_OBJS) $(COMBAT_OBJS) $(MAP_OBJS) $(MAIN_OBJS) -o $(TARGET) $(LIBS)

$(OBJDIR)/game/%.o: $(SRCDIR)/game/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/character/%.o: $(SRCDIR)/character/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/combat/%.o: $(SRCDIR)/combat/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/map/%.o: $(SRCDIR)/map/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)/* $(TARGET)


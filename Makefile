TARGET := tp_P3
LIBS := -lm
CFLAGS := -Wall -g -std=c++11
OBJDIR := obj/
SRCDIR := src/
INCLUDEDIR := include/
INCLUDE_PATHS := -Iinclude
CLI := client/main.cpp
CC := g++

all: $(TARGET)

SRC = $(wildcard $(SRCDIR)*.cpp)
HEADERS = $(wildcard $(INCLUDEDIR)*.h)

CLIENT = $(OBJDIR)$(basename $(notdir $(CLI)))

OBJECTS := $(SRC:$(SRCDIR)%.cpp=$(OBJDIR)%.o)
OBJECTS += $(CLIENT).o

$(OBJDIR)%.o: $(SRCDIR)%.cpp $(HEADERS)
	@ mkdir -p $(OBJDIR)
	$(CC) $(INCLUDE_PATHS) $(CFLAGS) -c -o $@ $<

$(CLIENT).o: $(CLI)
	$(CC) $(INCLUDE_PATHS) $(CFLAGS) -c -o $@ $<


$(TARGET): $(OBJECTS)
	$(CC) $(INCLUDE_PATHS) $(OBJECTS) $(LIBS) -o $@

run: $(TARGET)
	@./$(TARGET) candidatos.csv partidos.csv 15/11/2020

clean:
	-rm -f -r obj
	-rm -f *.o
	-rm -f $(TARGET)

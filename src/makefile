IDIR = ../include
CC = g++
CFLAGS = -I$(IDIR) -c -Wall
LDFLAGS =
ODIR = obj

SOURCES = main.cpp Parser.cpp Result.cpp
_OBJECTS = $(SOURCES:.cpp=.o)
OBJECTS = $(patsubst %,$(ODIR)/%,$(_OBJECTS))

_DEPS = Data.hpp Attribute.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

EXECUTABLE = main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(DEPS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

$(ODIR)/%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@


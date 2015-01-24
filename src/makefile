IDIR = ../include
CC = g++
CFLAGS = -I$(IDIR) -c -Wall
LDFLAGS =
ODIR = obj

SOURCES = main.cpp Parser.cpp VResult.cpp
_OBJECTS = $(SOURCES:.cpp=.o)
OBJECTS = $(patsubst %,$(ODIR)/%,$(_OBJECTS))

_DEPS = IResult.hpp VResult.hpp Data.hpp Attribute.hpp Parser.hpp ParseTree.hpp ParseTreeResult.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

EXECUTABLE = main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(DEPS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) $< -o $@


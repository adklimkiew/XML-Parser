IDIR = ../include
CC = g++
CFLAGS = -I$(IDIR) -c -Wall -Werror
LDFLAGS =
ODIR = obj

SOURCES = $(wildcard *.cpp)
_OBJECTS = $(SOURCES:.cpp=.o)
OBJECTS = $(addprefix $(ODIR)/, $(_OBJECTS))

DEPS := $(wildcard $(IDIR)/*.hpp)

all: $(OBJECTS)

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm $(OBJECTS)

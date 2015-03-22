IDIR = ../include
CC = g++
CFLAGS = -I$(IDIR) -c -Wall -Werror
LDFLAGS =
OBJDIR = obj

SOURCES = $(wildcard *.cpp)
_OBJECTS = $(SOURCES:.cpp=.o)
OBJECTS = $(addprefix $(OBJDIR)/, $(_OBJECTS))

DEPS := $(wildcard $(IDIR)/*.hpp)

all: $(OBJECTS)

$(OBJDIR)/%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm $(OBJECTS)

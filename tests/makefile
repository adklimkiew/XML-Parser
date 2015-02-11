CC = g++
IDIR = ../include
CFLAGS = -I$(IDIR) -c -Wall -Werror

EXECUTABLE = main

ODIR = ../src/obj
LIB_OBJECTS = $(addprefix $(ODIR)/, *.o)

SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

all: $(EXECUTABLE)

$(EXECUTABLE): $(LIB_OBJECTS) $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@


$(LIB_OBJECTS):
	cd ../src && $(MAKE) all

DEPS := $(wildcard $(IDIR)/*.hpp)
%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) $< -o $@


.PHONY: clean
clean:
	cd ../src && $(MAKE) clean


CC = g++
IDIR = ../include
CFLAGS = -I$(IDIR) -c -Wall -Werror

EXECUTABLE = main

ODIR = ../src/obj
LIB_OBJECTS = $(addprefix $(ODIR)/, *.o)

SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

$(EXECUTABLE): $(LIB_OBJECTS) $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@


$(LIB_OBJECTS):
	cd ../src && $(MAKE)

%.o: %.cpp #$(DEPS)
	$(CC) $(CFLAGS) $< -o $@



.PHONY: clean
clean:
	cd ../src && $(MAKE) clean


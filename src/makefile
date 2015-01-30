IDIR = ../include
CC = g++
CFLAGS = -I$(IDIR) -c -Wall -Werror
LDFLAGS =
ODIR = obj

#SOURCES = main.cpp Parser.cpp VResult.cpp TagInterpreter.cpp XmlOpeningElement.cpp XmlClosingElement.cpp XmlElementContents.cpp XmlEmptyElement.cpp
SOURCES = $(wildcard *.cpp)
_OBJECTS = $(SOURCES:.cpp=.o)
OBJECTS = $(addprefix $(ODIR)/, $(_OBJECTS))

DEPS := $(wildcard $(IDIR)/*.hpp)

EXECUTABLE = main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) #$(DEPS)
	$(CC) $(LDFLAGS) $^ -o $@

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm main.exe $(OBJECTS)

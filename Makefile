#Compiler and Linker
CC := gcc

#Target binary program
TARGET := fileSystem

#Directories, Sources, Includes, Objects, Binaries and Resources
SRCDIR := src
OBJDIR := obj
TARGETDIR := bin

#Flags, Libraries and Includes
CFLAGS := -Wall -O3 -g

#---------------------------------------------------------------------------------
#DO NOT EDIT BELOW THIS LINE
#---------------------------------------------------------------------------------

#OBJECTS := $(addprefix $(OBJDIR)/, cli_tools.o tree.o)
SOURCES := $(shell find $(SRCDIR) -name "*.c")
OBJECTS := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES))

#Default make
all: $(OBJECTS) main.c
	$(CC) $(CFLAGS) $^ -o $(TARGETDIR)/$(TARGET)

#Remake
remake: cleaner all

#Create object files
%.o: $(SRCDIR)/%.c $(SRCDIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $(OBJDIR)/$@

#Clean only objects
clean:
	rm -rf $(OBJDIR)/*

#Full clean, objects and binaries
cleaner:
	rm -rf $(TARGETDIR)/* $(OBJDIR)/*
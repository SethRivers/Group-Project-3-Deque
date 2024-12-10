 # /
 # @file Makefile
 # @author Script Sages
 # @date 2024-12-09
 # @brief The makefile of the deque assignment
 # 
 # 
 # /


#Defines the compiler
CC = g++

#Compile with all errors and warnings
CFLAGS = -g -Wall -Wextra -c

#Links the .o files together and creates an executable
TARGET = deque

#Readies $(TARGET) for use in the following code
all: $(TARGET)

#Marks all the files that will be compiled
$(TARGET):	main.o deque.o
		$(CC) main.o deque.o -o $(TARGET)

#Compiles the main.cpp file with the .h file
main.o: 	main.cpp deque.h
		$(CC) $(CFLAGS) main.cpp

#Compiles the Steganography.cpp/.h files
deque.o: 	deque.h deque.cpp
		$(CC) $(CFLAGS) deque.cpp

#Cleans out any unnecaary items post compiling.
clean:
		$(RM) *.o *~ deque

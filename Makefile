all: deque

deque: main.o deque.o
	$(CXX) -o deque main.o deque.o

main.o: main.cpp deque.h
	$(CXX) -c main.cpp

deque.o: deque.cpp deque.h
	$(CXX) -c deque.cpp

clean: rm -f deque *.o

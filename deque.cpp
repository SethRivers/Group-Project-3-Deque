#include "deque.h"
#include <iostream>

// Constructor: Initializes an empty deque
Deque::Deque() : blockmap(nullptr), numBlocks(0), blockSize(4), frontIndex(0), backIndex(0), currentSize(0) {
    allocateBlock();
}

// Destructor: Frees all dynamically allocated memory
Deque::~Deque() {
    if (blockmap != nullptr) {
        for (int i = 0; i < numBlocks; i++) {
            if (blockmap[i] != nullptr) {
                delete[] blockmap[i];
                blockmap[i] = nullptr;  // Avoid dangling pointers
            }
        }
        delete[] blockmap;
        blockmap = nullptr;
    }
}

// Allocates an initial block for the deque
void Deque::allocateBlock() {
    numBlocks = 1;
    blockmap = new int*[numBlocks];
    blockmap[0] = new int[blockSize];
    frontIndex = backIndex = blockSize / 2;  // Start in the middle for flexibility
}

// Push a value to the front of the deque
void Deque::push_front(int value) {
    if (frontIndex < 0) {
        expandBlockmap();
    }
    blockmap[0][frontIndex--] = value;
    currentSize++;
}

// Push a value to the back of the deque
void Deque::push_back(int value) {
    if (backIndex >= blockSize) {
        expandBlockmap();
    }
    blockmap[0][backIndex++] = value;
    currentSize++;
}

// Pop a value from the front of the deque
void Deque::pop_front() {
    if (currentSize == 0) {
        std::cerr << "Error: Attempt to pop from an empty deque." << std::endl;
        return;
    }
    frontIndex++;
    currentSize--;
}

// Pop a value from the back of the deque
void Deque::pop_back() {
    if (currentSize == 0) {
        std::cerr << "Error: Attempt to pop from an empty deque." << std::endl;
        return;
    }
    backIndex--;
    currentSize--;
}

// Check if the deque is empty
bool Deque::empty() const {
    return currentSize == 0;
}

// Get the current size of the deque
int Deque::size() const {
    return currentSize;
}

// Expand the blockmap when more space is needed (basic implementation)
void Deque::expandBlockmap() {
    int** newBlockmap = new int*[numBlocks + 1];
    for (int i = 0; i < numBlocks; i++) {
        newBlockmap[i] = blockmap[i];
    }
    newBlockmap[numBlocks] = new int[blockSize];
    delete[] blockmap;
    blockmap = newBlockmap;
    numBlocks++;
    frontIndex = blockSize / 2;
    backIndex = frontIndex + 1;
}

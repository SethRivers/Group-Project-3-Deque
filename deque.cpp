/**
 * @file deque.cpp
 * @author Script Sages
 * @date 2024-12-09
 * @brief This is the cpp file for the deque assignment. Here, all the processes of making the deque and managing it are handled and distributed. 
 * 
 * 
 */

#include "deque.h"
#include <iostream>

Deque::Deque() : blockmap(nullptr), numBlocks(0), blockSize(4), frontIndex(0), backIndex(0), currentSize(0) {
    allocateBlock();  // Allocate an initial block to start with
}

Deque::~Deque() {
    if (blockmap != nullptr) {
        // Iterate through all the blocks and delete each dynamically allocated array
        for (int i = 0; i < numBlocks; i++) {
            if (blockmap[i] != nullptr) {
                delete[] blockmap[i];
                blockmap[i] = nullptr;  // Avoid dangling pointers
            }
        }
        // Delete the blockmap itself and set it to nullptr
        delete[] blockmap;
        blockmap = nullptr;
    }
}

void Deque::allocateBlock() {
    numBlocks = 1;                     // Start with one block
    blockmap = new int*[numBlocks];    // Allocate space for the blockmap (array of pointers)
    blockmap[0] = new int[blockSize];  // Allocate the first block of integers

    // Set front and back indices to the middle of the block for flexibility
    frontIndex = backIndex = blockSize / 2;
}

void Deque::push_front(int value) {
    // If frontIndex is out of bounds, expand the blockmap to allocate more space
    if (frontIndex < 0) {
        expandBlockmap();
    }

    // Insert the value at the current frontIndex and decrement it
    blockmap[0][frontIndex--] = value;
    currentSize++;
}

void Deque::push_back(int value) {
    // If backIndex exceeds the block size, expand the blockmap to allocate more space
    if (backIndex >= blockSize) {
        expandBlockmap();
    }

    // Insert the value at the current backIndex and increment it
    blockmap[0][backIndex++] = value;
    currentSize++;
}

void Deque::pop_front() {
    if (currentSize == 0) {
        // Error handling: Attempt to pop from an empty deque
        std::cerr << "Error: Attempt to pop from an empty deque." << std::endl;
        return;
    }

    // Increment the frontIndex to remove the front element logically
    frontIndex++;
    currentSize--;
}

void Deque::pop_back() {
    if (currentSize == 0) {
        // Error handling: Attempt to pop from an empty deque
        std::cerr << "Error: Attempt to pop from an empty deque." << std::endl;
        return;
    }

    // Decrement the backIndex to remove the back element logically
    backIndex--;
    currentSize--;
}

bool Deque::empty() const {
    return currentSize == 0;  // Returns true if the current size is zero
}

int Deque::size() const {
    return currentSize;  // Return the number of elements currently in the deque
}

void Deque::expandBlockmap() {
    // Create a new blockmap with one more block than the current blockmap
    int** newBlockmap = new int*[numBlocks + 1];

    // Copy the existing blocks to the new blockmap
    for (int i = 0; i < numBlocks; i++) {
        newBlockmap[i] = blockmap[i];
    }

    // Allocate a new block and add it to the new blockmap
    newBlockmap[numBlocks] = new int[blockSize];

    // Free the old blockmap and replace it with the new one
    delete[] blockmap;
    blockmap = newBlockmap;

    numBlocks++;  // Update the number of blocks

    // Reset the front and back indices to the middle of the new block
    frontIndex = blockSize / 2;
    backIndex = frontIndex + 1;
}





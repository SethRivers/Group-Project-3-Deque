#ifndef DEQUE_H
#define DEQUE_H

class Deque {
private:
    int** blockmap;          // Pointer to an array of blocks
    int numBlocks;           // Number of blocks in the blockmap
    int blockSize;           // Size of each block
    int frontIndex;          // Index for the front of the deque
    int backIndex;           // Index for the back of the deque
    int currentSize;         // Number of elements currently in the deque (renamed)

    void allocateBlock();    // Allocates the initial block
    void expandBlockmap();   // Expands the blockmap when necessary

public:
    Deque();                 // Constructor
    ~Deque();                // Destructor

    void push_front(int value); // Add to the front
    void push_back(int value);  // Add to the back
    void pop_front();           // Remove from the front
    void pop_back();            // Remove from the back
    bool empty() const;         // Check if the deque is empty
    int size() const;           // Get the number of elements in the deque
};

#endif // DEQUE_H






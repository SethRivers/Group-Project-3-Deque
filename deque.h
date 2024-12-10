#ifndef DEQUE_H
#define DEQUE_H


/**
 * The Deque Class - which allows the entire system to operate and process data. 
 *
 * @class Deque deque.h "Group-Project-3-Deque/deque.h"
 * @brief This class is used to read from files, make a deque for it to store the data from the files 
 * to, and to clean/destroy the deque when everything is said and done. 
 *
 */
class Deque {
private:
    int** blockmap;          // Pointer to an array of blocks
    int numBlocks;           // Number of blocks in the blockmap
    int blockSize;           // Size of each block
    int frontIndex;          // Index for the front of the deque
    int backIndex;           // Index for the back of the deque
    int currentSize;         // Number of elements currently in the deque (renamed)


/**
 * Allocates an initial block for the deque
 *
 * @pre 
 * @return void 
 * @post 
 * 
 */
    void allocateBlock();

/**
 * Expands the blockmap when more space is needed
 *
 * @pre 
 * @return void 
 * @post 
 * 
 */
    void expandBlockmap();

public:

/**
 * The constructor for the Deque files. Will Initialize an empty que for the user. 
 *
 * @pre 
 * @post 
 * 
 */
    Deque();

/**
 * Destructor for the deque files. Will free up all of the dynamically allocated memory
 *
 * @pre 
 * @post 
 * 
 */
    ~Deque();


/**
 * Pushes a value to the front of the deque - adding it as a result
 *
 * @param int value - what will be pushed
 * @pre 
 * @return void 
 * @post 
 * 
 */
    void push_front(int value);

/**
 * Pushes a value to the back of the deque - adding it as a result
 *
 * @param int value - what will be pushed
 * @pre 
 * @return void 
 * @post 
 * 
 */
    void push_back(int value);

/**
 * Pops a value from the front of the deque - removing it 
 *
 * @pre 
 * @return void 
 * @post 
 * 
 */
    void pop_front();

/**
 * Pops a value from the back of the deque - removing it. 
 *
 * @pre 
 * @return void 
 * @post 
 * 
 */
    void pop_back();

/**
 * Will check if the deque is emoty or not
 *
 * @pre 
 * @return bool - the confirmation 
 * @post 
 * 
 */
    bool empty() const;

/**
 * will get the current size of the deque for the user to see. 
 *
 * @pre 
 * @return int - the deque size
 * @post 
 * 
 */
    int size() const;
};

#endif // DEQUE_H






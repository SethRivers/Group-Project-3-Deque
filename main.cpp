#include "deque.h"
#include <iostream>
#include <fstream>
#include <string>

// Function to read numbers from a file and perform operations on the deque
void processFile(const std::string& filename, Deque& dq) {
    std::ifstream file(filename);  // Open the file for reading
    if (!file.is_open()) {
        // If the file cannot be opened, print an error message and return
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    int value;
    bool toggle = true;  // Toggle to alternate between push_front and push_back

    // Read numbers from the file and insert them into the deque
    while (file >> value) {
        if (toggle) {
            // Push the value to the front of the deque
            dq.push_front(value);
            std::cout << "Pushed " << value << " to the front." << std::endl;
        } else {
            // Push the value to the back of the deque
            dq.push_back(value);
            std::cout << "Pushed " << value << " to the back." << std::endl;
        }
        toggle = !toggle;  // Alternate between front and back for each push
    }

    std::cout << "\nFinished reading numbers from the file." << std::endl;

    // Display the current size of the deque and whether it is empty
    std::cout << "Deque size: " << dq.size() << std::endl;
    std::cout << "Is deque empty? " << (dq.empty() ? "Yes" : "No") << std::endl;

    // Pop elements alternately from the front and back until the deque is empty
    toggle = true;  // Reset the toggle to alternate between pop_front and pop_back
    while (!dq.empty()) {
        if (toggle) {
            // Pop a value from the front of the deque
            std::cout << "Popped from the front." << std::endl;
            dq.pop_front();
        } else {
            // Pop a value from the back of the deque
            std::cout << "Popped from the back." << std::endl;
            dq.pop_back();
        }
        // Display the deque size after each pop
        std::cout << "Size after pop: " << dq.size() << std::endl;
        toggle = !toggle;  // Alternate between front and back for each pop
    }

    std::cout << "Deque is now empty." << std::endl;

    file.close();  // Close the file
}

int main() {
    Deque dq;             // Create an instance of the Deque
    std::string filename; // Variable to store the filename

    // Prompt the user to enter the filename
    std::cout << "Enter the filename: ";
    std::cin >> filename;

    // Call the function to process the file and perform deque operations
    processFile(filename, dq);

    return 0;  // Indicate that the program finished successfully
}






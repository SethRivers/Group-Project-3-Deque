#include "deque.h"
#include <iostream>
#include <fstream>
#include <string>

void processFile(const std::string& filename, Deque& dq) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    int value;
    bool toggle = true;  // To alternate between push_front and push_back

    // Read numbers from the file and insert them into the deque
    while (file >> value) {
        if (toggle) {
            dq.push_front(value);
            std::cout << "Pushed " << value << " to the front." << std::endl;
        } else {
            dq.push_back(value);
            std::cout << "Pushed " << value << " to the back." << std::endl;
        }
        toggle = !toggle;
    }

    std::cout << "\nFinished reading numbers from the file." << std::endl;

    std::cout << "Deque size: " << dq.size() << std::endl;
    std::cout << "Is deque empty? " << (dq.empty() ? "Yes" : "No") << std::endl;

    // Demonstrate popping alternately from the front and back until the deque is empty
    toggle = true;  // To alternate between pop_front and pop_back
    while (!dq.empty()) {
        if (toggle) {
            std::cout << "Popped from the front." << std::endl;
            dq.pop_front();
        } else {
            std::cout << "Popped from the back." << std::endl;
            dq.pop_back();
        }
        std::cout << "Size after pop: " << dq.size() << std::endl;
        toggle = !toggle;
    }

    std::cout << "Deque is now empty." << std::endl;

    file.close();
}

int main() {
    Deque dq;
    std::string filename;

    std::cout << "Enter the filename: ";
    std::cin >> filename;

    processFile(filename, dq);

    return 0;
}

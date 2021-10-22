#include <iostream>

int main(int argc, char* argv[]) {
    // Get filename
    if (argc == 2){
        std::cout << "INFO: Translating " << argv[1] << std::endl;
    }
    else {
        std::cout << "ERROR: Incorrect usage, expected a .hack file." << std::endl;
    }

    return 0;
}
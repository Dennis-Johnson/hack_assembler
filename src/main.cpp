#include <iostream>
#include "../includes/parser.hpp"

int main(int argc, char* argv[]) {
    // Get filename
    if (argc == 2){
        std::cout << "INFO: Translating file: " << argv[1] << std::endl;
    }
    else {
        std::cout << "ERROR: Incorrect usage, expected a .hack file." << std::endl;
    }

    Parser parser = Parser("FilePath");

    return 0;
}
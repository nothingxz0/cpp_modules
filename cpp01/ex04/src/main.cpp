#include <fstream>
#include <string>
#include <iostream>

int main(int ac, char **av) {
    if (ac != 4) {
        std::cout << "Expected input: ./replace <fileName> <s1> <s2>" << std::endl;
        return (1);
    }
    std::string fileName(av[1]), s1(av[2]), s2(av[3]), line;
    std::ifstream inFile(fileName.c_str());
    if (!inFile.is_open()) {
        std::cout << "Could not open the file for reading" << std::endl;
        return (1);
    }
    std::ofstream outFile((fileName + ".replace").c_str());
    if (!outFile.is_open()) {
        std::cout << "Could not open the file for writing" << std::endl;
        return (1);
    }
    size_t pos;
    while (std::getline(inFile, line)) {
       pos = 0;
       while ((pos = line.find(s1, pos)) != std::string::npos) {
            std::string before = line.substr(0, pos);
            std::string after = line.substr(pos + s1.length());
            line = before + s2 + after;
            pos += s2.length();
       }
        outFile << line << std::endl;
    }
    return (0);
}
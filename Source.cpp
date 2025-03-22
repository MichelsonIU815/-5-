#include <iostream>
#include <algorithm>
#include <vector>
#include<algorithm>
#include <fstream>
#include<unordered_set>
#include<set>
#include"student.h"
int main() {
    student _temp;
    std::set<student>_set;
    std::unordered_set<student, hash_student>_unordered_set;
    //std::cout << _set.size() << std::endl;
    std::ifstream _fileinput;
    std::ofstream _fileoutput;
    _fileinput.open("test.txt");
    if (!_fileinput.is_open()) {
        std::cout << "_fileinput is not opened\n";
    }
    _fileoutput.open("result.txt");
    if (!_fileoutput.is_open()) {
        std::cout << "_fileoutput is not opened\n";
    }
    std::cout << "---------------------------------------------------------------------------------\n";
    _fileoutput << "---------------------------------------------------------------------------------\n";
    while (_fileinput >> _temp) {
        _set.insert(_temp);
        _unordered_set.insert(_temp);
        std::cout << _temp << std::endl;
        _fileoutput << _temp << std::endl;
    }
    std::cout << "---------------------------------------------------------------------------------\n";
    _fileoutput << "---------------------------------------------------------------------------------\n";
    for (const auto& u : _set) {
        std::cout << u << std::endl;
        _fileoutput << u << std::endl;
    }
    std::cout << _unordered_set.size() << std::endl;
    std::cout << "---------------------------------------------------------------------------------\n";
    _fileoutput << "---------------------------------------------------------------------------------\n";
    for (const auto& u : _unordered_set) {
        std::cout << u << std::endl;
        _fileoutput << u << std::endl;
    }
    std::cout << "---------------------------------------------------------------------------------\n";
    _fileoutput << "---------------------------------------------------------------------------------\n";
}
#include "../include/flat_map.h"

#include <iostream>
#include <string>

int main() 
{
    __gnu::cxx2a::flat_map<int, std::string> map(
        [](std::pair<int, std::string> a, std::pair<int, std::string> b) -> bool 
        {
            return a.first < b.first;
        });

    map.try_insert(2, "Hello, ");
    map.try_insert(1, "World!");

    std::cout << map.try_key(2).value() << map.try_key(1).value() << std::endl;
}
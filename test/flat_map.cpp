#include "flat_map.h"

#include <iostream>
#include <string>

int main() 
{
    __gnu::cxx2a::flat_map<int, std::string> map1(
        [](std::pair<int, std::string> a, std::pair<int, std::string> b) -> bool 
        {
            /// Ascending order
            return a.first < b.first;
        });
    
    __gnu::cxx2a::flat_map<int, std::string> map2(
        [](std::pair<int, std::string> a, std::pair<int, std::string> b) -> bool 
        {
            /// Descending order
            return a.first < b.first;
        });

    map1.try_insert(2, "Hello, ");
    map1.try_insert(1, "World!");
    map2.try_insert(1, "Hello, ");
    map2.try_insert(2, "World!");
    
    if ((map1.get(2).value() + map1.get(1).value()) == "Hello, World!")
        std::cout << "[+] Test 1 Passing" << std::endl;
    else
        std::cout << "[-] Test 1 Failed" << std::endl;

    if ((map1.get(1).value() + map1.get(2).value()) == "World!Hello, ")
        std::cout << "[+] Test 2 Passing" << std::endl;
    else
        std::cout << "[-] Test 2 Failed" << std::endl;

    if ((map2.get(1).value() + map2.get(2).value()) == "Hello, World!")
        std::cout << "[+] Test 3 Passing" << std::endl;
    else
        std::cout << "[-] Test 3 Failed" << std::endl;

    if ((map2.get(2).value() + map1.get(2).value()) == "World!Hello, ")
        std::cout << "[+] Test 4 Passing" << std::endl;
    else
        std::cout << "[-] Test 4 Failed" << std::endl;

    if (!map1.get(1012).has_value())
        std::cout << "[+] Test 5 Passing" << std::endl;
    else
        std::cout << "[-] Test 5 Failed" << std::endl;

    if (!map2.get(72389).has_value())
        std::cout << "[+] Test 6 Passing" << std::endl;
    else
        std::cout << "[-] Test 6 Failed" << std::endl;

    if (map1.get(1).has_value())
        std::cout << "[+] Test 7 Passing" << std::endl;
    else
        std::cout << "[-] Test 7 Failed" << std::endl;

    if (map2.get(2).has_value())
        std::cout << "[+] Test 8 Passing" << std::endl;
    else
        std::cout << "[-] Test 8 Failed" << std::endl;

}
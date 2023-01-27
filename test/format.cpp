#include <iostream>
#include "../include/format.h"


int main() 
{
    if (auto str = __gnu::cxx2a::vformat("%x  ", 12); str == std::string("c  "))
        std::cout << "[+] Test 1 Passing" << std::endl;
    else 
        std::cout << "[-] Test 1 Failed" << std::endl;

    if (auto str = __gnu::cxx2a::vformat("%d", 14882); str == std::string("14882"))
        std::cout << "[+] Test 2 Passing" << std::endl;
    else 
        std::cout << "[-] Test 2 Failed" << std::endl;

    if (auto str = __gnu::cxx2a::vformat("%c", 78); str == std::string("N"))
        std::cout << "[+] Test 3 Passing" << std::endl;
    else 
        std::cout << "[-] Test 3 Failed" << std::endl;

    if (auto str = __gnu::cxx2a::vformat("Hello, %s!", "World"); str == std::string("Hello, World!"))
        std::cout << "[+] Test 4 Passing" << std::endl;
    else 
        std::cout << "[-] Test 4 Failed" << std::endl;

    if (auto str = __gnu::cxx2a::vformat("%s  %X", "()", 0xabc); str == std::string("()  ABC"))
        std::cout << "[+] Test 5 Passing" << std::endl;
    else 
        std::cout << "[-] Test 5 Failed" << std::endl;

    if (auto str = __gnu::cxx2a::vnformat("%s", 7, "This sentence is going to be cut off..."); str == std::string("This s"))
        std::cout << "[+] Test 6 Passing" << std::endl;
    else 
        std::cout << "[-] Test 6 Failed" << std::endl;

    if (auto str = __gnu::cxx2a::vnformat("%c%c%c", 3, 32, 32, 32); str == std::string("  "))
        std::cout << "[+] Test 7 Passing" << std::endl;
    else 
        std::cout << "[-] Test 7 Failed" << std::endl;

    if (auto str = __gnu::cxx2a::vformat("%f", 0.0123); str == std::string("0.012300"))
        std::cout << "[+] Test 8 Passing";
    else 
        std::cout << "[-] Test 8 Failed";
}
#include <iostream>
#include "../src/format.h"


int main() 
{
    if (auto str = __gnu_cxx::v23::vformat("%x  ", 12); str == std::string("c  "))
        std::cout << "[+] Test 1 Passing" << std::endl;
    else 
        std::cout << "[-] Test 1 Failed" << std::endl;

    if (auto str = __gnu_cxx::v23::vformat("%d", 14882); str == std::string("14882"))
        std::cout << "[+] Test 2 Passing" << std::endl;
    else 
        std::cout << "[-] Test 2 Failed" << std::endl;

    if (auto str = __gnu_cxx::v23::vformat("%c", 78); str == std::string("N"))
        std::cout << "[+] Test 3 Passing" << std::endl;
    else 
        std::cout << "[-] Test 3 Failed" << std::endl;

    if (auto str = __gnu_cxx::v23::vformat("Hello, %s!", "World"); str == std::string("Hello, World!"))
        std::cout << "[+] Test 4 Passing" << std::endl;
    else 
        std::cout << "[-] Test 4 Failed" << std::endl;

    if (auto str = __gnu_cxx::v23::vformat("%s  %X", "()", 0xabc); str == std::string("()  ABC"))
        std::cout << "[+] Test 5 Passing" << std::endl;
    else 
        std::cout << "[-] Test 5 Failed" << std::endl;

    if (auto str = __gnu_cxx::v23::vnformat("%s", 7, "This sentence is going to be cut off..."); str == std::string("This s"))
        std::cout << "[+] Test 6 Passing" << std::endl;
    else 
        std::cout << "[-] Test 6 Failed" << std::endl;

    if (auto str = __gnu_cxx::v23::vnformat("%c%c%c", 3, 32, 32, 32); str == std::string("  "))
        std::cout << "[+] Test 7 Passing" << std::endl;
    else 
        std::cout << "[-] Test 7 Failed" << std::endl;

    if (auto str = __gnu_cxx::v23::vformat("%f", 0.0123); str == std::string("0.012300"))
        std::cout << "[+] Test 8 Passing" << std::endl;
    else 
        std::cout << "[-] Test 8 Failed" << std::endl;
}
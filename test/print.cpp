#include "../src/print.h"

int main() 
{
    __gnu_cxx::v2a::println("Hello, World!");
    __gnu_cxx::v2a::vprintln("This is Printing with a FILE*");
    __gnu_cxx::v2a::vprintln("Now we are printing with non-unicode characters...");
    __gnu_cxx::v2a::wprintln(L"Alpha:  Beta: β");
};
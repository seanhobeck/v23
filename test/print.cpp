#include "../src/print.h"

int main() 
{
    __gnu_cxx::v23::println("Hello, World!");
    __gnu_cxx::v23::vprintln_unicode("This is Printing with a FILE*");
    __gnu_cxx::v23::vprintln_unicode("Now we are printing with non-unicode characters...");
    __gnu_cxx::v23::vprintln_nonunicode(L"Alpha:  Beta: β");
};
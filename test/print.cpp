#include "../src/print.h"

int main() 
{
    __gnu::cxx2a::println("Hello, World!");
    __gnu::cxx2a::vprintln("This is Printing with a FILE*");
    __gnu::cxx2a::vprintln("Now we are printing with non-unicode characters...");
};
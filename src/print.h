/**
 * 
 * 
 *      @author  Sean Hobeck
 *       @date 2023-02-07
 * 
 * 
 **/

/// @uses: stdio.h 
#include <iostream>

/// @uses: std::string
#include <string>

/// @uses: std::vformat
#include "format.h"


/// @brief Namespace for the "gnu/linux c++2a standard".
namespace __gnu::cxx2a {
    /// @brief Prints out to stdout, with formatted args.
    /// @tparam ...pargs_t Packed args (same as virtual arguments).
    /// @param __format The string to be formatted to.
    /// @param __args Format parameters to format the string and print to stdout.
    template<typename ... pargs_t>
    static void 
    print(const std::string& __format, pargs_t... __args) noexcept 
    { 
        std::cout << __gnu::cxx2a::vformat(__format, __args...); 
    };
    /// @brief Prints out to a file stream, with formatted args.
    template<typename ... pargs_t>
    static void 
    print(const std::ostream& __fs, const std::string& __format, pargs_t... __args) noexcept 
    { 
        __fs << __gnu::cxx2a::vformat(__format, __args...); 
    };


    /// @brief Prints a line out to stdout, with formatted args.
    /// @tparam ...pargs_t Packed args (same as virtual arguments).
    /// @param __format The string to be formatted to.
    /// @param __args Format parameters to format the string and print a line to stdout.
    template<typename ... pargs_t>
    static void 
    println(const std::string& __format, pargs_t... __args) noexcept 
    { 
        std::cout << __gnu::cxx2a::vformat(__format, __args...) << std::endl; 
    };
    /// @brief Prints a line out to a file stream, with formatted args.
    template<typename ... pargs_t>
    static void 
    println(const std::ostream& __fs, const std::string& __format, pargs_t... __args) noexcept 
    { 
        __fs << __gnu::cxx2a::vformat(__format, __args...) << std::endl;
    };


    /// @brief Writes out to a file pointer, with formatted args (unicode).
    /// @tparam ...pargs_t Packed args (same as virtual arguments).
    /// @param __fp 
    /// @param __format The string to be formatted to.
    /// @param __args Format parameters to format the string and print a line to the file pointer.
    template<typename ... pargs_t>
    static void 
    vprint(FILE* __fp, const std::string& __format, pargs_t... __args) noexcept 
    { 
        if (auto __frmt = __gnu::cxx2a::vformat(__format, __args...); __frmt.length() > 0)
            fwrite(__frmt.c_str(), __frmt.length(), 1ul, __fp);
    };
    /// @brief Writes out to stdout with formatted args (unicode).
    template<typename ... pargs_t>
    static void 
    vprint(const std::string& __format, pargs_t... __args) noexcept 
    { 
        vprint(stdout, __format, __args...);
    };
    
    
    /// @brief Writes out to a file pointer, ending the line, with formatted args (unicode).
    /// @tparam ...pargs_t Packed args (same as virtual arguments).
    /// @param __fp 
    /// @param __format The string to be formatted to.
    /// @param __args Format parameters to format the string and print a line to the file pointer.
    template<typename ... pargs_t>
    static void 
    vprintln(FILE* __fp, const std::string& __format, pargs_t... __args) noexcept 
    { 
        if (auto __frmt = __gnu::cxx2a::vformat(__format, __args...) + '\n'; __frmt.length() > 0)
            fwrite(__frmt.c_str(), __frmt.length(), 1ul, __fp);
    };
    /// @brief Writes out to stdout with formatted args (unicode).
    template<typename ... pargs_t>
    static void 
    vprintln(const std::string& __format, pargs_t... __args) noexcept 
    { 
        vprintln(stdout, __format, __args...);
    };
};
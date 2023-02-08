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

/// @uses: std::string_view
#include <string_view>

/// @uses: std::vformat
#include "format.h"


/// @brief Namespace for the "gnu/linux c++2a standard".
namespace __gnu::cxx2a {
    /// @brief Prints out to stdout, with formatted args.
    /// @tparam ...pargs_t Packed args (same as virtual arguments).
    /// @param __format The string to be formatted to.
    /// @param ...__args Format parameters to format the string and print to stdout.
    template<typename ... pargs_t>
    static void 
    print(const std::string_view& __format, pargs_t... __args) noexcept { std::cout << __gnu::cxx2a::vformat<pargs_t>(__format, __args); };
    /// @brief Prints out to a file stream, with formatted args.
    template<typename ... pargs_t>
    static void 
    print(const std::ostream& __fs, const std::string_view& __format, pargs_t... __args) noexcept { __fs << __gnu::cxx2a::vformat<pargs_t>(__format, __args); };
    /// @brief Prints out to a file descriptor, with formatted args.
    template<typename ... pargs_t>
    static std::filebuf& 
    print(const std::size_t __fd, const std::string_view& __format, pargs_t... __args) noexcept 
    { 
        std::ostream __stream(__fd);
    };

    /// @brief Prints a line out to stdout, with formatted args.
    /// @tparam ...pargs_t Packed args (same as virtual arguments).
    /// @param __format The string to be formatted to.
    /// @param ...__args Format parameters to format the string and print a line to stdout.
    template<typename ... pargs_t>
    static void 
    println(const std::string_view& __format, pargs_t... __args) noexcept { std::cout << __gnu::cxx2a::vformat<pargs_t>(__format, __args) << std::endl; };
    /// @brief Prints a line out to a file stream, with formatted args.
    template<typename ... pargs_t>
    static void 
    println(const std::ostream& __fs, const std::string_view& __format, pargs_t... __args) noexcept { __fs << __gnu::cxx2a::vformat<pargs_t>(__format, __args) << std::endl; };
};
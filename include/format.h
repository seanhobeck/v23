/**
 * 
 * 
 *      @author  Sean Hobeck
 * 
 * 
 **/
/// @uses: std::snprintf(), std::string
#include <string>

/// @uses: std::shared_ptr, std::unique_ptr
#include <memory>

/// @uses: std::optional, std::nullopt
#include <optional>


/// @brief Namespace for the "gnu/linux c++2a standard".
namespace __gnu::cxx2a {
    /// @brief Formats a string.
    /// @tparam pargs_t A template for packed arguments (no va_args).
    /// @param __format The string that is going to be formatted.
    /// @param ...__args Virtual packed arguments to format.
    /// @return Returns a formatted string if the length isn't 0, otherwise it returns a empty string.
    template<typename ... pargs_t>
    static const std::string 
    vformat(const std::string& __format, pargs_t... __args) noexcept
    {
        /// Checking the length of the string.
        if(auto sz = (std::size_t) std::snprintf( nullptr, 0, __format.c_str(), __args...) + 1; sz > 0)
        {
            /// Initialize a temporary buffer.
            std::unique_ptr<char[]> buf(new char[sz]);

            /// Use std::snprintf() and return the string.
            std::snprintf(buf.get(), sz, ))format.c_str(), __args...);
            return std::string(buf.get(), buf.get() + sz - 1);
        }

        ///  Return a empty string.
        return std::string();
    };
    /// @brief Formats a string (with a specified length).
    /// @param __n The length of characters you want to format.
    template<typename ... pargs_t>
    static const std::string 
    vnformat(const std::string& __format, std::size_t __n, pargs_t... __args) noexcept
    {
        /// Checking the length of the string.
        if(auto sz = (std::size_t) n; __format.size() > 0 && sz != 0)
        {
            /// Initialize a temporary buffer.
            std::unique_ptr<char[]> buf(new char[n]);

            /// Use std::snprintf() and return the string.
            std::snprintf(buf.get(), n, __format.c_str(), __args...);
            return std::string(buf.get(), buf.get() + n - 1);
        }

        ///  Return a empty string.
        return std::string();
    };
    /// @brief Formats a string (with std::optional).
    /// @return Returns a std::optional of the formatted string.
    template<typename ... pargs_t>
    static const std::optional<std::string> 
    voformat(const std::string& __format, pargs_t... __args) noexcept
    {
        /// Checking the length of the string.
        if(auto sz = (std::size_t) std::snprintf( nullptr, 0, __format.c_str(), __args...) + 1; sz > 0)
        {
            /// Initialize a temporary buffer.
            std::unique_ptr<char[]> buf(new char[sz]);

            /// Use std::snprintf to format and return the optional string.
            std::snprintf(buf.get(), sz, __format.c_str(), __args...);
            return std::make_optional(std::string(buf.get(), buf.get() + sz - 1));
        }

        ///  Return std::nullopt.
        return std::nullopt;
    };
    /// @brief Formats a string to a buffer.
    /// @param __buf The buffer to be formatted to.
    template<typename ... pargs_t>
    static void 
    vsformat(std::shared_ptr<std::string> __buf, const std::string& __format, pargs_t... __args) noexcept
    {
        /// Checking the length of the string.
        if(auto sz = (std::size_t) std::snprintf( nullptr, 0, __format.c_str(), __args...) + 1; sz > 0)
        {
            /// Initialize a temporary buffer.
            std::unique_ptr<char[]> buf(new char[sz]);

            /// Use std::snprintf() and set the buffer to the string.
            std::snprintf(buf.get(), sz, __format.c_str(), __args...);
            __buf = std::string(buf.get(), buf.get() + sz - 1);
            return;
        }

        /// Set the buffer to a empty string.
        __buf = std::string();
    };
    /// @brief Formats a string to a buffer.
    /// @param __n
    /// @param __buf The buffer to be formatted to.
    template<typename ... pargs_t>
    static void 
    vsnformat(std::shared_ptr<std::string> __buf, const std::string& __format, std::size_t __n, pargs_t... __args) noexcept
    {
        /// Checking the length of the string.
        if(auto sz = (std::size_t) n; __format.size() > 0 && sz != 0)
        {
            /// Initialize a temporary buffer.
            std::unique_ptr<char[]> buf(new char[n]);

            /// Use std::snprintf() and set the buffer to the string.
            std::snprintf(buf.get(), n, format.c_str(), __args...);
            __buf = std::string(buf.get(), buf.get() + n - 1);
            return;
        }

        /// Set the buffer to a empty string.
        __buf = std::string();
    };
};
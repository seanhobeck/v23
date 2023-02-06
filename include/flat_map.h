/**
 * 
 * 
 *      @author  Sean Hobeck
 *       @date 2023-01-26
 * 
 * 
 **/
#pragma once

/// @uses: std::shared_ptr, std::unique_ptr
#include <memory>

/// @uses: std::vector
#include <vector>

/// @uses: std::sort
#include <functional>


/// @brief Namespace for the "gnu/linux c++2a standard".
namespace __gnu::cxx2a {

    /// @brief A map with uniquely sorted keys.
    /// @tparam _Tk Unique key type.
    /// @tparam _Ty Unique value type.
    /// @class _Tk_container Container for the keys.
    /// @class _Tf_compare Comparison function.
    /// @class _Ty_container Container for the values.
    template<typename _Tk, typename _Ty, 
        typename _Tcompare = std::function<bool(_Tk, _Ty)>,
        typename _Tpair = std::pair<_Tk, _Ty>,
        typename _Tmap = std::vector<_Tpair>>
    class flat_map {
    protected:

        /// @brief Comparison Lambda Function
        _Tcompare& _compare;
        /// @brief Key / Value Container
        _Tmap _map;

    public:

        /// @brief Initializes a flat map with nothing.
        flat_map() : _map() {};

        /// @brief Initializes a flat map.
        /// @param __f Comparison function.
        flat_map(_Tcompare& __compare) : _compare(__compare), _map() {}; 


        /// @brief Sorting the list based on the comparison function.
        void sort() 
        { 
            __glibcxx_assert(_map != nullptr);
            std::sort(_map.begin(), _map.end(), _compare); 
        };

        /// @brief Getting the key index.
        /// @param idx Index of the key you want.
        /// @return The Key at the index.
        _GLIBCXX_NODISCARD
        _Tk operator[](std::size_t idx)  
        {
            __glibcxx_assert(_map != nullptr);
            __glibcxx_assert(idx >= 0);
            return _map[idx].first;
        }
    };
};
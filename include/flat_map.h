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
    /// @brief Compare function for flat maps / sets.
    /// @tparam _Tk Unique key value for comparison.
    template<typename _Tk> bool(*_Tk_compare)(_Tk _u, _Tk _v);

    /// @brief A map with uniquely sorted keys.
    /// @tparam _Tk Unique key type.
    /// @tparam _Ty Unique value type.
    /// @class _Tk_container Container for the keys.
    /// @class _Ty_container Container for the values.
    template<typename _Tk, typename _Ty,
        class _Tk_container = std::vector<_Tk>,
        class _Ty_container = std::vector<_Ty>>
    class flat_map {
    protected:
        _Tk_compare& f;
        _Tk_container _k;
        _Ty_container _y;

    public:
        /// @brief Initializes a flat map with nothing.
        flat_map() = default;

        /// @brief Initializes a flat map.
        /// @param __f Comparison function.
        flat_map(_Tk_compare& __f) : f(__f), _k(), _y() {};
 
        
    };
};
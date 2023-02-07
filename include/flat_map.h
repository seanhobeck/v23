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

/// @uses: std::optional
#include <optional>

/// @uses: std::sort
#include <functional>


/// @brief Namespace for the "gnu/linux c++2a standard".
namespace __gnu::cxx2a {

    /// @brief A map with uniquely sorted keys.
    /// @tparam _Tk Unique key type.
    /// @tparam _Ty Unique value type.
    /// @class _Tmap Container for the key/value pairs.
    /// @class _Tpair Pair .
    template<typename _Tk, typename _Ty, 
        typename _Tpair = std::pair<_Tk, _Ty>,
        typename _Tmap = std::vector<_Tpair>>
    class flat_map {
    public:

        /// @type: _Tf_compare Comparison function.
        typedef bool(*_Tcompare)(_Tpair a, _Tpair b);
        /// @type: Optional Key
        typedef std::optional<_Tk> _ToptK;
        /// @type: Optional Value
        typedef std::optional<_Ty> _ToptY;

    protected:

        /// @brief Comparison Lambda Function
        _Tcompare _compare;
        /// @brief Key / Value Container
        _Tmap _map;

    public:

        /// @brief Initializes a flat map with nothing.
        flat_map() : _map() {};

        /// @brief Initializes a flat map.
        /// @param __f Comparison function.
        flat_map(_Tcompare __compare) : _compare(__compare), _map() {}; 


        ///------------------ @section Map Functions ----------------///



        /// @brief Sorting the list based on the comparison function.
        void sort() 
        {
            std::sort(_map.begin(), _map.end(), _compare); 
        };

        /// @brief Trying to push in a key/value pair.
        void try_insert(_Tk key, _Ty value) 
        {
            /// Pushing back the value
            _map.push_back(std::make_pair(key, value));

            /// Auto-sorting
            sort();
        };

        /// @brief Find the value from the specified key pair, if it exists.
        /// @return The value at the specifed key value, if it exists. 
        _ToptY try_key(_Tk key) 
        {
            for (auto p : _map)
                if (p.first == key)
                    return std::make_optional<_Ty>(p.second);

            return std::nullopt;
        };



        ///-------------------- @section Operators -----------------///



        /// @brief Getting the key index.
        /// @param idx Index of the key you want.
        /// @return The Key at the index.
        _GLIBCXX_NODISCARD
        _Tk operator[](std::size_t idx)  
        {
            __glibcxx_assert(idx >= 0);
            return _map[idx].first;
        }
    };
};
/**
 * 
 * 
 *      @author  Sean Hobeck
 *       @date 2023-02-13
 * 
 * 
 **/

/// @uses: std::int64_t, std::map, std::vector
#include <bits/stdc++.h>


/// @brief Namespace for the "gnu/linux c++2a standard".
namespace __gnu_cxx::v2a {

    /// @brief Flat map container.
    /// @tparam k Key typename.
    /// @tparam v Value typename.
    /// @tparam k_map Key map typename.
    /// @tparam v_container Value vector typename.
    /// @tparam kv_it Key-value iterator.
    /// @tparam kv_cit Key-value const iterator.
    template <typename k, typename v,
        typename k_map = std::map<k, std::int64_t>,
        typename v_container = std::vector<v>,
        typename kv_it = v_container::iterator,
        typename kv_cit = v_container::const_iterator>
    class flat_map {
    private:

        /// Key-index map.
        k_map _map;
        /// Values container.
        v_container _vec;

    public:

        flat_map() = default;


        ///------------- @section Member functions. -------------///


        /// @brief Inserting a key and value pair into the map.
        /// @param _k Key
        /// @param _v Value
        void insert(const k& _k, const v& _v) {
            auto it = _map.find(_k); 

            if (it == _map.end()) {
                _map.emplace(_k, _vec.size());
                _vec.emplace_back(_v);
            }
            else
                _vec[it->second] = _v;
        };

        /// @brief Checking if the container contains a key.
        /// @param _k The key.
        /// @return If the flat map contains the key.
        bool contains(const k& _k) const {
            return _map.count(_k) > 0;
        };

        /// @brief Get the size of the flat map container.
        /// @return The size of the flat map container.
        std::size_t size() const {
            return _map.size();
        };


        ///------------- @section Container functions. -------------///


        /// @brief Get the begin iterator of the flat map container.
        /// @return The begin iterator.
        kv_it begin() const {
            return _vec.begin();
        };

        /// @brief Get the end iterator of the flat map container.
        /// @return The ending iterator.
        kv_it end() const {
            return _vec.end();
        };
        
        /// @brief Get the begin iterator of the flat map container.
        /// @return The begin iterator.
        kv_cit cbegin() const {
            return _vec.cbegin();
        };

        /// @brief Get the end iterator of the flat map container.
        /// @return The ending iterator.
        kv_cit cend() const {
            return _vec.cend();
        };


        ///------------- @section Operator functions. -------------///


        const v& operator[](const k& _k) const {
            return _vec[_map.at(_k)];
        };

        v& operator[](const k& _k) const {
            return _vec[_map.at(_k)];
        };
    };
};
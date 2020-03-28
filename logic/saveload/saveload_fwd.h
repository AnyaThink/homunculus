#pragma once
#include <memory>

template<typename Self, typename... Args>
class object;
class object_base;

namespace saveload
{
class node_t;
template<typename DataT>
void add (node_t &node, DataT &data, const std::string &name);

namespace detail
{
class container_node_t_base;
template<typename DataT, typename ElemT>
class container_node_t;
template<typename T>
class can_build_saveload_tree;
template<typename Data>
class primitive_node_t;
template<typename ElemT, typename ContainerT>
void add_elem (ContainerT &data, std::unique_ptr<ElemT> elem_to_add);
}  // namespace detail
}  // namespace saveload

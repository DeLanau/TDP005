#pragma once

#include <unordered_map>
#include <string>
#include <memory>
/**
 * @brief Resource Manager to load files with T type
 * 
 * @tparam T 
 */
template<typename T>
class Resource_Manager
{
public:
    /**
     * @brief load file by string path
     * 
     * @param file 
     * @return T& 
     */
    static T &load(std::string const &file);
private:
    static std::unordered_map<std::string, std::shared_ptr<T>> file_list;
};

template<typename T>
std::unordered_map<std::string, std::shared_ptr<T>> Resource_Manager<T>::file_list;

#include "resource_manager.tcc"

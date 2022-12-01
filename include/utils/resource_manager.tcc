#pragma once 

#include "resource_manager.h"

template<typename T>
T &Resource_Manager<T>::load(std::string const &file)
{
    auto it = file_list.find(file);
    if (it == file_list.end())
    {   
        auto t = std::make_shared<T>();
        t->loadFromFile(file);
        file_list.emplace(std::make_pair(file, t));
        return *t;
    }
    else
        return *it->second;
}


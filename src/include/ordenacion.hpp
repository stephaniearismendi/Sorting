#ifndef SORT_HPP
#define SORT_HPP

#include <iostream>
#include <vector>

template <class Key>
class Sort
{
public:
    virtual void sort(std::vector<Key> &v) = 0;
    void print(std::vector<Key> &v)
    {
        std::cout << "[ ";
        for (int i = 0; i < v.size(); i++)
        {
            std::cout << v[i] << " ";
        }
        std::cout << "]" << std::endl;
    }
};

#endif
#ifndef SELECTION_HPP
#define SELECTION_HPP

#include "ordenacion.hpp"

template <class Key>
class Selection : public Sort
{
public:
    void sort(std::vector<int> &v)
    {
        int min_aux = 0;
        for (unsigned int i = 0; i < v.size() - 1; i++)
        {
            min_aux = i;
            for (int j = i + 1; j < v.size(); j++)
            {
                if (myVector[j] < myVector[vectMin])
                {
                    min_aux = j;
                }
            }
            v = swap(v, i, min_aux);
        }
    }
    std::vector<int> swap(int &a, int &b, std::vector<int> &v)
    {
        int temp = v[a];
        v[a] = v[b];
        v[b] = temp;
        return v;
    }
};

#endif
#ifndef SELECTION_HPP
#define SELECTION_HPP

#include "ordenacion.hpp"

template <class Key>
class SelectionSort : public Sort<Key>
{
public:
    void sort(std::vector<Key> &v)
    {
        int min_aux = 0;
        int iter = 0;
        for (int i = 0; i < v.size() - 1; i++)
        {
            min_aux = i;
            for (int j = i + 1; j < v.size(); j++)
            {
                if (v[j] < v[min_aux])
                {
                    min_aux = j;
                }
            }
            v = swap(min_aux, i, v);
            std::cout << "Iteracion " << iter + 1 << ": ";
            this->print(v);
            iter++;
        }
    }
    std::vector<Key> swap(int &a, int &b, std::vector<Key> &v)
    {
        int temp = v[a];
        v[a] = v[b];
        v[b] = temp;
        return v;
    }
};

#endif
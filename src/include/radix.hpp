#ifndef RADIX_HPP
#define RADIX_HPP

#include "ordenacion.hpp"

template <class Key>
class RadixSort : public Sort<Key>
{
public:
    void sort(std::vector<Key> &v)
    {
        int max = v[0];
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] > max)
            {
                max = v[i];
            }
            std::cout << "Iteracion " << iter + 1 << ": ";
            this->print(v);
            iter++;
        }
        for (int exp = 1; max / exp > 0; exp *= 10)
        {
            v = countSort(v, exp);
            std::cout << "Iteracion " << iter + 1 << ": ";
            this->print(v);
            iter++;
        }
    }
    std::vector<Key> countSort(std::vector<int> &v, int exp)
    {
        std::vector<Key> aux(v.size());
        int count[10] = {0};
        for (int i = 0; i < v.size(); i++)
        {
            count[(v[i] / exp) % 10]++;
        }
        for (int i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }
        for (int i = v.size() - 1; i >= 0; i--)
        {
            aux[count[(v[i] / exp) % 10] - 1] = v[i];
            count[(v[i] / exp) % 10]--;
        }
        v = aux;
        return v;
    }

private:
    int iter = 0;
};

#endif
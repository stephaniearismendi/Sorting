#ifndef QUICK_HPP
#define QUICK_HPP

#include "ordenacion.hpp"

template <class Key>
class QuickSort : public Sort<Key>
{
public:
    void sort(std::vector<Key> &v)
    {
        quick_sort(v, 0, v.size() - 1);
    }
    void quick_sort(std::vector<Key> &v, int left, int right)
    {
        std::cout << "Iteracion " << iter + 1 << ": ";
        this->print(v);
        iter++;
        if (left < right)
        {
            int pivot = partition(v, left, right);
            quick_sort(v, left, pivot - 1);
            quick_sort(v, pivot + 1, right);
        }
    }
    int partition(std::vector<Key> &v, int left, int right)
    {
        int pivot = v[right];
        int i = left - 1;
        for (int j = left; j < right; j++)
        {
            if (v[j] <= pivot)
            {
                i++;
                v = swap(i, j, v);
            }
        }
        v = swap(i + 1, right, v);
        return i + 1;
    }
    std::vector<Key> swap(int a, int b, std::vector<Key> &v)
    {
        int temp = v[a];
        v[a] = v[b];
        v[b] = temp;
        return v;
    }

private:
    int iter = 0;
};

#endif
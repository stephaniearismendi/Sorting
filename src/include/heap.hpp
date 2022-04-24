#ifndef HEAP_HPP
#define HEAP_HPP

#include "ordenacion.hpp"

template <class Key>
class HeapSort : public Sort<Key>
{
public:
    void sort(std::vector<Key> &v)
    {
        int iter = 0;
        for (int i = v.size() / 2 - 1; i >= 0; i--)
        {
            heapify(v, v.size(), i);
            std::cout << "Iteracion " << iter + 1 << ": ";
            iter++;
            this->print(v);
        }
        for (int i = v.size() - 1; i >= 0; i--)
        {
            v = swap(0, i, v);
            heapify(v, i, 0);
            std::cout << "Iteracion " << iter + 1 << ": ";
            iter++;
            this->print(v);
        }
    }
    void heapify(std::vector<Key> &v, int n, int i)
    {
        int largest = i;   // root is the largest element
        int l = 2 * i + 1; // left = 2*i + 1
        int r = 2 * i + 2; // right = 2*i + 2
        // if left child is larger than root
        if (l < n && v[l] > v[largest])
        {
            largest = l;
        }
        // if right child is larger than largest
        if (r < n && v[r] > v[largest])
        {
            largest = r;
        }
        // if largest is not root
        if (largest != i)
        {
            v = swap(i, largest, v);
            heapify(v, n, largest);
        }
    }
    std::vector<Key> swap(int a, int b, std::vector<Key> &v)
    {
        Key temp = v[a];
        v[a] = v[b];
        v[b] = temp;
        return v;
    }
};

#endif
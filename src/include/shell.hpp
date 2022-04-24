#ifndef SHELL_HPP
#define SHELL_HPP

#include "ordenacion.hpp"

template <class Key>
class ShellSort : public Sort<Key>
{
public:
    void sort(std::vector<Key> &v)
    {
        float h = askConstant();
        while (h < v.size() / 3)
        {
            h = 3 * h + 1;
        }
        while (h >= 1)
        {
            for (int i = h; i < v.size(); i++)
            {
                for (int j = i; j >= h && v[j] < v[j - h]; j -= h)
                {
                    v = swap(j, j - h, v);
                    std::cout << "Iteracion " << iter + 1 << ": ";
                    this->print(v);
                    iter++;
                }
            }
            h = h / 3;
        }
    }
    std::vector<Key> swap(int a, int b, std::vector<Key> &v)
    {
        int temp = v[a];
        v[a] = v[b];
        v[b] = temp;
        return v;
    }
    float askConstant()
    {
        bool ok = false;
        float alpha_const = 0;
        while (!ok)
        {
            std::cout << "Introduce alpha value [0,1]: ";
            std::cin >> alpha_const;
            std::cout << std::endl;
            if (alpha_const >= 0 && alpha_const <= 1)
            {
                ok = true;
            }
            else
            {
                std::cout << "Alpha value must be between 0 and 1" << std::endl;
            }
        }
        return alpha_const;
    }

private:
    int iter = 0;
};

#endif
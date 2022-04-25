#ifndef SHELL_HPP
#define SHELL_HPP

#include "ordenacion.hpp"

template <class Key>
class ShellSort : public Sort<Key>
{
public:
    void sort(std::vector<Key> &v)
    {
        float h = askConstant() * v.size();
        while(h > 1){
            h = h / 2;
            deltaSort(v, h);
            std::cout << "iteracion " << iter + 1 << ": ";
            this->print(v);
            iter++;
        }
    }

    std::vector<Key> swap(int a, int b, std::vector<Key> &v)
    {
        int temp = v[a];
        v[a] = v[b];
        v[b] = temp;
        return v;
    }

    void deltaSort(std::vector<Key> &v, float h)
    {
        bool aux = false;;
        Key x;
        int j = 0;
        for(int i = h; i < v.size(); i++)
        {
            aux = false;
            x = v[i];
            j = i;  
            while(j >= h && v[j - h] > x)
            {
                v[j] = v[j - h];
                j -= h;
                aux = true;
            }
            if(aux)
            {
                v[j] = x;
            }
        }
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
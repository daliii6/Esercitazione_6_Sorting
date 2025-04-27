#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace SortLibrary {

template<typename T>
concept Sortable = requires(T& t) {
    { t < t } -> std::convertible_to<bool>;
};


template<Sortable T>
void BubbleSort(std::vector<T>& v)
{
    const unsigned int n = v.size();
    for (unsigned int i = 0; i < n - 1; i++)
    {
        for (unsigned int j = i+1; j < n ; j++)
        {
            if(v[j] < v[i])
            {
                //swap:
                const T tmp = v[i];
                v[i]=v[j];
                v[j]=tmp;
            } 
        }
    }
}


template<Sortable T>
void VectoHeap(vector<T>& v, int n, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && v[left] > v[largest])
        largest = left;

    if (right < n && v[right] > v[largest])
        largest = right;

    if (largest != i)
    {
        //swap
        const T tmp = v[i];
		v[i] = v[largest];
		v[largest] = tmp;
        VectoHeap(v, n, largest);
    }
}

template<Sortable T>
void HeapSort(std::vector<T>& v)
{
    const unsigned int n = v.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        VectoHeap(v, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        const T tmp = v[i];
		v[i] = v[0];
		v[0] = tmp;
        VectoHeap(v, i, 0);
    }
}

}

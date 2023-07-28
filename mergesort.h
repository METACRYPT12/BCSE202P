#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include <vector>

using namespace std;

template <class vector>
void merge(vector data, vector aux, int lo, int mid, int hi)
{
    for (int k = lo; k <= hi; k++)
    {
        aux.push_back(data[k]);
    }
    int i = lo, j = mid + 1;
    for (int k = lo; k <= hi; k++)
    {
        if (i > mid)
            data[k] = aux[j++];
        else if (j > hi)
            data[k] = aux[i++];
        else if (aux[j].weight < aux[i].weight)
            data[k] = aux[j++];
        else
            data[k] = aux[i++];
    }
    return;
}

template <class vector>
void msort(vector data, vector aux, int lo, int hi)
{
    if (hi <= lo)
        return;
    int mid = lo + (hi - lo) / 2;
    msort(data, aux, lo, mid);
    msort(data, aux, mid + 1, hi);
    merge(data, aux, lo, mid, hi);
    return;
}

template <class vector>
vector sort(vector data, int s)
{
    vector aux;
    msort(data, aux, 0, s - 1);
    return data;
}

#endif
#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace SortLibrary {

template<typename T>
concept Sortable = requires(T& t) {
    {t < t} -> std::convertible_to<bool>;
};

template<Sortable T>

void BubbleSort(vector<T>& v) {
    int n = v.size();

    for (int i = 0; i < n - 1; i++) {

        for (int j = i+1; j < n - 1; j++) {

            if (v[j] < v[i])

                swap(v[j], v[i]);
        }
    }
}

template<Sortable T>
void heapify(vector<T>& v, int n, int i)
{
	while(true) {
	int largest = i; 
	int l = 2 * i + 1; 
	int r = 2 * i + 2; 

	
	if (l < n && v[l] > v[largest])
		largest = l;

	
	if (r < n && v[r] > v[largest])
		largest = r;

	
	if (largest == i) 
		break
	
	swap(v[i],v[largest]);
	i=largest
	}
}

template<Sortable T>
void HeapSort(vector<T>& v)
{
	int n = v.size();
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(v, n, i);
	for (int i = n - 1; i >= 0; i--) {
		swap(v[0], v[i]);
		heapify(v, i, 0);
	}
	for (int j = 0; j<n; j++){
		reverse(v.begin(), v.end());

		}
}



}




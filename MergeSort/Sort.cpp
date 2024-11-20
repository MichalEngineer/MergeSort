#include "sort.h"

void MergeSort::Sort(std::vector<int>& tab) {
    if (tab.size() <= 1) return; 
    Divide(tab, 0, tab.size() - 1); 
}

void MergeSort::Divide(std::vector<int>& tab, int l, int r) {
    if (l >= r) return; 

    int mid = l + (r - l) / 2; 
    Divide(tab, l, mid);       
    Divide(tab, mid + 1, r);   
    Merge(tab, l, mid, r);     
}

void MergeSort::Merge(std::vector<int>& tab, int l, int mid, int r) {
    std::vector<int> left(tab.begin() + l, tab.begin() + mid + 1);
    std::vector<int> right(tab.begin() + mid + 1, tab.begin() + r + 1);

    int i = 0, j = 0, k = l;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            tab[k++] = left[i++];
        }
        else {
            tab[k++] = right[j++];
        }
    }

    while (i < left.size()) {
        tab[k++] = left[i++];
    }

    while (j < right.size()) {
        tab[k++] = right[j++];
    }
}

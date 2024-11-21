#include "sort.h"

void MergeSort::Sort(std::vector<int>& tab) {
    if (tab.size() <= 1) return; // <-- Jeœli tablica ma jeden lub mniej elementów, nie ma potrzeby sortowaæ
    Divide(tab, 0, tab.size() - 1); // <-- Rozpoczynamy dzielenie tablicy od indeksu 0 do ostatniego elementu
}

void MergeSort::Divide(std::vector<int>& tab, int l, int r) { // <-- Funkcja jest odpowiedzialana za dzielenie tablicy na mniejsze podtablice
    if (l >= r) return; // <-- Jeœli lewy indeks jest wiêkszy lub równy prawemu, oznacza to, ¿e nie ma ju¿ co dzieliæ (tablica ma tylko jeden element)

    int mid = l + (r - l) / 2; // <-- Obliczamy indeks œrodkowy
    Divide(tab, l, mid);       // <-- Rekurencyjnie dzielimy lew¹ czêœæ tablicy
    Divide(tab, mid + 1, r);   // <-- Rekurencyjnie dzielimy praw¹ czêœæ tablicy
    Merge(tab, l, mid, r);     // <-- Scalanie obu posortowanych czêœci tablicy
}

void MergeSort::Merge(std::vector<int>& tab, int l, int mid, int r) {
    std::vector<int> left(tab.begin() + l, tab.begin() + mid + 1); // <-- Tworzenie tablicy która zawiera elementy lewa do œrodka 
    std::vector<int> right(tab.begin() + mid + 1, tab.begin() + r + 1);// <-- Tworzenie tablicy która zawiera elementy œrodka do koñca 

    int i = 0; // <-- indeks dla lewej podtablicy
    int j = 0; // <-- indeks dla lewej prawej
    int k = l; // <-- indeks dla lewej g³ównej

    while (i < left.size() && j < right.size()) {// <-- Scalanie obu podtablic to tablicy g³ównej dopóki s¹ elementy w obu podtablicach
        if (left[i] <= right[j]) {// <-- Jeœli element w lewej podtablicy jest mniejszy lub równy elementowi w prawej
            tab[k++] = left[i++];// <-- Wstawiamy element z lewej podtablicy do g³ównej tablicy
        }
        else {
            tab[k++] = right[j++]; // <-- Wstawiamy element z prawej podtablicy do g³ównej tablicy
        }
    }

    while (i < left.size()) {// <-- Je¿eli pozosta³y elementy w lewej podtablicy, wstawiamy je do g³ównej tablicy
        tab[k++] = left[i++]; // <-- Przenosimy pozosta³e elementy z lewej podtablicy
    }

    while (j < right.size()) {// <-- Jeœli pozosta³y elementy w prawej podtablicy, wstawiamy je do g³ównej tablicy
        tab[k++] = right[j++]; // <-- Przenosimy pozosta³e elementy z prawej podtablicy
    }
}

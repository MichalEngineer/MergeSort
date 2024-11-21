#include "sort.h"

void MergeSort::Sort(std::vector<int>& tab) {
    if (tab.size() <= 1) return; // <-- Je�li tablica ma jeden lub mniej element�w, nie ma potrzeby sortowa�
    Divide(tab, 0, tab.size() - 1); // <-- Rozpoczynamy dzielenie tablicy od indeksu 0 do ostatniego elementu
}

void MergeSort::Divide(std::vector<int>& tab, int l, int r) { // <-- Funkcja jest odpowiedzialana za dzielenie tablicy na mniejsze podtablice
    if (l >= r) return; // <-- Je�li lewy indeks jest wi�kszy lub r�wny prawemu, oznacza to, �e nie ma ju� co dzieli� (tablica ma tylko jeden element)

    int mid = l + (r - l) / 2; // <-- Obliczamy indeks �rodkowy
    Divide(tab, l, mid);       // <-- Rekurencyjnie dzielimy lew� cz�� tablicy
    Divide(tab, mid + 1, r);   // <-- Rekurencyjnie dzielimy praw� cz�� tablicy
    Merge(tab, l, mid, r);     // <-- Scalanie obu posortowanych cz�ci tablicy
}

void MergeSort::Merge(std::vector<int>& tab, int l, int mid, int r) {
    std::vector<int> left(tab.begin() + l, tab.begin() + mid + 1); // <-- Tworzenie tablicy kt�ra zawiera elementy lewa do �rodka 
    std::vector<int> right(tab.begin() + mid + 1, tab.begin() + r + 1);// <-- Tworzenie tablicy kt�ra zawiera elementy �rodka do ko�ca 

    int i = 0; // <-- indeks dla lewej podtablicy
    int j = 0; // <-- indeks dla lewej prawej
    int k = l; // <-- indeks dla lewej g��wnej

    while (i < left.size() && j < right.size()) {// <-- Scalanie obu podtablic to tablicy g��wnej dop�ki s� elementy w obu podtablicach
        if (left[i] <= right[j]) {// <-- Je�li element w lewej podtablicy jest mniejszy lub r�wny elementowi w prawej
            tab[k++] = left[i++];// <-- Wstawiamy element z lewej podtablicy do g��wnej tablicy
        }
        else {
            tab[k++] = right[j++]; // <-- Wstawiamy element z prawej podtablicy do g��wnej tablicy
        }
    }

    while (i < left.size()) {// <-- Je�eli pozosta�y elementy w lewej podtablicy, wstawiamy je do g��wnej tablicy
        tab[k++] = left[i++]; // <-- Przenosimy pozosta�e elementy z lewej podtablicy
    }

    while (j < right.size()) {// <-- Je�li pozosta�y elementy w prawej podtablicy, wstawiamy je do g��wnej tablicy
        tab[k++] = right[j++]; // <-- Przenosimy pozosta�e elementy z prawej podtablicy
    }
}

#pragma once
#include <vector>
/**
 * @class MergeSort
 * @brief Klasa implementuj¹ca algorytm MergeSort.
 */
class MergeSort {
public:
    /**
    * @brief Funkcja sortuj¹ca tablicê przy u¿yciu algorytmu MergeSort.
    *
	* Ta funkcja jest wywo³ywana w celu rozpoczêcia procesu sortowania tablicy. U¿ywa algorytmu MergeSort,
	* który dzieli tablicê na mniejsze czêœci i scala je w posortowan¹ ca³oœæ.
	*
	* @param tab Referencja do tablicy, która ma zostaæ posortowana.
	*/
	static void Sort(std::vector<int>& tab);
    /**
	* @brief Funkcja dziel¹ca tablicê na dwie czêœci do dalszego sortowania.
	*
	* Funkcja ta dzieli tablicê na dwie czêœci na podstawie indeksów lewego (l) i prawego (r)
	* granicy. Nastêpnie wywo³uje rekurencyjnie sortowanie dla obu czêœci.
	*
	* @param tab Referencja do tablicy, która ma zostaæ podzielona.
	* @param l Indeks pocz¹tkowy lewej czêœci tablicy.
	* @param r Indeks koñcowy prawej czêœci tablicy.
	*/
	static void Divide(std::vector<int>& tab, int l, int r);
	/**
	* @brief Funkcja scala dwie posortowane czêœci tablicy w jedn¹ posortowan¹ ca³oœæ.
	*
	* Ta funkcja ³¹czy dwie posortowane czêœci tablicy w jeden ci¹g w sposób wydajny,
	* zachowuj¹c porz¹dek rosn¹cy. Operacja scalania jest kluczow¹ czêœci¹ algorytmu MergeSort.
	*
	* @param tab Referencja do tablicy, w której odbywa siê scalanie.
	* @param l Indeks pocz¹tkowy lewej czêœci tablicy.
	* @param mid Indeks œrodkowy, który dzieli tablicê na dwie czêœci.
	* @param r Indeks koñcowy prawej czêœci tablicy.
	*/
	static void Merge(std::vector<int>& tab, int l, int mid, int r);
};
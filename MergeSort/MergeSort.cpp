#include <iostream>
#include "sort.h"

void PrintVector(const std::vector<int>& tab) {
    for (int i = 0; i < tab.size(); ++i) {
        std::cout << tab[i] << " "; 
    }
    std::cout << std::endl;
}
int main()
{
    std::vector<int> test1 = { 38, 27, 43, 3, 9, 82, 10 };      
    std::vector<int> test2 = { 1, 2, 3, 4, 5 };                  


    std::cout << "Test 1 - Przed sortowaniem: ";
    PrintVector(test1);
    MergeSort::Sort(test1);
    std::cout << "Test 1 - Po sortowaniu: ";
    PrintVector(test1);
    std::cout << "Test 2 - Przed sortowaniem: ";
    PrintVector(test2);
    MergeSort::Sort(test2);
    std::cout << "Test 2 - Po sortowaniu: ";
    PrintVector(test2);


}


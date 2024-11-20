#pragma once
#include <vector>
class MergeSort {
public:
	static void Sort(std::vector<int>& tab);
	static void Divide(std::vector<int>& tab, int l, int r);
	static void Merge(std::vector<int>& tab, int l, int mid, int r);
};
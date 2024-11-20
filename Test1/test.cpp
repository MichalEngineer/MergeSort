#include "../MergeSort/Sort.cpp"
#include <gtest/gtest.h>

TEST(Tests, alreadydone) {
    std::vector<int> t = { 1, 2, 3, 4, 5 };
    MergeSort::Sort(t);
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    ASSERT_EQ(t, expected);
}
